// Singleton with atExit demonstration

#include <iostream>

using std::cout; using std::endl;

class Singleton {
public:
    static Singleton* instance();

    int getPayload() { return payload_; }
    void setPayload(int payload) { payload_ = payload; }

    Singleton(const Singleton&) = delete; // copy ctor prohibited
    Singleton& operator=(const Singleton&) = delete;
private:
    Singleton();
    static void cleanUp();
    static Singleton* instance_;
    int payload_;
};

Singleton* Singleton::instance_ = nullptr;

Singleton* Singleton::instance() {
    if(instance_ == nullptr) {
        instance_ = new Singleton();
    }
    return instance_;
}

#include <cstdlib>

// registering behavior at program shutdown
Singleton::Singleton(){atexit(cleanUp);}

void Singleton::cleanUp() {
    cout << "Cleaning stuff up" << endl;
    delete instance_;
    instance_ = nullptr;
}


int main() {
    Singleton::instance()->setPayload(69);
    cout << Singleton::instance()->getPayload() << endl;

    Singleton *s = Singleton::instance();

    s->setPayload(70);
    cout << s->getPayload() << endl;
}