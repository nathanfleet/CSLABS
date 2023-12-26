// State Design Pattern Demonstration

#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

class State; // forward declaration

// Context
class Car {
public:
    Car();

    // behaviors
    void ignitionON();
    void throttle();
    void brake();
    void ignitionOFF();

    int    getVin() const { return vin_; }
    string report();

    void changeState(State* state) { state_ = state; }
private:
    int vin_;
    State* state_;
};

// abstract state
class State {
public:
    virtual void ignitionON(Car*){}
    virtual void throttle(Car*){}
    virtual void brake(Car*){}
    virtual void ignitionOFF(Car*){}

    virtual string report(Car*) =0;

    void changeState(Car* car, State* state) { car->changeState(state); }
};

// concrete state
class Off : public State {
public:
    // singleton
    static State* instance() {
        static State* onlyInstance = new Off;
        return onlyInstance;
    }

    void ignitionON(Car* car) override final;
    string report(Car* car) override;
};

// concrete state
class Idle : public State {
public:
    static State* instance() {
        static State* onlyInstance = new Idle;
        return onlyInstance;
    }

    void ignitionOFF(Car* car) override final;
    void throttle(Car* car) override;
    string report(Car* car) override;
};

// concrete state
class Accelerating : public State {
public:
    static State* instance() {
        static State* onlyInstance = new Accelerating;
        return onlyInstance;
    }

    void brake(Car* car) override;
    string report(Car* car) override;
};

// concrete state
class Decelerating : public State {
public:
    static State* instance() {
        static State* onlyInstance = new Decelerating;
        return onlyInstance;
    }

    void throttle(Car* car) override;
    void brake(Car* car) override;
    string report(Car* car) override;
};

///////////////////////////////////////////////////////////////
// Car member functions
Car::Car() : vin_(++vin_) { state_ = Off::instance(); } 
void   Car::ignitionON()  { state_->ignitionON(this); }
void   Car::throttle()    { state_->throttle(this);   }
void   Car::brake()       { state_->brake(this);      }
void   Car::ignitionOFF() { state_->ignitionOFF(this);}
string Car::report()      { return state_->report(this); }

///////////////////////////////////////////////////////////////
// state transition member functions
// Off
void   Off::ignitionON(Car* car) { car->changeState(Idle::instance()); }
string Off::report(Car* car) { return "Car is: off \n"; }

// Idle
void   Idle::throttle(Car* car)    { car->changeState(Accelerating::instance()); }
void   Idle::ignitionOFF(Car* car) { car->changeState(Off::instance()); }
string Idle::report(Car* car)      { return "Car is: idling \n"; }

// Accelerating
void   Accelerating::brake(Car* car)  { car->changeState(Decelerating::instance()); }
string Accelerating::report(Car* car) { return "Car is: accelerating \n"; }

// Decelerating
void   Decelerating::throttle(Car* car) { car->changeState(Accelerating::instance()); }
void   Decelerating::brake(Car* car)    { car->changeState(Idle::instance()); }
string Decelerating::report(Car* car)   { return "Car is: decelerating \n"; }

int main() {
    Car* car = new Car();

    // car driving simulation
    cout << car->report();

    // turn the car on
    cout << "Turning the car on..." << endl;
    car->ignitionON();
    cout << car->report();

    // accelerate
    cout << "Getting on the throttle..." << endl;
    car->throttle();
    cout << car->report();

    // hit the brakes
    cout << "Breaking..." << endl;
    car->brake();
    cout << car->report();

    // speed up again
    cout << "Hitting the gas..." << endl;
    car->throttle();
    cout << car->report();

    // slow down
    cout << "Slowing down..." << endl;
    car->brake();
    cout << car->report();

    // come to a stop
    cout << "Coming to a stop..." << endl;
    car->brake();
    cout << car->report();

    // turn the car off
    cout << "Turning the car off..." << endl;
    car->ignitionOFF();
    cout << car->report();

    delete car;
    return 0;
}
