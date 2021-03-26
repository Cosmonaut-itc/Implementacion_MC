//
// Created by Diego Ortiz on 3/22/21.
//

#ifndef IMPLEMENTACION_MC_TOKEN_H
#define IMPLEMENTACION_MC_TOKEN_H

#include <string>

using namespace std;

class Token {
private:
    vector<vector<string>> tokenStringType;
public:
    Token();
    void addToken(string, string);
    pair getTokenStringType();
};


#endif //IMPLEMENTACION_MC_TOKEN_H
