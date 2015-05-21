#include <iostream>
#include <SSARI/ssari.h>
#include <memory>
#include"z3++.h"

using namespace z3;
using namespace SSARI;
using namespace std;


class z3Math: public SymbolicVar {
public:
    z3Math(string varName) : varName(varName) { }
    string toString() const {return this->expr; }
    string getName() const {return this->expr; }
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
    shared_ptr<z3Math>  gt(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e > b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  gte(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e >= b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  lt( shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e < b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  lte(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e - b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e <= result;

        return resultPtr;
    }
    shared_ptr<z3Math>  eq( shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e == b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  neq(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = !(a->e == b->e);

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }

    // Arithmetic Operations
    shared_ptr<z3Math>  add(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e + b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  sub(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e - b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  mul(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e * b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  div(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e / b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }

    // Logical Operations
    shared_ptr<z3Math>  logOr(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e || b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  logAnd(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e && b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  logNot(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = !((a->e) && (b->e)) ;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }

    // Boolean Operations
    shared_ptr<z3Math>  boolOr(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e | b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  boolAnd(shared_ptr<const z3Math> opA, shared_ptr<const z3Math> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr result = a->e & b->e;

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }
    shared_ptr<z3Math>  boolNot(shared_ptr<const z3Math> opA) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        expr result = !(a->e);

        shared_ptr<z3Math> resultPtr = shared_ptr<z3Math>(new z3Math(""));
        resultPtr->e = result;

        return resultPtr;
    }

    // Is Satisfiable -> Still W.I.P.
    bool isSat(shared_ptr<z3Math> expr) {
        context c;

        //expr e;
        solver s(c);

        switch (s.check()) {
        case unsat:   std::cout << "is unsat\n"; break;
        case sat:     std::cout << "is sat\n"; break;
        case unknown: std::cout << "unknown\n"; break;

        return true;
    }

    // Clears Any History
    void clear() {}

};
