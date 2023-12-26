// Strategy Demonstration (push)

#include <iostream>
using std::cout; using std::endl;

// abstract strategy
class Strategy {
public:
    virtual void execute() const =0;
};

class ConcreteStrategy : public Strategy {
public:
    void execute() const override {
        cout << "Executing concrete strategy" << endl;
    }
};

// context using the strategies
class Context {
public:
    Context(Strategy* strategy) : strategy_(strategy) {}
    void setStrategy(Strategy* strategy) { strategy_ = strategy; }
    void execute() const { strategy_->execute(); }
private:
    Strategy* strategy_;
};

int main() {
    ConcreteStrategy cs;
    Context context(&cs);

    context.execute();

    return 0;
}