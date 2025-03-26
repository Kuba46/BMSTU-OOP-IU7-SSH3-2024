#include "logic/include/calculator.h"

Calculator::Calculator() {}

void Calculator::pushStack(double number)
{
    stack.push_back(number);
}

void Calculator::calculate(Operator* op)
{
    if (stack.size() >= 2)
    {
        double value = op->execute(*(++stack.rbegin()), *stack.rbegin());
        stack.erase(stack.begin() + (stack.size() - 1));
        stack.erase(stack.begin() + (stack.size() - 1));
        stack.push_back(value);
    }
}

double Calculator::top()
{
    return stack.size() > 0 ? *stack.rbegin() : 0;
}
