//
// Created by Diego Ortiz on 3/22/21.
//

#include <vector>
#include "Token.h"

Token(){
    tokenStringType = [];
}

void addToken(vector<string> tokenstrTp) {
    tokenStringType.pushback(tokenstrTp);
}

vector<vector<string>> getTokenStringType() {
    return tokenStringType;
}