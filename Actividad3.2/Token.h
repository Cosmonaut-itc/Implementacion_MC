//
// Created by Diego Ortiz on 3/22/21.
//

#ifndef IMPLEMENTACION_MC_TOKEN_H
#define IMPLEMENTACION_MC_TOKEN_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using namespace std;

class Token {
private:
    vector<vector<string>> tokenStringType;
    int size = 0;
public:
    Token();
    void addToken(string tokenString, string tokenType);
    string getTokenString(int row);
    string getTokenType(int row);
    int getSize();
    void tokenPrint();
};


#endif //IMPLEMENTACION_MC_TOKEN_H
