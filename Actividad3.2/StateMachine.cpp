//
// Created by Diego Ortiz on 3/22/21.
// Created by David Velázquez on 3/22/21.
// Created by Felix De Haro on 3/22/21.
//

#include "StateMachine.h"

StateMachine::StateMachine() {
    this->currentState = 0;
    this->currentChar = '\0';
    this->currentCharType = "Null";
    // Add reserved words
    this->reservedWords = {
            {"define", 1}
    };
    // Initial state and operator state
    static const std::map<string, int> q0Table{
            {"Parentesis que abre",   1},
            {"Parentesis que cierra", 1},
            {"Letra",                 2},
            {"Exponencial",           2},
            {"False",                 2},
            {"True",                  2},
            {"PuntoYComa",            3},
            {"Resta",                 4},
            {"Dígito",                5},
            {"Hashtag",               11},
            {"Quote",                 13},
            // Escape characters
            {"Division",              0},
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0},
    };
    // Special characters state
    static const std::map<string, int> q1Table{
            {"Parentesis que abre",   1},
            {"Parentesis que cierra", 1},
            // State only escape
            {"Letra",                 2},
            {"Exponencial",           2},
            {"False",                 2},
            {"True",                  2},
            {"Dígito",                5},
            {"Resta",                 4},
            {"PuntoYComa",            3},
            {"Quote",                 13},
            // Escape characters
            {"Division",              0},
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
            {"False",                 2},
            {"True",                  2},
            {"Underscore",            2},
            {"Dígito",                2},
            // State only escape
            {"Parentesis que abre",   1},
            {"Parentesis que cierra", 1},
            {"Resta",                 4},
            {"PuntoYComa",            3},
            {"Quote",                 13},
            // Escape characters
            {"Division",              0},
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
            {"PuntoYComa",            3},
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
            {"False",                 3},
            {"True",                  3},
            {"Quote",                 3},
            // Escape characters
            {"SaltoDeLinea",          0},
    };
    // Negative State
    static const std::map<string, int> q4Table{
            {"Dígito",                5},
            // State only escape
            {"Parentesis que abre",   1},
            {"Parentesis que cierra", 1},
            {"Letra",                 2},
            {"Exponencial",           2},
            {"False",                 2},
            {"True",                  2},
            {"Resta",                 4},
            {"PuntoYComa",            3},
            {"Quote",                 13},
            // Escape characters
            {"Division",              0},
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
            {"Parentesis que abre",   1},
            {"Parentesis que cierra", 1},
            {"Resta",                 4},
            {"PuntoYComa",            3},
            {"Quote",                 13},
            // Escape characters
            {"Division",              0},
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
            {"Parentesis que abre",   1},
            {"Parentesis que cierra", 1},
            {"Resta",                 4},
            {"PuntoYComa",            3},
            {"Quote",                 13},
            // Escape characters
            {"Division",              0},
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
            {"Parentesis que abre",   1},
            {"Parentesis que cierra", 1},
            {"Resta",                 0},
            {"PuntoYComa",            3},
            {"Quote",                 13},
            // Escape characters
            {"Division",              0},
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
            {"Division",              0},
            // State only escape
            {"Parentesis que abre",   1},
            {"Parentesis que cierra", 1},
            {"Resta",                 4},
            {"PuntoYComa",            3},
            {"Quote",                 13},
    };
    // Logic state (non terminal)
    static const std::map<string, int> q11Table{
            {"True",  12},
            {"False", 12},
    };
    // Logic state (terminal)
    static const std::map<string, int> q12Table{
            // State only escape characters
            {"Resta",                 4},
            {"PuntoYComa",            3},
            {"Parentesis que abre",   1},
            {"Parentesis que cierra", 1},
            {"Quote",                 13},
            // Escape characters
            {"Espacio",               0},
            {"Suma",                  0},
            {"Multiplicacion",        0},
            {"Potencia",              0},
            {"Parentesis que abre",   0},
            {"Parentesis que cierra", 0},
            {"SaltoDeLinea",          0},
            {"Asignacion",            0},
            {"Division",              0},
    };
    // Symbol state (non terminal)
    static const std::map<string, int> q13Table{
            {"Quote",          13},
            {"Dígito",         14},
            {"Letra",          14},
            {"Exponencial",    14},
            {"False",          14},
            {"True",           14},
            {"Resta",          14},
            {"Suma",           14},
            {"Multiplicacion", 14},
            {"Potencia",       14},
            {"Asignacion",     14},
            {"Division",       14},
    };
    // Symbol state (terminal)
    static const std::map<string, int> q14Table{
            {"Dígito",         14},
            {"Letra",          14},
            {"Exponencial",    14},
            {"False",          14},
            {"True",           14},
            {"Resta",          14},
            {"Suma",           14},
            {"Multiplicacion", 14},
            {"Potencia",       14},
            {"Asignacion",     14},
            {"Division",       14},
            // Escape characters
            {"Espacio",        0},
            {"SaltoDeLinea",   0},
            // State only escape characters
            {"Quote",          13},
    };

    stateNames.emplace_back("Operadores");
    this->transitionTable.push_back(q0Table);
    stateNames.emplace_back("Especiales");
    this->transitionTable.push_back(q1Table);
    stateNames.emplace_back("Identificadores");
    this->transitionTable.push_back(q2Table);
    stateNames.emplace_back("Comentarios");
    this->transitionTable.push_back(q3Table);
    stateNames.emplace_back("Operadores");
    this->transitionTable.push_back(q4Table);
    stateNames.emplace_back("Números");
    this->transitionTable.push_back(q5Table);
    stateNames.emplace_back("Números");
    this->transitionTable.push_back(q6Table);
    // Exponential state (non terminal)
    stateNames.emplace_back("Errores");
    this->transitionTable.push_back(q7Table);
    // Float with negative exponential state (non terminal)
    stateNames.emplace_back("Errores");
    this->transitionTable.push_back(q8Table);
    stateNames.emplace_back("Números");
    this->transitionTable.push_back(q9Table);
    stateNames.emplace_back("Errores");
    this->transitionTable.push_back(q10Table);
    // Logic State (non terminal)
    stateNames.emplace_back("Errores");
    this->transitionTable.push_back(q11Table);
    stateNames.emplace_back("Lógicos");
    this->transitionTable.push_back(q12Table);
    stateNames.emplace_back("Símbolos");
    this->transitionTable.push_back(q13Table);
    stateNames.emplace_back("Símbolos");
    this->transitionTable.push_back(q14Table);
}


