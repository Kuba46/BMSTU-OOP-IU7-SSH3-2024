#ifndef PARCER_H
#define PARCER_H

#include <vector>
#include <string>

#include "configurations.h"

#include "logic/include/calculator.h"
#include "logic/include/commands/command.hpp"
#include "logic/include/operators/operatorcreator.h"

class Parser
{
private:
    str expression;

    const str operators = OPERATORS;
    void splitString(std::vector<str>& parts);
public:
    Parser(const str& expression);

    static double toDouble(str str);
    static str toString(double value);

    void parse(std::vector<Command<Calculator>*>& commands);
};

#endif // PARCER_H
