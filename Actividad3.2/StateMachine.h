//
// Created by Diego Ortiz on 3/22/21.
// Created by David Velázquez on 3/22/21.
// Created by Felix De Haro on 3/22/21.
//
#ifndef ACTIVIDAD3_2_STATEMACHINE_H
#define ACTIVIDAD3_2_STATEMACHINE_H

#include <iostream>
#include <map>
#include <vector>
#include "InputLine.h"
#include "Token.h"

using namespace std;
class StateMachine {
private:
    vector<std::map<string, int>> transitionTable;
    vector<string> stateNames;
    Token tokens;
    int currentState;
    char currentChar;
    string currentCharType;
public:
    StateMachine();
    int nextState(const string& input);
    Token lexer(const vector<InputLine>& Lines);
    void addCurrentToTokens();
};


#endif //ACTIVIDAD3_2_STATEMACHINE_H
