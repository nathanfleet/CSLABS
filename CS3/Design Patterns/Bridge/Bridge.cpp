#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

class Implementation {
public:
    virtual string OperationImplmentation() const = 0;
    ~Implementation() {}
};

class ConcreteImplementation1 : public Implementation {
public:
    string OperationImplmentation() const override {
        return "ConcreteImplementation1: this is the result for platform 1.";
    }
};

class ConcreteImplementation2 : public Implementation {

    string OperationImplmentation() const override {
        return "ConcreteImplementation2: this is the result for platform 2.";
    }
};

class Abstraction {
public:
    Abstraction(Implementation* implmentation) : implementation_(implmentation) {}

    virtual string Operation() const {
        return "Abstraction: Base operation with:\n" +
                this->implementation_->OperationImplmentation();
    }

    ~Abstraction() {}
protected:
    Implementation* implementation_;
};

// client
int main() {
    Implementation* implementation = new ConcreteImplementation1;
    Abstraction* abstraction = new Abstraction(implementation);

    cout << abstraction->Operation() << endl;

    delete implementation;
    delete abstraction;

    return 0;
}