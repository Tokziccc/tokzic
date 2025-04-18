#include <string>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

struct Expression {
    virtual ~Expression() = default;
    virtual double evaluate() const = 0;
};

struct Number : Expression {
    Number(double value) : value_(value) {}
    double evaluate() const override { return value_; }
private:
    double value_;
};

struct BinaryOperation : Expression {
    enum { PLUS = '+', MINUS = '-', DIV = '/', MUL = '*' };

    BinaryOperation(Expression const* left, int op, Expression const* right)
        : left_(left), op_(op), right_(right) {
        assert(left_ && right_);
    }

    ~BinaryOperation() override {
        delete left_;
        delete right_;
    }

    double evaluate() const override {
        double left = left_->evaluate();
        double right = right_->evaluate();
        switch (op_) {
        case PLUS: return left + right;
        case MINUS: return left - right;
        case DIV: return left / right;
        case MUL: return left * right;
        }
        assert(0);
        return 0.0;
    }
private:
    Expression const* left_;
    Expression const* right_;
    int op_;
};

struct FunctionCall : Expression {
    FunctionCall(const string& name, Expression const* arg)
        : name_(name), arg_(arg) {
        assert(arg_ != nullptr);
        assert(name == "sqrt" || name == "abs");
    }

    ~FunctionCall() override {
        delete arg_;
    }

    double evaluate() const override {
        double value = arg_->evaluate();
        if (name_ == "sqrt") return sqrt(value);
        if (name_ == "abs") return fabs(value);
        assert(0);
        return 0.0;
    }

    string const& name() const { return name_; }
    Expression const* arg() const { return arg_; }

private:
    string name_;
    Expression const* arg_;
};

int main() {
    Expression* e1 = new Number(1.234);
    Expression* e2 = new Number(-1.234);
    Expression* e3 = new BinaryOperation(e1, BinaryOperation::DIV, e2);

    cout << "1: " << e3->evaluate() << endl;  

    delete e3;  

    Expression* n32 = new Number(32.0);
    Expression* n16 = new Number(16.0);
    Expression* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
    Expression* callSqrt = new FunctionCall("sqrt", minus);
    Expression* n2 = new Number(2.0);
    Expression* mult = new BinaryOperation(n2, BinaryOperation::MUL, callSqrt);
    Expression* callAbs = new FunctionCall("abs", mult);

    cout << "2: " << callAbs->evaluate() << endl; 

    delete callAbs; 

    return 0;
}