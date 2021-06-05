//
// Created by Diego Ortiz on 3/22/21.
// Created by David Velázquez on 3/22/21.
// Created by Felix De Haro on 3/22/21.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <mutex>
#include <thread>
#include "Token.h"
#include "InputLine.h"
#include "StateMachine.h"

using namespace std;

//Path of files buffer
vector<string> filesPath;
mutex filesMutex;
bool fileEmpty = false;


// Token buffer
vector<Token> tokens;
mutex tokensMutex;
condition_variable tokensCv;
int fileNum = 0;

vector<string> readFile(const string &path) {
    ifstream archivo;
    archivo.open(path, ios::in);
    if (archivo.fail()) {
        cout << "El archivo no se pudo abrir" << endl;
        //exit(1);
    }
    string texto;
    vector<string> words;
    string word;
    while (!archivo.eof()) {
        getline(archivo, texto);
        texto += '\n';
        words.push_back(texto);
    }
    archivo.close();
    return words;
}

// Convierte la información del Token a HTML+CSS
string createHTML(const string &token, const string &type) {
    std::map<string, string> typeHTML{
            {"Números",             "<span style = \"color: #ffe119;\">" + token + "</span>"}, // amarillo
            {"Lógicos",             "<span style = \"color: #4363d8;\">" + token + "</span>"}, // azul marino
            {"Símbolos",            "<span style = \"color: #469990;\">" + token + "</span>"}, // verde turquesa
            {"Operadores",          "<span style = \"color: #911eb4;\">" + token + "</span>"}, // morado fuerte
            {"Identificadores",     "<span style = \"color: #3cb44b;\">" + token + "</span>"}, // verde normal
            {"Especiales",          "<span style = \"color: #9A6324;\">" + token + "</span>"}, // cafe
            {"Comentarios",         "<span style = \"color: #808000;\">" + token + "</span>"}, // amarillo cafesoso
            {"Palabras reservadas", "<span style = \"color: #f032e6;\">" + token + "</span>"}, // morado bajito
            {"Errores",             "<span style = \"color: #e6194B;\">" + token + "</span>"}, // rojo
            {"Espacio",             " "},
            {"SaltoDeLinea",        "<br>"}
    };
    return typeHTML.find(type)->second;
}

// Creates an HTML file to show the output.
void createFile(Token tokens, int number) {
    string fileName = "DFA" + to_string(number) + ".HTML";
    fstream CreateFile(fileName, ios::out);
    ofstream fileToken;
    fileToken.open(fileName);
    fileToken << "<!DOCTYPE HTML>\n"
                 "<html lang=\"en\">\n"
                 "  <head>\n"
                 "  <meta charset=\"utf-8\">\n"
                 "  <meta name=\"description\" content=\"A page for exploring basic HTML documents\">\n"
                 "  <title>Basic HTML document</title>\n"
                 "  </head>\n"
                 "  <body style = \"justify-content: center; text-align: center; align-items: center; font-size: 40px;\">\n"
              << endl;
    for (int i = 0; i < tokens.getSize(); i++) {
        fileToken << createHTML(tokens.getTokenString(i), tokens.getTokenType(i));
    }
    fileToken << "</body>\n</html>";
}

void consumeTokens() {
    while (!fileEmpty || !tokens.empty()) {
        Token currentToken;
        {
            std::unique_lock<mutex> tokensUl(tokensMutex);
            tokensCv.wait(tokensUl, [] { return (!tokens.empty()); });
            currentToken = tokens.back();
            tokens.pop_back();
        }
        //token.tokenPrint();
        createFile(currentToken, fileNum);
        fileNum++;
    }
}

void produceTokens() {
    // Read archives buffer
    while (!filesPath.empty()) {
        vector<string> linesString;
        string currentFilePath;
        {
            // Read filesPath vector (protected by mutex)
            std::lock_guard<mutex> filesPathLg(filesMutex);
            currentFilePath = filesPath.back();
            filesPath.pop_back();
        }
        //Consume lines
        linesString = readFile(currentFilePath);
        vector<InputLine> Lines;
        StateMachine lexerMachine;
        Token currentToken;
        for (auto const &line: linesString) {
            InputLine currentLine(line);
            Lines.push_back(currentLine);
        }
        currentToken = lexerMachine.lexer(Lines);
        std::lock_guard<mutex> lg(tokensMutex);
        tokens.emplace_back(currentToken);
        tokensCv.notify_one();
    }
    fileEmpty = true;

}


void createTokens(unsigned int start, unsigned int end) {
    for (int i = start; i < end; i++) {
        // Read archives buffer
        vector<string> linesString = readFile(filesPath[i]);
        //Consume lines
        vector<InputLine> Lines;
        StateMachine lexerMachine;
        for (auto const &line: linesString) {
            InputLine currentLine(line);
            Lines.push_back(currentLine);
        }
        //token.tokenPrint();
        createFile(lexerMachine.lexer(Lines), i);
    }
}

void parallelProcessing(unsigned int numParallelThreads) {
    //Thread vector
    vector<thread> threads;
    //Reserve number of threads
    threads.reserve(numParallelThreads);
    // Calculate amount of iterations per thread
    unsigned int part = filesPath.size() / numParallelThreads;

    for (unsigned int i = 0; i < numParallelThreads - 1; i++) {
        unsigned int inicio = (part * i);
        unsigned int fin = (part * i) + part;
        threads.emplace_back(createTokens, inicio, fin);
    }
    threads.emplace_back(createTokens, (numParallelThreads - 1) * part, filesPath.size());
    for (auto &t : threads) {
        t.join();
    }
}

void producerConsumer(unsigned int numProducerThreads, unsigned int numConsumerThreads) {
    //Thread vector
    vector<thread> threads;
    //Reserve number of threads
    threads.reserve(numProducerThreads + numConsumerThreads);
    for (unsigned int i = 0; i < numProducerThreads; i++) {
        threads.emplace_back(produceTokens);
    }
    for (unsigned int i = 0; i < numConsumerThreads; i++) {
        threads.emplace_back(consumeTokens);
    }
    for (auto &t : threads) {
        t.join();
    }
}

int main() {
    //Read all files inside the directory InputFiles
    vector<string> localFilesPath;
    std::string path = "./InputFiles";
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        localFilesPath.push_back(entry.path());
    }
    // Copy files path to global variable
    filesPath = localFilesPath;
    //Get number of available threads
    const auto processorCount = std::thread::hardware_concurrency();
    // Number of threads
    unsigned int numProducerThreads = processorCount / 2;
    unsigned int numConsumerThreads = processorCount / 2;
    unsigned int numParallelThreads = processorCount;

    // Single threaded
    auto start = chrono::steady_clock::now();
    createTokens(0, filesPath.size());
    auto end = chrono::steady_clock::now();
    cout << "Single threaded elapsed time in milliseconds: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    // Producer consumer
    start = chrono::steady_clock::now();
    producerConsumer(numProducerThreads, numConsumerThreads);
    end = chrono::steady_clock::now();
    cout << "Multithreading Producer-consumer elapsed time in milliseconds: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    // Copy files path to global variable
    filesPath = localFilesPath;
    // Parallel processing
    start = chrono::steady_clock::now();
    parallelProcessing(numParallelThreads);
    end = chrono::steady_clock::now();
    cout << "Parallel Multithreading Elapsed time in milliseconds: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}