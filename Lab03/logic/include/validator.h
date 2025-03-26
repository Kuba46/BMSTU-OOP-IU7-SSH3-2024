#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

#include "exceptions/invalid_expression_exception.hpp"
#include "configurations.h"

class Validator
{
private:
    const str digits = DIGITS;
    const char point = POINT;
    const str operators = OPERATORS;
    const str brackets = BRACKETS;

    str expression;

    bool hasCharacterInNumber(size_t begin, char character);
public:
    Validator(const str& expression);

    void validate();
};

#endif // VALIDATOR_H
