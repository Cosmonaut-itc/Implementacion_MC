//
// Created by Diego Ortiz on 3/22/21.
//

#ifndef IMPLEMENTACION_MC_WORD_H
#define IMPLEMENTACION_MC_WORD_H

#include <iostream>
#include <vector>
#include "CharacterData.h"


class InputLine {
private:
    string lineString;
public:
    InputLine(string lineString);

    vector<CharacterData> characters;
};


#endif //IMPLEMENTACION_MC_WORD_H
