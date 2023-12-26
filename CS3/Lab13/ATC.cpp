// mediator-based air traffic control
// Nathan Fleet
// 11/14/2023

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <map>

// for timed sleep
#include <thread>
#include <chrono>

using std::cout; using std::cin; using std::endl;
using std::string;

enum class airline { AirFrance, KLM, Aeroflot, Lufthansa, Delta, United, JetBlue };

// abstract flywight
class Airline {
public:
    virtual string image() = 0;
};

// Concrete flyweights
class AirFrance : public Airline {
public:
    string image() override { return "AIRFRANCE"; }
};

class KLM : public Airline {
public:
    string image() override { return "KLM"; }
};

class Aeroflot : public Airline {
public:
    string image() override { return "AEROFLOT"; }
};

class Lufthansa : public Airline {
public:
    string image() override { return "LUFTHANSA"; }
};

class Delta : public Airline {
public:
    string image() override { return "DELTA"; }
};

class United : public Airline {
public:
    string image() override { return "UNITED"; }
};

class JetBlue : public Airline {
public:
    string image() override { return "JETBLUE"; }
};

// factory
class Hangar {
public:
    static Airline *makeAirline(airline a) {
        if(airlines_.find(a) == airlines_.end()) {
            switch(a) {
            case airline::AirFrance: airlines_[a] = new AirFrance; break;
            case airline::KLM:       airlines_[a] = new KLM;       break;
            case airline::Aeroflot:  airlines_[a] = new Aeroflot;  break;
            case airline::Lufthansa: airlines_[a] = new Lufthansa; break;
            case airline::Delta:     airlines_[a] = new Delta;     break;
            case airline::United:    airlines_[a] = new United;    break;
            case airline::JetBlue:   airlines_[a] = new JetBlue;   break;
            }
        }
        return airlines_[a];
    }
private:
    static std::map<airline, Airline*> airlines_;
};

std::map<airline, Airline*> Hangar::airlines_;

// abstract mediator
class Controller{
public:
    virtual void join(class Flight*)=0;
    virtual void leave(class Flight*)=0;
    virtual void broadcast() = 0;
    virtual void observe() = 0;
};

// concrete mediator
// tower, runway clearance
class Tower: public Controller{
public:
    void join(class Flight*) override; 
    void leave(class Flight*) override;
    void broadcast() override;
    void observe() override;
private:
    std::set<class Flight*> waiting_;
};

// abstract colleague
class Flight {
public:
    Flight(Controller *controller):controller_(controller), status_(Status::waiting){
        task_ = rand() % 2 ? Task::taxiing : Task::approaching;
        controller_->join(this);
    }

    void receive(const string &msg){
        if (msg.find(flightNo_) != string::npos || msg.find("all") != string::npos){
            if(msg.find("clear") != string::npos){
                cout << flightNo_ << " roger that, ";
                cout << (task_ == Task::taxiing ? "taking off" : "landing") << endl;
                // display logo
                if(task_ == Task::taxiing) {
                    cout << "..." << logo_->image() << " takes off..." << endl;
                } else {
                    cout << "..." << logo_->image() << " lands..." << endl;
                }
                status_ = Status::cleared;
            } else if(msg.find("status") != string::npos) {
                cout << flightNo_
                     << (status_ == Status::waiting ? " waiting to " : " cleared to ")   
                     << (task_ == Task::taxiing ? "take off" : "land") << endl;
            } else
                cout << "Tower, this is " << flightNo_ << " please repeat." << endl;
        }
    }

    bool isCleared() const {return status_ == Status::cleared;}

    void proceed(){
        std::this_thread::sleep_for(std::chrono::seconds(rand()%3+1)); // wait a while    
        cout << flightNo_
             << (task_ == Task::taxiing ? " took off" : " landed")
             << ". Have a good day!" << endl; 
        controller_->leave(this);
    }

protected:
    Airline *logo_; //extrinsic state
    string flightNo_;
    Controller *controller_;
    enum class Task {taxiing, approaching};  Task task_;
    enum class Status {waiting, cleared};    Status status_;
};

// concrete colleagues
class Airbus: public Flight{
public:
    Airbus(Tower *tower): Flight(tower){
        static const std::vector<string> companies = {"AirFrance", "KLM", "Aeroflot", "Lufthansa"};

        string company = companies[rand() % companies.size()];

        // assign logo
        if(company == "AirFrance") {
            logo_ = Hangar::makeAirline(airline::AirFrance);
        } else if(company == "KLM") {
            logo_ = Hangar::makeAirline(airline::KLM);
        } else if(company == "Aeroflot") {
            logo_ = Hangar::makeAirline(airline::Aeroflot);
        } else {
            logo_ = Hangar::makeAirline(airline::Lufthansa);
        }

        flightNo_ = company + std::to_string(rand() % 1000);
        cout << flightNo_ << " requesting "
             << (task_ == Task::taxiing ? "takeoff" : "landing") << endl;
    }
};

class Boeing: public Flight{
public:
    Boeing(Tower *tower): Flight(tower){
        static const std::vector<string> companies = {"Delta", "United", "JetBlue"};

        string company = companies[rand() % companies.size()];

        // assign logo
        if(company == "Delta") {
            logo_ = Hangar::makeAirline(airline::Delta);
        } else if(company == "United") {
            logo_ = Hangar::makeAirline(airline::United);
        } else {
            logo_ = Hangar::makeAirline(airline::JetBlue);
        }

        flightNo_ = company + std::to_string(rand() % 1000);
        cout << flightNo_ << " requesting "
             << (task_ == Task::taxiing ? "takeoff" : "landing") << endl;
    }
};

// member functions for Tower
void Tower::broadcast() {
    cout << "Tower: ";
    string msg;
    getline(cin,msg);
    if(!msg.empty()) {
        for(auto f: waiting_) {
            f->receive(msg);
        }
    }
}

void Tower::observe() {
    auto findCleared = [](Flight *f){return f->isCleared();};

    auto toProceed = std::find_if(waiting_.begin(),waiting_.end(), findCleared);

    while (toProceed != waiting_.end()){ // found a cleared flight
        (*toProceed) -> proceed();
        toProceed = std::find_if(waiting_.begin(), waiting_.end(), findCleared);
        if(toProceed != waiting_.end()) {
            cout << "MAYDAY! MAYDAY! MAYDAY! " << endl; // more than a single flight cleared
        }
    }
}

void Tower::join(Flight *f) {
    waiting_.insert(f);
}


void Tower::leave(Flight *f) {
    waiting_.erase(f);
    delete f;
}

int main(){
    srand(time(nullptr));
    Tower jfk;

    new Boeing(&jfk);
    new Airbus(&jfk);
    new Boeing(&jfk);
    new Airbus(&jfk);

    while(true){
        jfk.broadcast();
        jfk.observe();
        if(rand() % 2){
            if (rand() % 2) {
                new Boeing(&jfk);
            } else {
                new Airbus(&jfk);
            }
        }
    }
}