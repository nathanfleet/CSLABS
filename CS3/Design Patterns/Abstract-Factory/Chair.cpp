// Abstract Factory Demonstration

#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

// product interface
// aka Abstract Product (Chair)
class Chair {
public:
    string getType() const { return type_; }
protected:
    string type_;
};

// concrete product
class VictorianChair : public Chair {
public:
    VictorianChair() { type_ = "Victorian"; }
};

// concrete product
class ModernChair : public Chair {
public:
    ModernChair() { type_ = "Modern"; }
};

// Abstract Product (Sofa)
class Sofa {
public:
    string getType() const { return type_; }
protected:
    string type_;
};

// concrete product
class VictorianSofa : public Sofa {
public:
    VictorianSofa() { type_ = "Victorian"; }
};

// concrete product
class ModernSofa : public Sofa {
public:
    ModernSofa() { type_ = "Modern"; }
};

// Abstract Factory
class FurnitureFactory {
public:
    virtual Chair* requestChair() =0;
    virtual Sofa*  requestSofa()  =0;
    virtual ~FurnitureFactory(){}
protected:
    virtual Chair* makeChair() =0;
    virtual Sofa*  makeSofa()  =0;
};

class VictorianFactory : public FurnitureFactory {
public:
    Chair* requestChair() { return makeChair(); }
    Sofa*  requestSofa()  { return makeSofa();  }
protected:
    Chair* makeChair() override {
        return new VictorianChair();
    }

    Sofa* makeSofa() override {
        return new VictorianSofa();
    }
};

class ModernFactory : public FurnitureFactory {
public:
    Chair* requestChair() { return makeChair(); }
    Sofa*  requestSofa()  { return makeSofa();  }
protected:
    Chair* makeChair() override {
        return new ModernChair();
    }

    Sofa* makeSofa() override {
        return new ModernSofa();
    }
};

void VictorianClient(FurnitureFactory* f) {
    f->requestChair();
    f->requestSofa();
    cout << "Your victorian Furniture is ready!" << endl;

    delete f;
}

void ModernClient(FurnitureFactory* f) {
    Chair* chair = f->requestChair();
    Sofa* sofa = f->requestSofa();
    cout << "Your modern furniture is ready!" << endl;

    delete f;
}

int main() {
    VictorianFactory* vf = new VictorianFactory();
    ModernFactory* mf = new ModernFactory();

    VictorianClient(vf);
    ModernClient(mf);

    delete vf;
    delete mf;

    return 0;
}
