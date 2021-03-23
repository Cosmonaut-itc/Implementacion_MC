#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "token.h"

using namespace std;

vector<string> readFile(){
    ifstream archivo;
    archivo.open("archivo.txt", ios::in);
    if (archivo.fail()) {
        cout << "El archivo no se pudo abrir" << endl;
        exit(1);
    }
    string texto;
    vector<string> words;
    string word  = "";
    while (!archivo.eof()) {
        getline(archivo, texto);
        words.push_back(texto);
    }
    archivo.close();
    return words;
}

void exportFile(vector<token> tokens){
    fstream CreateFile("DFA.csv", ios::out);
    CreateFile<<"Token,Tipo"<<endl;
    ofstream MyFile;
    MyFile.open("DFA.csv");
    for (int i = 0; i<tokens.size(); i++){
        //MyFile<<currentToken.getTokenString() <<  "," << currentToken.getTokenType() << endl;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<string> words = readFile();
    vector<token> tokens;
    return 0;
}