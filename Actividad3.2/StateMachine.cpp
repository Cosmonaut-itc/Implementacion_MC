//
// Created by Diego Ortiz on 3/25/21.
//

#include "StateMachine.h"

StateMachine::StateMachine() {

    const std::map<char, string> stateTable{
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
    this->stateTable = stateTable;
}
