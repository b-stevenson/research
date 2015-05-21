#include<z3++.h>
#include<SSARI/ssari.h>
#include<gtest/gtest.h>
#include "z3Math.h"

using namespace z3;
using namespace std;
using namespace SSARI;

// Test Bool Greater Than
TEST(Z3Var, TestGT) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.gt(x, y);
    EXPECT_EQ(operation.isSat(expr), false);
    operation.clear();
    expr = operation.gt(y, x);
    EXPECT_EQ(operation.isSat(expr), true);
}

// Test Boolean Operations
// Greater than or Equal
TEST(Z3Var, TestGTE) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.gte(x, y);
    EXPECT_EQ(operation.isSat(expr), false);
    operation.clear();
    expr = operation.gte(y, x);
    EXPECT_EQ(operation.isSat(expr), true);
}
// Less than
TEST(Z3Var, TestLT) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.lt(x, y);
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.lt(y, x);
    EXPECT_EQ(operation.isSat(expr), false);
}

// Less than or Equal
TEST(Z3Var, TestLTE) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.lte(x, y);
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.lte(y, x);
    EXPECT_EQ(operation.isSat(expr), false);
}

// Equal
TEST(Z3Var, TestEQ) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.eq(x, y);
    EXPECT_EQ(operation.isSat(expr), false);

    expr = operation.eq(x, x);
    EXPECT_EQ(operation.isSat(expr), true);
}

// Not Equal
TEST(Z3Var, TestNEQ) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.neq(x, y);
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.neq(x, x);
    EXPECT_EQ(operation.isSat(expr), false);
}


// Test Arithmetic Operations
// Addition
TEST(Z3Var, TestADD) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> sol = operation.set(CVar("sol") , operation.get(shared_ptr<CConstant>(new CConstant("14"))));
    shared_ptr<SymbolicVar> nSol = operation.set(CVar("nsol") , operation.get(shared_ptr<CConstant>(new CConstant("12"))));

    shared_ptr<SymbolicVar> result = operation.add(x, y);
    shared_ptr<SymbolicVar> expr = operation.eq(result, sol);
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.eq(result, nSol);
    EXPECT_EQ(operation.isSat(expr), false);
}



// Subraction
TEST(Z3Var, TestSUB) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> sol = operation.set(CVar("sol") , operation.get(shared_ptr<CConstant>(new CConstant("-6"))));
    shared_ptr<SymbolicVar> nSol = operation.set(CVar("nsol") , operation.get(shared_ptr<CConstant>(new CConstant("12"))));

    shared_ptr<SymbolicVar> result = operation.sub(x, y);
    shared_ptr<SymbolicVar> expr = operation.eq(result, sol);
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.eq(result, nSol);
    EXPECT_EQ(operation.isSat(expr), false);
}

// Multiplication
TEST(Z3Var, TestMUL) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> sol = operation.set(CVar("sol") , operation.get(shared_ptr<CConstant>(new CConstant("40"))));
    shared_ptr<SymbolicVar> nSol = operation.set(CVar("nsol") , operation.get(shared_ptr<CConstant>(new CConstant("12"))));

    shared_ptr<SymbolicVar> result = operation.mul(x, y);
    shared_ptr<SymbolicVar> expr = operation.eq(result, sol);
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.eq(result, nSol);
    EXPECT_EQ(operation.isSat(expr), false);
}

// Division
TEST(Z3Var, TestDIV) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> sol = operation.set(CVar("sol") , operation.get(shared_ptr<CConstant>(new CConstant(".4"))));
    shared_ptr<SymbolicVar> nSol = operation.set(CVar("nsol") , operation.get(shared_ptr<CConstant>(new CConstant("12"))));

    shared_ptr<SymbolicVar> result = operation.div(x, y);
    shared_ptr<SymbolicVar> expr = operation.eq(result, sol);
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.eq(result, nSol);
    EXPECT_EQ(operation.isSat(expr), false);
}


// Test Logical Operations
// LogOr
TEST(Z3Var, TestlogOR) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> z = operation.set(CVar("z") , operation.get(shared_ptr<CConstant>(new CConstant("14"))));

    shared_ptr<SymbolicVar> expr = operation.logOr(operation.lt(x, y), operation.lt(y, x));
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.logOr(operation.lt(z, y), operation.lt(y, x));
    EXPECT_EQ(operation.isSat(expr), false);
}

// LogAnd
TEST(Z3Var, TestlogAND) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> z = operation.set(CVar("z") , operation.get(shared_ptr<CConstant>(new CConstant("14"))));

    shared_ptr<SymbolicVar> expr = operation.logAnd(operation.lt(x, y), operation.lt(y, z));
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.logAnd(operation.lt(y, z), operation.lt(y, x));
    EXPECT_EQ(operation.isSat(expr), false);
}

// LogNot
TEST(Z3Var, TestlogNOT) {
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.logNot(operation.lt(y, x));
    EXPECT_EQ(operation.isSat(expr), true);

    expr = operation.logNot(operation.lt(x, y));
    EXPECT_EQ(operation.isSat(expr), false);
}

TEST(Z3Var, UniversalConst)
{
    context c;
    Z3Math operation(c);
    shared_ptr<SymbolicVar> u = operation.set(CVar("U") , operation.get(shared_ptr<CUniversal>(new CUniversal())));
    shared_ptr<SymbolicVar> zero = operation.set(CVar("zero") , operation.get(shared_ptr<CConstant>(new CConstant("0"))));
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));


    shared_ptr<SymbolicVar> constraint = operation.lt(zero, y);
    shared_ptr<SymbolicVar> resultOp = operation.add(constraint, x);
    shared_ptr<SymbolicVar> sol = operation.eq(resultOp, y);
    EXPECT_EQ(operation.isSat(sol), true);

    constraint = operation.lt(u, zero);
    resultOp = operation.add(constraint, x);
    sol = operation.eq(resultOp, y);
    EXPECT_EQ(operation.isSat(sol), false);
}

