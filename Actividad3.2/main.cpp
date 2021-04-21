//
// Created by Diego Ortiz on 3/22/21.
// Created by David Velázquez on 3/22/21.
// Created by Felix De Haro on 3/22/21.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Token.h"
#include "InputLine.h"
#include "StateMachine.h"

using namespace std;

vector<string> readFile() {
    ifstream archivo;
    archivo.open("expresiones.txt", ios::in);
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

void exportFile(Token tokens) {
    fstream CreateFile("DFA.csv", ios::out);
    ofstream fileToken;
    fileToken.open("DFA.csv");
    fileToken << "Token , Type"<<endl;
    for (int i = 0; i < tokens.getSize(); i++) {
        fileToken<<tokens.getTokenString(i) <<  "," << tokens.getTokenType(i) << endl;
    }
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
    exportFile(tokens);
    return 0;
}