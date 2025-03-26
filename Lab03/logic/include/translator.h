#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <string>
#include <vector>

#include "configurations.h"

using str = std::string;

class Translator
{
private:
    const str digits = FORNUMBER;
    const str brackets = BRACKETS;

    str input;
    
    str join(std::vector<str>& parts);
public:
    Translator(const str& input);

    str translate();
};

#endif // TRANSLATOR_H
