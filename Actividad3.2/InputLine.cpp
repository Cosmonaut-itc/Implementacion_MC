//
// Created by Diego Ortiz on 3/22/21.
//

#include "InputLine.h"

#include <utility>

InputLine::InputLine(string lineString) : lineString(std::move(lineString)) {
    for (char &currentChar : this->lineString) {
        CharacterData CurrentCharacterData(currentChar);
        this->characters.emplace_back(currentChar);
    }
}
