//
// Created by Diego Ortiz on 3/22/21.
// Created by David Velázquez on 3/22/21.
// Created by Felix De Haro on 3/22/21.
//

#include "StateMachine.h"

StateMachine::StateMachine() {
    this->currentState = 0;
    this->currentChar = '\n';
    this->currentCharType = "SaltoDeLinea";
    // Initial state and operator state
    static const std::map<string, int> q0Table{
            {"Letra",                 2},
            {"Exponencial",           2},
            {"Dígito",                5},
            {"Division",              1},
            {"Resta",                 4},
            // Escape characters
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"Parentesis que abre",   0},
            {"Parentesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0},
    };
    // Division state
    static const std::map<string, int> q1Table{
            {"Division",              3},
            // State only escape
            {"Letra",                 2},
            {"Exponencial",           2},
            {"Dígito",                5},
            {"Resta",                 4},
            // Escape characters
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"Parentesis que abre",   0},
            {"Parentesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0},
    };
    // Variable state
    static const std::map<string, int> q2Table{
            {"Letra",                 2},
            {"Exponencial",           2},
            {"Underscore",            2},
            {"Dígito",                2},
            // State only escape
            {"Division",              1},
            {"Resta",                 4},
            // Escape characters
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"Parentesis que abre",   0},
            {"Parentesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0},
    };
    // Comment state
    static const std::map<string, int> q3Table{
            {"Asignacion",            3},
            {"Suma",                  3},
            {"Resta",                 3},
            {"Multiplicacion",        3},
            {"Division",              3},
            {"Potencia",              3},
            {"Espacio",               3},
            {"Punto",                 3},
            {"Parentesís que abre",   3},
            {"Parentesis que cierra", 3},
            {"UnderScore",            3},
            {"Exponencial",           3},
            {"Letra",                 3},
            {"Dígito",                3},
            // Escape characters
            {"SaltoDeLinea",          0},
    };
    // Negative State
    static const std::map<string, int> q4Table{
            {"Dígito",                5},
            // State only escape
            {"Division",              1},
            {"Letra",                 2},
            {"Exponencial",           2},
            {"Resta",                 4},
            // Escape characters
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"Parentesis que abre",   0},
            {"Parentesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0},
    };
    // Digit(s) state
    static const std::map<string, int> q5Table{
            {"Dígito",                5},
            {"Punto",                 6},
            // State only escape
            {"Division",              1},
            {"Resta",                 4},
            // Escape characters
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"Parentesis que abre",   0},
            {"Parentesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0},
    };
    // Float state
    static const std::map<string, int> q6Table{
            {"Dígito",                6},
            {"Exponencial",           7},
            // State only escape
            {"Division",              1},
            {"Resta",                 4},
            // Escape characters
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"Parentesis que abre",   0},
            {"Parentesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0},
    };
    // Exponential state (none terminal)
    static const std::map<string, int> q7Table{
            {"Dígito", 9},
            {"Resta",  8},
    };

    //Float with negative exponential state (non terminal)
    static const std::map<string, int> q8Table{
            {"Dígito", 9},
    };

    //Float with negative digit(s) exponential
    static const std::map<string, int> q9Table{
            {"Dígito",                9},
            // State only escape
            {"Division",              0},
            {"Resta",                 0},
            // Escape characters
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"Parentesis que abre",   0},
            {"Parentesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0}
    };
    // Error
    static const std::map<string, int> q10Table{
            // Escape characters
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"Parentesis que abre",   0},
            {"Parentesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0},
            {"Division",              1},
            {"Resta",                 4},
    };
    stateNames.emplace_back("Operador");
    this->transitionTable.push_back(q0Table);
    stateNames.emplace_back("Operador");
    this->transitionTable.push_back(q1Table);
    stateNames.emplace_back("Variable (identificador)");
    this->transitionTable.push_back(q2Table);
    stateNames.emplace_back("Comentario");
    this->transitionTable.push_back(q3Table);
    stateNames.emplace_back("Operador");
    this->transitionTable.push_back(q4Table);
    stateNames.emplace_back("Entero");
    this->transitionTable.push_back(q5Table);
    stateNames.emplace_back("Flotantes (Reales)");
    this->transitionTable.push_back(q6Table);
    stateNames.emplace_back("Exponential state (none terminal)");
    this->transitionTable.push_back(q7Table);
    stateNames.emplace_back("Float with negative exponential state (non terminal)");
    this->transitionTable.push_back(q8Table);
    stateNames.emplace_back("Flotantes (Reales)");
    this->transitionTable.push_back(q9Table);
    stateNames.emplace_back("Error");
    this->transitionTable.push_back(q10Table);
}


int StateMachine::nextState(const string& input) {
    std::map<string, int> currentTable = transitionTable[currentState];
    if (currentTable.find(input) == currentTable.end()) {
        // If not found
        return 10;
    } else {
        // If found
        return currentTable.find(input)->second;
    }
}

void StateMachine::addCurrentToTokens() {
    string stateName;
    stateName = stateNames[currentState];
    tokens.addToken(string(1, currentChar), stateName);
}

Token StateMachine::lexer(const vector<InputLine>& Lines) {
    for (const auto &line: Lines) {
        string accumulated;
        for (const auto &characterData: line.characters) {
            char nextChar = characterData.getCharacterChar();
            const string& nextCharType = characterData.getCharacterType();
            int nextState = this->nextState(nextCharType);

            // If machine its currently on non initial operator state
            if (currentState == 1) {
                if (nextState != 3) {
                    // Add current character to tokens
                    addCurrentToTokens();
                } else {
                    accumulated += currentChar;
                }
            }
            if (currentState == 4) {
                if (nextState != 5) {
                    addCurrentToTokens();
                } else {
                    accumulated += currentChar;
                }
            }

            // Print operator from the initial state
            if (currentState == 0 && currentCharType != "Espacio" && currentCharType != "SaltoDeLinea") {
                addCurrentToTokens();
            }
            // If next state is an operator state
            if (nextState == 0 || nextState == 1 || nextState == 4) {
                // If there is something accumulated
                if (!accumulated.empty()) {
                    // Add accumulated to tokens
                    string stateName;
                    stateName = stateNames[currentState];
                    tokens.addToken(accumulated, stateName);
                    accumulated = "";
                }
            } else {
                accumulated += nextChar;
            }

            this->currentState = nextState;
            this->currentChar = nextChar;
            this->currentCharType = nextCharType;
        }
    }
    return tokens;
}
