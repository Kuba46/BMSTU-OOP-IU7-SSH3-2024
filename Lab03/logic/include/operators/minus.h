#ifndef MINUS_H
#define MINUS_H

#include "logic/include/operators/operator.h"

class Minus : public Operator {
public:
    double execute(double left, double right) override;
    int priority() override;
    Operator* clone() override;
};

#endif // MINUS_H
