#include "logic/include/parser.h"
#include "logic/include/commands/operatorcommand.h"
#include "logic/include/commands/push_command_to_stack.h"

#include "exceptions/unknown_operator_exception.hpp"

#include <locale>

Parser::Parser(const str& expression) {
    this->expression = expression;
}

double Parser::toDouble(str str) {
    char point = std::use_facet<std::numpunct<char>>(std::locale("")).decimal_point();
    if (str.find('.') != str::npos) {
        str[str.find('.')] = point;
    }
    return std::stod(str);
}

str Parser::toString(double value) {
    str result = std::to_string(value);
    char point = std::use_facet<std::numpunct<char>>(std::locale("")).decimal_point();
    if (result.find(point) != str::npos) {
        result[result.find(point)] = '.';
    }
    return result;
}

void Parser::splitString(std::vector<str>& parts)
{
    str expression = this->expression;
    size_t pos = 0;
    while ((pos = expression.find(' ')) != str::npos)
    {
        parts.push_back(expression.substr(0, pos));
        expression.erase(0, pos + 1);
    }
    parts.push_back(expression);
}

void Parser::parse(std::vector<Command<Calculator>*>& commands)
{
    if (this->expression.length() == 0)
    {
        commands.push_back(new PushCommand(0));
        return;
    }
    OperatorCreator operatorCreator;
    std::vector<str> parts;
    splitString(parts);
    for (str& part : parts)
    {
        if (operators.find(part) != std::string::npos)
        {
            Operator* op = operatorCreator.create(part[0]);
            commands.push_back(new OperatorCommand(op));
        }
        else
        {
            commands.push_back(new PushCommand(toDouble(part)));
        }
    }
}
