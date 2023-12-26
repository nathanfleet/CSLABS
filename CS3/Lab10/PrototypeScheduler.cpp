// prototype example w/covariance turned Prototype Scheduler for Lab 10
// Nathan Fleet
// 10/24/2023

#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>

using std::cout; using std::endl;
using std::string; using std::queue;

enum class State {READY, RUNNING, BLOCKED, EXITED};

class ProcessPrototype {
public:
   ProcessPrototype(State state) : state_(state) {}

   virtual void exit    () = 0;
   virtual void block   () = 0;
   virtual void unblock () = 0;
   virtual void suspend () = 0;
   virtual void dispatch() = 0;

   virtual ProcessPrototype* clone() = 0;

   virtual string report() = 0;

   int getPID() { return pid_; }
   void changeState(State state) { state_ = state; }

   virtual ~ProcessPrototype(){}
protected:
   State state_;
   int pid_;
   static int nextID_;
};

int ProcessPrototype::nextID_ = 1;

class Process: public ProcessPrototype {
public:
   Process(State state) : ProcessPrototype(state) { pid_ = nextID_++; }
   
   void exit     () override { if(state_ == State::RUNNING) {
      cout << "Exiting..." << endl;
      changeState(State::EXITED);
      // could not figure out how to 'destroy' the process as in StateTransition.cpp
      // opted to create a new State 'EXITED'
   }}
   void block    () override { if(state_ == State::RUNNING) { 
      cout << "Blocking..." << endl;
      changeState(State::BLOCKED);
   }}
   void unblock  () override { if(state_ == State::BLOCKED) {
      cout << "Unblocking..." << endl;
      changeState(State::READY);
   }}
   void suspend  () override { if(state_ == State::RUNNING) { 
      cout << "Suspending..." << endl;
      changeState(State::READY);
   }}
   void dispatch () override { if(state_ == State::READY)   { 
      cout << "Dispatching..." << endl;
      changeState(State::RUNNING);
   }}

   string report()  override { 
      string state;

      if(state_ == State::READY) {
         state = "READY";
      } else if(state_ == State::RUNNING) {
         state = "RUNNING";
      } else if(state_ == State::BLOCKED) {
         state = "BLOCKED";
      } 

      // this was in order to match example output
      if(state_ == State::EXITED) {
         return "PID " + std::to_string(getPID()) + ": exited"; 
      } else {
         return "PID " + std::to_string(getPID()) + " state: " + state; 
      }
   }

   Process* clone() override { return new Process(state_); }
};

int main() {
   srand(time(nullptr));

   queue<Process*> ready;
   queue<Process*> blocked;

   // setting up prototype
   Process* prototype = new Process(State::READY);
   cout << "PID " << prototype->getPID() << ": created" << endl;
   ready.push(prototype);
   cout << prototype->report() << endl;

   // setting up clones
   for(int i = 1; i < 4; ++i) {
      Process* process = prototype->clone();
      cout << "PID " << process->getPID() << ": created" << endl;
      ready.push(process);
      cout << process->report() << endl;
   }

   cout << endl << "---------- scheduler running ----------" << endl;

   while(!ready.empty()) {
      ready.front()->dispatch();
      cout << ready.front()->report() << endl;

      // 33% chance of exiting, suspending, or blocking
      int transition = rand() % 3;

      if(transition == 0) {
         ready.front()->exit();
         cout << ready.front()->report() << endl << endl;
         ready.pop();
      } else if(transition == 1) {
         ready.front()->suspend();
         cout << ready.front()->report() << endl << endl;
         ready.push(ready.front());
         ready.pop();
      } else if(transition == 2) {
         ready.front()->block();
         cout << ready.front()->report() << endl << endl;
         blocked.push(ready.front());
         ready.pop();
      }

      // with some probability, blocked process will become ready again (75%)
      if(!blocked.empty() && rand() % 100 > 25) {
         blocked.front()->unblock();
         cout << blocked.front()->report() << endl << endl;
         ready.push(blocked.front());
         blocked.pop();
      }
   }

   cout << "The ready queue is empty" << endl << endl;

   // allow remaining processes to run and exit
   while(!blocked.empty()) {
      blocked.front()->unblock();
      cout << blocked.front()->report() << endl << endl;
      blocked.front()->dispatch();
      cout << blocked.front()->report() << endl;
      blocked.front()->exit();
      cout << blocked.front()->report() << endl << endl;
      blocked.pop();
   }

   cout << "all processes exited." << endl;

   cout << "---------- scheduler done ----------" << endl;
}