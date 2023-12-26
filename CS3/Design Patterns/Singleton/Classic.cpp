// classic singleton demonstration

class Singleton {
public:
    static Singleton* instance();

    int  getPayload()            { return payload_;    }
    void setPayload(int payload) { payload_ = payload; }
private:
    // creation and copying prohibited
    Singleton(){}
    Singleton(const Singleton&){}
    Singleton& operator=(const Singleton*){}

    // maintains pointer to its only instance
    static Singleton* onlyInstanceInt_;

    // payload
    int payload_;
};

Singleton* Singleton::onlyInstanceInt_ = nullptr;

// returns pointer to singleton instance
Singleton* Singleton::instance() {
    if(onlyInstanceInt_ == nullptr) {
        onlyInstanceInt_ = new Singleton;
    }
    return onlyInstanceInt_;
}

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main() {
    // Singleton singleton; <-- wrong

    // arrow operator is used because instance() returns
    // pointer to singleton instance
    Singleton::instance()->setPayload(69);

    cout << "Current payload: " << Singleton::instance()->getPayload() << endl;

    Singleton *s = Singleton::instance();
    s->setPayload(70);

    cout << "Current payload: " << Singleton::instance()->getPayload() << endl;
}