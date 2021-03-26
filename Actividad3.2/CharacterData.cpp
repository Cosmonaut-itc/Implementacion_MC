//
// Created by Diego Ortiz on 3/22/21.
//

#include <map>
#include "CharacterData.h"

CharacterData::CharacterData(char characterChar) : characterChar(characterChar) {
    if (isdigit(characterChar)) {
        this->characterType = "Dígito";
    } else {
        if (isalpha(characterChar)) {
            this->characterType = "Letra";
        } else {
            static const std::map<char, string> characterTable{
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
                            {'_',"UnderScore"},
                            {'\n', "SaltoDeLinea"}
                    }
            };
            this->characterType = characterTable.find(characterChar)->second;
        }
    }
}
