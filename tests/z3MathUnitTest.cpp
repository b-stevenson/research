#include<z3++.h>
#include<SSARI/ssari.h>
#include<gtest/gtest.h>
#include "z3Math.h"

using namespace z3;
using namespace std;
using namespace SSARI;

// Test Bool Greater Than
TEST(Z3Var, TestGT) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.gt(x, y);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
    operation.clear();
    expr = operation.gt(y, x);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
}

// Test Boolean Operations
// Greater than or Equal
TEST(Z3Var, TestGTE) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.gte(x, y);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
    operation.clear();
    expr = operation.gte(y, x);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
}
// Less than
TEST(Z3Var, TestLT) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.lt(x, y);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.lt(y, x);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}

// Less than or Equal
TEST(Z3Var, TestLTE) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.lte(x, y);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.lte(y, x);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}

// Equal
TEST(Z3Var, TestEQ) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.eq(x, y);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
    operation.clear();
    expr = operation.eq(x, x);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
}

// Not Equal
TEST(Z3Var, TestNEQ) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.neq(x, y);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.neq(x, x);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}


// Test Arithmetic Operations
// Addition
TEST(Z3Var, TestADD) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> sol = operation.set(CVar("sol") , operation.get(shared_ptr<CConstant>(new CConstant("14"))));
    shared_ptr<SymbolicVar> nSol = operation.set(CVar("nsol") , operation.get(shared_ptr<CConstant>(new CConstant("12"))));

    shared_ptr<SymbolicVar> result = operation.add(x, y);
    shared_ptr<SymbolicVar> expr = operation.eq(result, sol);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.eq(result, nSol);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}



// Subraction
TEST(Z3Var, TestSUB) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> sol = operation.set(CVar("sol") , operation.get(shared_ptr<CConstant>(new CConstant("-6"))));
    shared_ptr<SymbolicVar> nSol = operation.set(CVar("nsol") , operation.get(shared_ptr<CConstant>(new CConstant("12"))));

    shared_ptr<SymbolicVar> result = operation.sub(x, y);
    shared_ptr<SymbolicVar> expr = operation.eq(result, sol);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.eq(result, nSol);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}

// Multiplication
TEST(Z3Var, TestMUL) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> sol = operation.set(CVar("sol") , operation.get(shared_ptr<CConstant>(new CConstant("40"))));
    shared_ptr<SymbolicVar> nSol = operation.set(CVar("nsol") , operation.get(shared_ptr<CConstant>(new CConstant("12"))));

    shared_ptr<SymbolicVar> result = operation.mul(x, y);
    shared_ptr<SymbolicVar> expr = operation.eq(result, sol);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.eq(result, nSol);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}

// Division
TEST(Z3Var, TestDIV) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> sol = operation.set(CVar("sol") , operation.get(shared_ptr<CConstant>(new CConstant(".4"))));
    shared_ptr<SymbolicVar> nSol = operation.set(CVar("nsol") , operation.get(shared_ptr<CConstant>(new CConstant("12"))));

    shared_ptr<SymbolicVar> result = operation.div(x, y);
    shared_ptr<SymbolicVar> expr = operation.eq(result, sol);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.eq(result, nSol);
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}


// Test Logical Operations
// LogOr
TEST(Z3Var, TestlogOR) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> z = operation.set(CVar("z") , operation.get(shared_ptr<CConstant>(new CConstant("14"))));

    shared_ptr<SymbolicVar> expr = operation.logOr(operation.lt(x, y), operation.lt(y, x));
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.logOr(operation.lt(z, y), operation.lt(y, x));
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}

// LogAnd
TEST(Z3Var, TestlogAND) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<SymbolicVar> z = operation.set(CVar("z") , operation.get(shared_ptr<CConstant>(new CConstant("14"))));

    shared_ptr<SymbolicVar> expr = operation.logAnd(operation.lt(x, y), operation.lt(y, z));
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.logAnd(operation.lt(y, z), operation.lt(y, x));
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}

// LogNot
TEST(Z3Var, TestlogNOT) {
    Z3Math operation;
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.logNot(operation.lt(y, x));
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();
    expr = operation.logNot(operation.lt(x, y));
    operation.addClause(expr);
    EXPECT_EQ(operation.isSat(nullptr), false);
}

TEST(Z3Var, UniversalConst)
{
    Z3Math operation;
    shared_ptr<SymbolicVar> u = operation.set(CVar("U") , operation.get(shared_ptr<CUniversal>(new CUniversal())));
    shared_ptr<SymbolicVar> zero = operation.set(CVar("zero") , operation.get(shared_ptr<CConstant>(new CConstant("0"))));
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));

    shared_ptr<SymbolicVar> zeroConstraint = operation.lt(zero, u);
    operation.addClause(zeroConstraint);
    shared_ptr<SymbolicVar> resultOp = operation.add(u, x);
    shared_ptr<SymbolicVar> resultConstraint = operation.lt(zero, resultOp);
    operation.addClause(resultConstraint);
    EXPECT_EQ(operation.isSat(nullptr), true);
    operation.clear();

    resultConstraint = operation.lt(resultOp, zero);
    operation.addClause(zeroConstraint);
    operation.addClause(resultConstraint);
    EXPECT_EQ(operation.isSat(nullptr), false);
}

