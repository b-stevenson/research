#ifndef Z3TEST_H
#define Z3TEST_H
#include<z3++.h>
#include<ssari.h>
#include<gtest/gtest.h>
class z3Math: public SymbolicVar {
public:
    z3Math(string varName) : varName(varName) { }
    string toString() const {return this->varName; }
    string getName() const { return this->varName; }
    context c;
    expr e;
};
#endif // Z3TEST_H
