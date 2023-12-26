// Template Method Demonstration

#include <iostream>

using std::cout; using std::endl;

class Algorithm {
public:
    // template method
    void TemplateMethod() {
        int a = add();
        int b = subtract();

        int result;
        if(addOrSubtract()) {
            result = a+b;
        } else {
            result = a-b;
        }
        cout << "The result of the algorithm (template method) is: "
             << std::to_string(result) << endl;
    }

protected:
    // primitive operations
    virtual int add() =0;
    virtual int subtract() =0;

    // hook
    virtual bool addOrSubtract() { return true; }
};

class Addition : public Algorithm {
    int add() override { return 2 + 2; }
    int subtract() override { return 4 - 2; }

    // no need to override hook in this case
    // bool addOrSubtract() override { return true; }
};

class Subtraction : public Algorithm {
public:
    int add() override { return 2 + 2; }
    int subtract() override { return 4 - 2; }

    // "hooking" in
    bool addOrSubtract() override { return false; }
};

int main() {
    Algorithm* alg = new Addition;

    cout << "Addition algorithm: " << endl;
    alg->TemplateMethod();
    
    cout << "Subtraction algorithm: " << endl;
    alg = new Subtraction;
    alg->TemplateMethod();

    delete alg;
    return 0;
}