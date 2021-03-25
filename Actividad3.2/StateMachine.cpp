//
// Created by Diego Ortiz on 3/25/21.
//

#include "StateMachine.h"

StateMachine::StateMachine() {

    std::map<char, string> declareStateTable{
            {
                    {'=', "Asignación"},
                    {'+', "Suma"},
                    {'-', "Resta"},
                    {'*', "Multipliación"},
                    {'/', "División"},
                    {'^', "Potencia"},
                    {' ', "Espacio"},
                    {'.', "Punto"},
                    {'(', "Parentesís que abre"},
                    {')', "Paréntesis que cierra"},
                    {'_',"UnderScore"}
            }
    };
    this->stateTable = declareStateTable;
}
