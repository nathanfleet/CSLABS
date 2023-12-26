// Chain of Responsibility Demonstration

#include <iostream>

using std::cout; using std::endl;

// abstract class that sets up individual links in the
// chain of responsibility (Abstract Handler)
class Soldier {
public:
    Soldier(Soldier* successor) : successor_(successor) {}
    virtual void handleRequest(int amt) {
        if(successor_ != nullptr) {
            successor_->handleRequest(amt);
        } else {
            cout << "Nobody can handle this request" << endl;
        }
    }
private:
    Soldier* successor_;
};

// concrete handlers
class Rank1 : public Soldier {
public:
    Rank1(Soldier* successor=nullptr) : Soldier(successor) {}
    void handleRequest(int amt) override {
        if(amt < 100) {
            cout << "Soldier Rank1 can handle this request" << endl;
        } else {
            Soldier::handleRequest(amt);
        }
    }
};

class Rank2 : public Soldier {
public:
    Rank2(Soldier* successor=nullptr) : Soldier(successor) {}
    void handleRequest(int amt) {
        if(amt < 1000) {
            cout << "Soldier Rank2 can handle this request" << endl;
        } else {
            Soldier::handleRequest(amt);
        }
    }
};

int main() {
    Soldier* soldier = new Rank1(new Rank2);

    soldier->handleRequest(50);
    soldier->handleRequest(500);
    soldier->handleRequest(5000);

    delete soldier;
    return 0;
}