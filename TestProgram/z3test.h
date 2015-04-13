#ifndef Z3TEST_H
#define Z3TEST_H
class z3Math: public SymbolicVar {
public:
    z3Math(string varName) : varName(varName) { }
    string toString() const {return this->varName; }
    string getName() const { return this->varName; }


private:
    expr e;
};
#endif // Z3TEST_H
