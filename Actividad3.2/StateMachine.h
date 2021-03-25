//
// Created by Diego Ortiz on 3/25/21.
//

#ifndef ACTIVIDAD3_2_STATEMACHINE_H
#define ACTIVIDAD3_2_STATEMACHINE_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;
class StateMachine {
private:
    vector<std::map<string, int>> transitionTable;
    int currentState;
public:
    StateMachine();
};


#endif //ACTIVIDAD3_2_STATEMACHINE_H
