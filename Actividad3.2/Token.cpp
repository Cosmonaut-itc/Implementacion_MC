//
// Created by Diego Ortiz on 3/22/21.
// Created by David Velázquez on 3/22/21.
// Created by Felix De Haro on 3/22/21.
//
#include "Token.h"

Token::Token(){
    this->tokenStringType[0];
    this->size = 0;
}

void Token::addToken(string tokenString, string tokenType) {
    vector<string> tokenStrTp;
    tokenStrTp.push_back(tokenString);
    tokenStrTp.push_back(tokenType);
    this->tokenStringType.push_back(tokenStrTp);
    this->size++;
}

string Token::getTokenString(int row) {
    return this->tokenStringType[row][0];
}

string Token::getTokenType(int row) {
    return this->tokenStringType[row][1];
}

void Token::tokenPrint(){
    for (int i = 0; i < this->size; i++){
        for (int j = 0; j < 2; j++){
            cout << this->tokenStringType[i][j] << ",";
        }
        cout<<endl;
    }
}

int Token::getSize() {
    return this->size;
}