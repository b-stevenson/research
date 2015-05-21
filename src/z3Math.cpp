#include <iostream>
#include <SSARI/ssari.h>
#include <memory>
#include"z3++.h"
#include "z3Math.h"

using namespace z3;
using namespace SSARI;
using namespace std;
using s_Z3Var = shared_ptr<Z3Var>;
using sc_Z3Var = shared_ptr<const Z3Var>;

// Set Operation
shared_ptr<SymbolicVar> Z3Math::set(CVar var, shared_ptr<SymbolicVar> expr) {
    return expr;
}

// Get Operation
shared_ptr<SymbolicVar> Z3Math::get(shared_ptr<const CConstant> c) {
    if(dynamic_pointer_cast<const CUniversal>(c))
    {
        string val = "U" + to_string(uCount++);
        return s_Z3Var(new Z3Var(cntxt.real_const(val.c_str())));
    }
    return s_Z3Var(new Z3Var(cntxt.real_val(c->toString().c_str())));
}

// Boolean Operations
shared_ptr<SymbolicVar>  Z3Math::gt(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e > b->e));
    return resultPtr;
}

shared_ptr<SymbolicVar>  Z3Math::gte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e >= b->e));
    return resultPtr;
}

shared_ptr<SymbolicVar>  Z3Math::lt( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e < b->e));
    return resultPtr;
}

shared_ptr<SymbolicVar>  Z3Math::lte(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e <= b->e));
    return resultPtr;
}

shared_ptr<SymbolicVar>  Z3Math::eq( shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e == b->e));
    return resultPtr;
}

shared_ptr<SymbolicVar>  Z3Math::neq(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e != b->e));
    return resultPtr;
}

// Arithmetic Operations
shared_ptr<SymbolicVar>  Z3Math::add(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e + b->e));
    return resultPtr;
}
shared_ptr<SymbolicVar>  Z3Math::sub(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e - b->e));
    return resultPtr;
}
shared_ptr<SymbolicVar>  Z3Math::mul(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e * b->e));
    return resultPtr;
}
shared_ptr<SymbolicVar>  Z3Math::div(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e / b->e));
    return resultPtr;
}

// Logical Operations
shared_ptr<SymbolicVar>  Z3Math::logOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e || b->e));
    return resultPtr;
}

shared_ptr<SymbolicVar>  Z3Math::logAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e && b->e));
    return resultPtr;
}
shared_ptr<SymbolicVar>  Z3Math::logNot(shared_ptr<const SymbolicVar> opA) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(!a->e));
    return resultPtr;
}

// Boolean Operations
shared_ptr<SymbolicVar>  Z3Math::boolOr(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e | b->e));
    return resultPtr;
}

shared_ptr<SymbolicVar>  Z3Math::boolAnd(shared_ptr<const SymbolicVar> opA, shared_ptr<const SymbolicVar> opB) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    sc_Z3Var b = dynamic_pointer_cast<const Z3Var>(opB);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(a->e & b->e));
    return resultPtr;
}

shared_ptr<SymbolicVar>  Z3Math::boolNot(shared_ptr<const SymbolicVar> opA) {
    sc_Z3Var a = dynamic_pointer_cast<const Z3Var>(opA);
    s_Z3Var resultPtr = s_Z3Var(new Z3Var(~a->e));
    return resultPtr;
}

// Is Satisfiable -> Still W.I.P.
bool Z3Math::isSat(shared_ptr<SymbolicVar> expr) {
    s_Z3Var zExpr = dynamic_pointer_cast<Z3Var>(expr);
    if(!zExpr)
        throw runtime_error("Z3Math: isSat, non-Z3Var input");

    solver s(cntxt);
    s.add(zExpr->e);

    switch (s.check()) {
        case unsat:   return false;
        case sat:     return true;
        case unknown: return true;
    }
    return true;
}

// Clears Any History
void Z3Math::clear() {}

