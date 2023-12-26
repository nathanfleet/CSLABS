// Observer (registry) Demonstration

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout; using std::endl;
using std::map; using std::set;
using std::string;

class Observer;
class Subject;

class EventRegistry {
public:
    static void registerObserver(Subject*, Observer*);
    static void deregisterObserver(Subject*, Observer*);
    static void handleMessage(Subject*);
private:
    // observer map uses subject pointer as key
    // and set of observer pointer as value
    // therefore each subject has a record of its observers
    static map<Subject*, set<Observer*>> observerMap_;
};

map<Subject*, set<Observer*>> EventRegistry::observerMap_;

class Observer {
public:
    Observer(const string& name) : name_(name) {}
    string getName() const { return name_; }
    void subscribe(Subject* s) { EventRegistry::registerObserver(s, this); }
    void unsubscribe(Subject* s) { EventRegistry::deregisterObserver(s, this); }
    void handleMessage(Subject*);
private:
    string name_;
};

class Subject {
public:
    Subject(const string& name) : name_(name) {}
    string getName() const { return name_; }
    void generateMessage() {
        cout << name_ << " sent a message" << endl;
        EventRegistry::handleMessage(this);
    }
private:
    string name_;
};

void EventRegistry::registerObserver(Subject* s, Observer* o) {
    observerMap_[s].insert(o);
    cout << o->getName() << " subscribed to " << s->getName() << endl;
}

void EventRegistry::deregisterObserver(Subject* s, Observer* o) {
    observerMap_[s].erase(o);
    cout << o->getName() << " unsubscribed from " << s->getName() << endl;
}

void EventRegistry::handleMessage(Subject* s) {
    for(auto e : observerMap_[s]) {
        e->handleMessage(s);
    }
}

void Observer::handleMessage(Subject* s) {
    cout << name_ << " received message from " << s->getName() << endl;
}

int main() {
    Subject subject("Nathan");
    Observer observer("Jared");

    observer.subscribe(&subject);

    cout << endl;

    subject.generateMessage();

    cout << endl;

    observer.unsubscribe(&subject);

    return 0;
}