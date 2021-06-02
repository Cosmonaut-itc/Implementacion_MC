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
#include "Token.h"
#include "InputLine.h"
#include "StateMachine.h"

using namespace std;

vector<string> readFile() {
    ifstream archivo;
    archivo.open("expresiones.txt", ios::in);
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
string createHTML(const string& token, const string& type){
    std::map<string, string> typeHTML{
            {"Números", "<span style = \"color: #ffe119;\">" + token + "</span>"}, // amarillo
            {"Lógicos", "<span style = \"color: #4363d8;\">" + token + "</span>"}, // azul marino
            {"Símbolos", "<span style = \"color: #469990;\">" + token + "</span>"}, // verde turquesa
            {"Operadores", "<span style = \"color: #911eb4;\">" + token + "</span>"}, // morado fuerte
            {"Identificadores", "<span style = \"color: #3cb44b;\">" + token + "</span>"}, // verde normal
            {"Especiales", "<span style = \"color: #9A6324;\">" + token + "</span>"}, // cafe
            {"Comentarios", "<span style = \"color: #808000;\">" + token + "</span>"}, // amarillo cafesoso
            {"Palabras reservadas", "<span style = \"color: #f032e6;\">" + token + "</span>"}, // morado bajito
            {"Errores", "<span style = \"color: #e6194B;\">" + token + "</span>"}, // rojo
            {"Espacio", " "},
            {"SaltoDeLinea", "<br>"}
    };
    return typeHTML.find(type)->second;
}

// Creates an HTML file to show the output.
void createFile(Token tokens) {
    fstream CreateFile("DFA.HTML", ios::out);
    ofstream fileToken;
    fileToken.open("DFA.HTML");
    fileToken << "<!DOCTYPE HTML>\n"
                 "<html lang=\"en\">\n"
                 "  <head>\n"
                 "  <meta charset=\"utf-8\">\n"
                 "  <meta name=\"description\" content=\"A page for exploring basic HTML documents\">\n"
                 "  <title>Basic HTML document</title>\n"
                 "  </head>\n"
                 "  <body style = \"justify-content: center; text-align: center; align-items: center; font-size: 40px;\">\n"<<endl;
    for (int i = 0; i < tokens.getSize(); i++) {
        fileToken<<createHTML(tokens.getTokenString(i), tokens.getTokenType(i));
    }
    fileToken <<  "</body>\n</html>";
}

int main() {
    vector<string> linesString = readFile();
    vector<InputLine> Lines;
    StateMachine lexerMachine;

    for (auto const &line: linesString) {
        InputLine currentLine(line);
        Lines.push_back(currentLine);
    }
    Token tokens = lexerMachine.lexer(Lines);
    tokens.tokenPrint();
    createFile(tokens);
    return 0;
}