//
// Created by Diego Ortiz on 3/25/21.
//

#include "StateMachine.h"

StateMachine::StateMachine() {
    this->currentState = 0;
    // Estado Incial
    static const std::map<string, int> q0Table{
            {"Espacio",               0},
            {"División",              1},
            {"Suma",                  0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Letra",                 3},
            {"Exponencial",           3},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"Resta",                 7},
            {"Dígito",                8},
            {"SaltoDeLinea",          0},
            {"Asignación",            0},
    };

    static const std::map<string, int> q1Table{
            {"Espacio",               0},
            {"División",              6},
            {"Resta",                 0},
            {"Suma",                  0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0}
    };
    static const std::map<string, int> q2Table{
            {"Espacio",               0},
            {"Suma",                  0},
            {"División",              0},
            {"Resta",                 0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0}
    };
    static const std::map<string, int> q3Table{
            {"Espacio",               0},
            {"Letra",                 3},
            {"Exponencial",           3},
            {"Underscore",            3},
            {"División",              0},
            {"Resta",                 0},
            {"Dígito",                3},
            {"Suma",                  0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignación",            0},
    };
    static const std::map<string, int> q4Table{
            {"Espacio",               0},
            {"Suma",                  0},
            {"División",              0},
            {"Resta",                 0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0},
    };
    static const std::map<string, int> q5Table{
            {"Espacio",               0},
            {"Suma",                  0},
            {"División",              0},
            {"Resta",                 0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0},
    };
    static const std::map<string, int> q6Table{
            {"Asignación",            6},
            {"Suma",                  6},
            {"Resta",                 6},
            {"Multipliación",         6},
            {"División",              6},
            {"Potencia",              6},
            {"Espacio",               6},
            {"Punto",                 6},
            {"Parentesís que abre",   6},
            {"Paréntesis que cierra", 6},
            {"UnderScore",            6},
            {"Exponencial",           6},
            {"Letra",                 6},
            {"SaltoDeLinea",          0}
    };
    static const std::map<string, int> q7Table{
            {"Dígito",                8},
            {"Espacio",               0},
            {"Suma",                  0},
            {"División",              0},
            {"Resta",                 0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0},
    };
    static const std::map<string, int> q8Table{
            {"Espacio",               0},
            {"División",              0},
            {"Resta",                 0},
            {"Suma",                  0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"Dígito",                8},
            {"Punto",                 9},
            {"SaltoDeLinea",          0},
    };
    static const std::map<string, int> q9Table{
            {"Espacio",               0},
            {"Dígito",                9},
            {"División",              0},
            {"Resta",                 0},
            {"Exponencial",           10},
            {"Suma",                  0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0},
    };
    static const std::map<string, int> q10Table{
            {"Dígito",                12},
            {"Resta",                 11},
            {"División",              0},
            {"Suma",                  0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0},
    };
    static const std::map<string, int> q11Table{
            {"Dígito",                11},
            {"Suma",                  0},
            {"División",              0},
            {"Resta",                 0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0},
    };
    static const std::map<string, int> q12Table{
            {"Espacio",               0},
            {"Dígito",                12},
            {"Suma",                  0},
            {"División",              0},
            {"Resta",                 0},
            {"Multipliación",         0},
            {"Potencia",              0},
            {"Paréntesis que abre",   0},
            {"Paréntesis que cierra", 0},
            {"SaltoDeLinea",          0},
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


/*
7.5e-5, real
7a/, 7a error, / division
7aaaaa 8, 7aaaaaa error, 8 interger
 */


int StateMachine::nextState(string input) {
    std::map<string, int> currentTable = transitionTable[currentState];
    if (currentTable.find(input) == currentTable.end()) {
        // If not found
        return -1;
    } else {
        // If found
        return currentTable.find(input)->second;
    }


}

void StateMachine::resetMachine() {
    this->currentState = 0;
}

void StateMachine::lexer(vector<InputLine> Lines) {
    for (const auto &line: Lines) {
        string accumulated = "";
        for (const auto &characterData: line.characters) {
            char currentChar = characterData.getCharacterChar();
            string currentCharType = characterData.getCharacterType();
            int nextState = this->nextState(currentCharType);
            //cout << currentState << ", "<< nextState;
            if (nextState == -1) {
                cout << "no encontrado: ";
                nextState = 0;
            }
            if (nextState == 0) {
                if (accumulated != "") {
                    cout << accumulated << " Estado: " << currentState << endl;
                }
                if (currentCharType != "Espacio" && currentCharType != "SaltoDeLinea") {
                    cout << currentChar << " Estado: " << currentState << endl;
                }
                accumulated = "";
            } else {
                if (currentCharType != "SaltoDeLinea") {
                    accumulated += currentChar;
                }
            }
            this->currentState = nextState;
        }
    }
}
