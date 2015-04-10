#include <iostream>
#include <ssari.h>
#include <memory>
#include"z3++.h"

using namespace z3;
using namespace SSARI;
using namespace std;


class z3Math: public SymbolicVar {
public:
    z3Math(string varName) : varName(varName) { }
    string toString() const {return this->varName; }
    string getName() const { return this->varName; }


private:
    expr a, b, result, conjecture;
};

class SimpleMath : public CVarMath {
public:
    // Set Operation
    shared_ptr<SymbolicVar> set(shared_ptr<SymbolicVar> var){ return var;}

    // Get Operation
    shared_ptr<const SymbolicVar> get(shared_ptr<const CConstant> c) {

        return shared_ptr<SimpleSymVar>(new SimpleSymVar(c->toString()));
    }

    // Boolean Operations
    shared_ptr<SymbolicVar>  gt( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
       return NULL;
    }
    shared_ptr<SymbolicVar>  gte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
       return NULL;
    }
    shared_ptr<SymbolicVar>  lt( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
       return NULL;
    }
    shared_ptr<SymbolicVar>  lte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
       return NULL;
    }
    shared_ptr<SymbolicVar>  eq( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
       return NULL;
    }
    shared_ptr<SymbolicVar>  neq(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
       return NULL;
    }

    // Arithmetic Operations
    shared_ptr<SymbolicVar>  add(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        shared_ptr<const z3Math> a = dynamic_pointer_cast<const z3Math>(opA);
        shared_ptr<const z3Math> b = dynamic_pointer_cast<const z3Math>(opB);
        expr a = dynamic_pointer_cast<const z3Math>(opA);
        expr b = dynamic_pointer_cast<const z3Math>(opB);
        expr b = dynamic_pointer_cast<const z3Math>(opB);
        return shared_ptr<z3Math>(new SimpleSymVar(a->getName() + " + " + b->getName()));
    }
    shared_ptr<SymbolicVar>  sub(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
       return NULL;
    }
    shared_ptr<SymbolicVar>  mul(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
      return NULL;
    }
    shared_ptr<SymbolicVar>  div(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
      return NULL;
    }

    // Logical Operations
    shared_ptr<SymbolicVar>  logOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
      return NULL;
    }
    shared_ptr<SymbolicVar>  logAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
      return NULL;
    }
    shared_ptr<SymbolicVar>  logNot(shared_ptr<const SymbolicVar> op) {
      return NULL;
    }

    // Boolean Operatiosn
    shared_ptr<SymbolicVar>  boolOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        return NULL;
    }
    shared_ptr<SymbolicVar>  boolAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
        return NULL;
    }
    shared_ptr<SymbolicVar>  boolNot(shared_ptr<const SymbolicVar> op) {
        return NULL;
    }

    // Is Satisfiable
    bool isSat(shared_ptr<SymbolicVar> expr) {
        return true;
    }

    // Clears Any History
    void clear() {}
};
