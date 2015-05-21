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
    expr e;
};


class z3Operations : public CVarMath {
public:
    // Set Operation
    shared_ptr<SymbolicVar> set(shared_ptr<SymbolicVar> var){ return var;}

    // Get Operation
    shared_ptr<const SymbolicVar> get(shared_ptr<const CConstant> c) { // Ignore this error for now

        return shared_ptr<SimpleSymVar>(new SimpleSymVar(c->toString())); // And this one
    }

    // Boolean Operations
    shared_ptr<z3Math>  gt(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  gte(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  lt( shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  lte(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  eq( shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  neq(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);

    // Arithmetic Operations
    shared_ptr<z3Math>  add(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  sub(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  mul(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  div(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);

    // Logical Operations
    shared_ptr<z3Math>  logOr(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  logAnd(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  logNot(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);

    // Boolean Operations
    shared_ptr<z3Math>  boolOr(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  boolAnd(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB);
    shared_ptr<z3Math>  boolNot(shared_ptr<const z3Math> opA) ;

    // Is Satisfiable -> Still W.I.P.
    bool isSat(shared_ptr<z3Math> expr);

    // Clears Any History
    void clear() {}{
};




#endif // Z3TEST_H
