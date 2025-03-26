#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>

#include "logic/include/operators/operator.h"

class Calculator
{
private:
    std::vector<double> stack;
public:
    Calculator();

    void pushStack(double number);
    void calculate(Operator* op);

    double top();
};

#endif // CALCULATOR_H
