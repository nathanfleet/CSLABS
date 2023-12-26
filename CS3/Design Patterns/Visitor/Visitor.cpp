// Visitor Demonstration

#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl;
using std::string; using std::vector;

// component
class Person {
public:
    Person(string name="John", Person* dad=nullptr, Person* mom=nullptr) :
    name_(name), dad_(dad), mom_(mom) {}

    const string& getName() const { return name_; }
    Person* getMom() const { return mom_; }
    Person* getDad() const { return dad_; }
    virtual void accept(class PersonVisitor*) =0;
private:
    const string name_;
    Person* dad_;
    Person* mom_;
};

class Man : public Person {
public:
    Man(string lastName) : lastName_(lastName) {}
    void accept(class PersonVisitor *visitor) override;
private:
    const string lastName_;
};

// abstract visitor
class PersonVisitor {
public:
    virtual void visit(Man*) =0;
};

void Man::accept(PersonVisitor* visitor) {
    visitor->visit(this);
}

// concrete visitor
class NamePrinter : public PersonVisitor {
public:
    void visit(Man* man) override {
        cout << man->getName() << endl;
    }
};

int main() {
    Man* man = new Man("Smith");
    NamePrinter* np = new NamePrinter;

    man->accept(np);

    delete man;
    return 0;
}