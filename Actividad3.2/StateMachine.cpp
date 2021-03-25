//
// Created by Diego Ortiz on 3/25/21.
//

#include "StateMachine.h"

StateMachine::StateMachine() {
    this->currentState = 0;
    static const std::map<string, int> q0Table{
            {"Espacio",     0},
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q1Table{
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q2Table{
            {"Espacio",     0},
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q3Table{
            {"Espacio",     0},
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q4Table{
            {"Espacio",     0},
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q5Table{
            {"Espacio",     0},
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q6Table{
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q7Table{
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q8Table{
            {"Espacio",     0},
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q9Table{
            {"Espacio",     0},
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q10Table{
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q11Table{
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
    };
    static const std::map<string, int> q12Table{
            {"Espacio",     0},
            {"Letra",  3},
            {"Dígito", 8},
            {"Resta",  7}
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
}
