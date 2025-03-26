#include "logic/include/operators/multiply.h"

double Multiply::execute(double left, double right) {
    return left * right;
}

int Multiply::priority()
{
    return 2;
}

Operator* Multiply::clone() {
    return new Multiply(*this);
}