int StateMachine::nextState(const string &input) {
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

Token StateMachine::lexer(const vector<InputLine> &Lines) {
    for (const auto &line: Lines) {
        string accumulated;
        for (const auto &characterData: line.characters) {
            char nextChar = characterData.getCharacterChar();
            const string &nextCharType = characterData.getCharacterType();
            int nextState = this->nextState(nextCharType);

            // If machine its currently on non initial escape state
            // Negative state
            if (currentState == 1) {
                addCurrentToTokens();
            }
            // Comment state
            if (currentState == 4) {
                if (nextState != 5) {
                    addCurrentToTokens();
                } else {
                    accumulated += currentChar;
                }
            }
            // Symbol state
            if (currentState == 13) {
                if (nextState != 14) {
                    addCurrentToTokens();
                } else {
                    accumulated += currentChar;
                }
            }

            // Print operator from the initial state
            if (currentState == 0 && currentCharType != "Espacio" && currentCharType != "SaltoDeLinea" && currentCharType != "Null") {
                addCurrentToTokens();
            }
            if (currentState == 0 && (currentCharType == "Espacio" || currentCharType == "SaltoDeLinea")) {
                string stateName;
                stateName = currentCharType;
                tokens.addToken(string(1, currentChar), stateName);
            }

            // If next state is an initial state or symbol that "Restarts machine"
            if (nextState == 0 || nextState == 1 || nextState == 4 || nextState == 13 ||
                (nextState == 3 && currentState != 3)) {
                // If there is something accumulated
                if (!accumulated.empty()) {
                    // Add accumulated to tokens
                    string stateName;
                    if (this->reservedWords.find(accumulated) != this->reservedWords.end()) {
                        stateName = "Palabras reservadas";
                    } else {
                        stateName = stateNames[currentState];
                    }
                    tokens.addToken(accumulated, stateName);
                    accumulated = "";
                }
            } else {
                accumulated += nextChar;
            }

            // Print if next is a comment operator
            if (nextState == 3 && currentState != 3) {
                accumulated += nextChar;
            }

            this->currentState = nextState;
            this->currentChar = nextChar;
            this->currentCharType = nextCharType;
        }
    }
    return tokens;
}
