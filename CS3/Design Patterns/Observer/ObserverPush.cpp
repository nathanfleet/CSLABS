// Observer (push) Demonstration

#include <unordered_set>
#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

// abstract observer
// define notification mechanism
class Observer {
public:
    // elaborated type specifier
    Observer(class Subject* s);
    virtual void notify(const string&) const =0;
};

// abstract subject
// define subscription mechanism
class Subject {
public:
    void deregisterObserver(Observer* o) { views_.erase(o); }
    void registerObserver(Observer* o) { views_.insert(o); }
    void notifyObservers(const string& data) const {
        for(auto e : views_) {
            e->notify(data);
        }
    }
private:
    std::unordered_set<Observer*> views_;
};

Observer::Observer(Subject* s) { s->registerObserver(this); }

class ConcreteSubject;

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const string&, ConcreteSubject*);
    void notify(const string& data) const override;
private:
    string name_;
    ConcreteSubject* s_;
};

class ConcreteSubject : public Subject {
public:
    ConcreteSubject(const string& name) : name_(name) {}
    void changeName(const string& name) { name_ = name; notifyObservers(name_); }
    const string& getName() const { return name_; }
private:
    string name_;
};

ConcreteObserver::ConcreteObserver
(const string& name, ConcreteSubject* s) 
: name_(name), s_(s), Observer(static_cast<Subject*>(s)) {}

void ConcreteObserver::notify(const string& data) const {
    cout << "observer " << name_ << " reports "
         << "subject changed name to: "
         << data << endl;
}

int main() {
    ConcreteSubject  subject("Nathan");
    ConcreteObserver observer("Jared", &subject);

    subject.changeName("Lucy");
}