#ifndef DIVIDE_H
#define DIVIDE_H

#include "logic/include/operators/operator.h"

class Divide : public Operator {
public:
    double execute(double left, double right) override;
    int priority() override;
    Operator* clone() override;
};

#endif // DIVIDE_H
