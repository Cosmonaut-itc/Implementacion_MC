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
    archivo.open(R"(C:\Users\Felix\Desktop\Tec\4to Semestre\Implementacion\Scheme\Repo\Actividad3.2\expresiones.txt)", ios::in);
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

// Creates an HTML file to show the output
void createFile(Token tokens) {
    fstream CreateFile(R"(C:\Users\Felix\Desktop\Tec\4to Semestre\Implementacion\Scheme\Repo\Actividad3.2\DFA.html)", ios::out);
    ofstream fileToken;
    fileToken.open(R"(C:\Users\Felix\Desktop\Tec\4to Semestre\Implementacion\Scheme\Repo\Actividad3.2\DFA.html)");
    fileToken << "<!DOCTYPE HTML>\n"
                 "<html lang=\"en\">\n"
                 "  <head>\n"
                 "  <meta charset=\"utf-8\">\n"
                 "  <meta name=\"description\" content=\"A page for exploring basic HTML documents\">\n"
                 "  <title>Basic HTML document</title>\n"
                 "  </head>\n"
                 "  <body>\n"<<endl;
    for (int i = 0; i < tokens.getSize(); i++) {
        fileToken<<tokens.getTokenString(i) <<  "," << tokens.getTokenType(i) << endl;
    }
    fileToken <<  "    <h1>Page content</h1>\n"
                  "  </body>\n"
                  "</html>"<<endl;
}

string createHTML(string token, string type){

    return "<html>";
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