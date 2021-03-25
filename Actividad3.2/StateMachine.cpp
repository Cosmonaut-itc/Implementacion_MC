//
// Created by Diego Ortiz on 3/25/21.
//

#include "StateMachine.h"

StateMachine::StateMachine() {
    this->currentState = 0;
    static const std::map<string, int> q0Table{
            {"Espacio",   0},
            {"División",  1},
            {"Suma", 2},
            {"Multipliación", 2},
            {"Potencia", 2},
            {"Letra", 3},
            {"Paréntesis que abre", 4},
            {"Paréntesis que cierra", 5},
            {"Resta",  7},
            {"Digito",  8}
    };
    static const std::map<string, int> q1Table{
            {"División",  6},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0}
    };
    static const std::map<string, int> q2Table{
            {"Espacio",     0},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0}
    };
    static const std::map<string, int> q3Table{
            {"Espacio",     0},
            {"Letra",  3},
            {"Underscore", 3},
            {"Digito",  3},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0}
    };
    static const std::map<string, int> q4Table{
            {"Espacio",     0},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0},
    };
    static const std::map<string, int> q5Table{
            {"Espacio",     0},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0},
    };
    static const std::map<string, int> q6Table{
            {"Asignación", 6},
            {"Suma", 6},
            {"Resta", 6},
            {"Multipliación", 6},
            {"División", 6},
            {"Potencia", 6},
            {"Espacio", 6},
            {"Punto", 6},
            {"Parentesís que abre", 6},
            {"Paréntesis que cierra", 6},
            {"UnderScore", 6}
    };
    static const std::map<string, int> q7Table{
            {"Digito",  8},
            {"Espacio", 0},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0},
    };
    static const std::map<string, int> q8Table{
            {"Espacio",0},
            {"División",  0},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0},
            {"Dígito", 8},
            {"Punto",  9}
    };
    static const std::map<string, int> q9Table{
            {"Espacio",     0},
            {"Dígito", 9},
            {"Exponencial",  10},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0}
    };
    static const std::map<string, int> q10Table{
            {"Dígito", 12},
            {"Resta",  11},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0}
    };
    static const std::map<string, int> q11Table{
            {"Dígito", 11},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0}
    };
    static const std::map<string, int> q12Table{
            {"Espacio",     0},
            {"Dígito", 12},
            {"Suma", 0},
            {"Multipliación", 0},
            {"Potencia", 0},
            {"Paréntesis que abre", 0},
            {"Paréntesis que cierra", 0}
    };
    this->transitionTable.push_back(q0Table);
    this->transitionTable.push_back(q1Table);
    this->transitionTable.push_back(q2Table);
    this->transitionTable.push_back(q3Table);
    this->transitionTable.push_back(q4Table);
    this->transitionTable.push_back(q5Table);
    this->transitionTable.push_back(q6Table);
    this->transitionTable.push_back(q7Table);
    this->transitionTable.push_back(q8Table);
    this->transitionTable.push_back(q9Table);
    this->transitionTable.push_back(q10Table);
    this->transitionTable.push_back(q11Table);
    this->transitionTable.push_back(q12Table);

    // Is q0 terminal
    for(int i = 0; i<12;i++) {
        if(i == 9 || i == 10) {
            this->terminalTable.push_back(false);
        }
        this->terminalTable.push_back(true);
    }
}

void StateMachine::nextState(const string& input) {
    std::map<string, int> currentTable = transitionTable[currentState];
    int nextState = currentTable.find(input)->second;
    this->currentState = nextState;
}

void StateMachine::resetMachine() {
    this->currentState = 0;
}
