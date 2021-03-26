//
// Created by Diego Ortiz on 3/25/21.
//

#ifndef ACTIVIDAD3_2_STATEMACHINE_H
#define ACTIVIDAD3_2_STATEMACHINE_H

#include <iostream>
#include <map>
#include <vector>
#include "InputLine.h"

using namespace std;
class StateMachine {
private:
    vector<std::map<string, int>> transitionTable;
    vector<string> stateNames;
    int currentState;
public:
    StateMachine();
    int nextState(string input);
    void lexer(vector<InputLine> Lines);
    void resetMachine();
};


#endif //ACTIVIDAD3_2_STATEMACHINE_H
