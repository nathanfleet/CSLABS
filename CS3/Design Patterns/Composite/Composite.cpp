// Composite demonstration

#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

// component
// abstract uniform interface class
class Expression {
public:
    virtual int evaluate() =0;
    virtual string print() =0;
    virtual ~Expression(){}
};

// leaf
class Number : public Expression {
public:
    Number(int value) : value_(value) {}
    int evaluate() override { return value_; }
    string print() override { return std::to_string(value_); }
private:
    int value_;
};

// composite
class Add : public Expression {
public:
    Add(Expression* left, Expression* right) :
    left_(left), right_(right) {}

    int evaluate() override {
        return left_->evaluate() + right_->evaluate();
    }

    string print() override {
        return '[' + left_->print() + '+' + right_->print() + ']';
    }
private:
    Expression* left_;
    Expression* right_;
};

int main() {
    Expression* e = new Number(2);
    Expression* a = new Number(4);

    Expression* add = new Add(e, a);
    cout << add->print() << endl;

    delete e;
    delete a;
    delete add;

    return 0;
}