//
// Created by Diego Ortiz on 3/22/21.
// Created by David Velázquez on 3/22/21.
// Created by Felix De Haro on 3/22/21.
//

#ifndef ACTIVIDAD3_2_CHARACTERDATA_H
#define ACTIVIDAD3_2_CHARACTERDATA_H

#include <iostream>

using namespace std;

class CharacterData {
private:
    char characterChar;
    string characterType;
public:
    CharacterData(char characterChar);

    char getCharacterChar() const;

    const string &getCharacterType() const;

};


#endif //ACTIVIDAD3_2_CHARACTERDATA_H
