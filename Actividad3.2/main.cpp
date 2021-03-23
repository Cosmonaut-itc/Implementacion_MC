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
        int comentario = 0;
        bool isComentario = false;
        for (char s : texto) {
            if (isComentario == false){
                if (s == ' ') {
                    words.push_back(word);
                    word = "";
                    comentario = 0;
                } else {
                    word += s;
                    if (comentario == 1){
                        if (s != '/'){
                            comentario = 0;
                        }
                    }
                }
                if (s == '/'){
                    comentario ++;
                    if (comentario == 2){
                        isComentario = true;
                    }
                    if (word != "//"){
                        string word2 = "";
                        for (int i = 0; i < word.length() - 2; i++){
                            word2 += word[i];
                        }
                        words.push_back(word2);
                        word = "//";
                    }
                }
            } else{
                word += s;
            }
        }
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