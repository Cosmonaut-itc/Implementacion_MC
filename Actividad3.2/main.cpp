#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Token.h"
#include "InputLine.h"

using namespace std;

vector<string> readFile() {
    ifstream archivo;
    archivo.open("archivo.txt", ios::in);
    if (archivo.fail()) {
        cout << "El archivo no se pudo abrir" << endl;
        exit(1);
    }
    string texto;
    vector<string> words;
    string word = "";
    while (!archivo.eof()) {
        getline(archivo, texto);
        texto += '\n';
        words.push_back(texto);
    }
    archivo.close();
    return words;
}

void exportFile(vector<Token> tokens) {
    fstream CreateFile("DFA.csv", ios::out);
    CreateFile << "Token,Tipo" << endl;
    ofstream MyFile;
    MyFile.open("DFA.csv");
    for (int i = 0; i < tokens.size(); i++) {
        //MyFile<<currentToken.getTokenString() <<  "," << currentToken.getTokenType() << endl;
    }
}

int main() {
    vector<Token> tokens;
    vector<string> linesString = readFile();
    vector<InputLine> Lines;
    for (auto const &line: linesString) {
        InputLine currentLine(line);
        Lines.push_back(currentLine);
    }
    return 0;
}