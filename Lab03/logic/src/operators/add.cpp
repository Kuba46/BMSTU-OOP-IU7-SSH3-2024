#include "logic/include/operators/add.h"

double Add::execute(double left, double right) {
    return left + right;
}

int Add::priority() {
    return 1;
}

Operator* Add::clone() {
    return new Add(*this);
}
