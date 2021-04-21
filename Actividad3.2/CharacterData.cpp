//
// Created by Diego Ortiz on 3/22/21.
// Created by David Velázquez on 3/22/21.
// Created by Felix De Haro on 3/22/21.
//

#include <map>
#include "CharacterData.h"

CharacterData::CharacterData(char characterChar) : characterChar(characterChar) {
    if (isdigit(characterChar)) {
        this->characterType = "Dígito";
    } else {
        if (isalpha(characterChar) && characterChar != 'e' && characterChar != 'E' && characterChar != 'f' &&
            characterChar != 't') {
            this->characterType = "Letra";
        } else {
            static const std::map<char, string> characterTable{
                    {
                            {'=', "Asignacion"},
                            {'+', "Suma"},
                            {'-', "Resta"},
                            {'*', "Multiplicacion"},
                            {'/', "Division"},
                            {'^', "Potencia"},
                            {' ', "Espacio"},
                            {'.', "Punto"},
                            {'(', "Parentesis que abre"},
                            {')', "Parentesis que cierra"},
                            {'_', "UnderScore"},
                            {'\n', "SaltoDeLinea"},
                            {'E', "Exponencial"},
                            {'e', "Exponencial"},
                            {';', "PuntoYComa"},
                            {'f', "False"},
                            {'t', "True"},
                            {'#', "Hashtag"},
                            {'\'', "Quote"}
                    }
            };
            if (characterTable.find(characterChar) == characterTable.end()) {
                this->characterType = "Error (character not found)";
            } else {
                this->characterType = characterTable.find(characterChar)->second;
            }

        }

    }
}

char CharacterData::getCharacterChar() const {
    return characterChar;
}

const string &CharacterData::getCharacterType() const {
    return characterType;
}
