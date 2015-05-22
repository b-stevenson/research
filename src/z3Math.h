#ifndef Z3TEST_H
#define Z3TEST_H

#include<z3++.h>
#include<SSARI/ssari.h>
#include<memory>
#include<string>
#include<sstream>

using std::stringstream;
using std::string;
using std::shared_ptr;
using namespace SSARI;
using namespace z3;

class Z3Var: public SymbolicVar {
public:
    Z3Var(expr e) : e(e) { }
    string toString() const {
        stringstream ss;
        ss << e;
        return ss.str();
    }
    expr e;
};


class Z3Math : public CVarMath {
public:
    Z3Math();
    ~Z3Math();

    // Set Operation
    shared_ptr<SymbolicVar> set(CVar var, shared_ptr<SymbolicVar> expr);

    // Get Operation
    shared_ptr<SymbolicVar> get(shared_ptr<const CConstant> c);

    // Boolean Operations
    shared_ptr<SymbolicVar>  gt(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  gte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  lt( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  lte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  eq( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  neq(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);

    // Arithmetic Operations
    shared_ptr<SymbolicVar>  add(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  sub(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  mul(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  div(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);

    // Logical Operations
    shared_ptr<SymbolicVar>  logOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  logAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  logNot(shared_ptr<const SymbolicVar> opA);

    // Boolean Operations
    shared_ptr<SymbolicVar>  boolOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  boolAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB);
    shared_ptr<SymbolicVar>  boolNot(shared_ptr<const SymbolicVar> opA) ;

    // Is Satisfiable
    bool isSat(shared_ptr<SymbolicVar> expr);
    void addClause(shared_ptr<SymbolicVar> expr);


    // Clears Any History
    void clear();
private:
    solver *s;
    context cntxt;
    int vCount = 0;
};




#endif // Z3TEST_H
