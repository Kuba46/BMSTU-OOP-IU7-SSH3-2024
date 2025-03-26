#ifndef OPERATOR_CREATOR_H
#define OPERATOR_CREATOR_H

#include <functional>
#include <vector>
#include <map>

#include "exceptions/unknown_operator_exception.hpp"

#include "logic/include/operators/operator.h"
#include "logic/include/operators/add.h"
#include "logic/include/operators/minus.h"
#include "logic/include/operators/divide.h"
#include "logic/include/operators/multiply.h"

class OperatorCreator
{
private:
    std::map<char, std::function<Operator*()>> operators;
public:
    OperatorCreator();

    Operator* create(char character);
    int priority(char character);
};

#endif // OPERATOR_CREATOR_H
