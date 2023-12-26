// demonstrates state design pattern
// Nathan Fleet
// 10/23/2023

#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;

class State;

// context
class Process{
public:
   Process();

   // behaviors
   void dispatch();
   void suspend ();
   void block   ();
   void unblock ();
   void exit    ();

   int getPID   ();
   string report();

   void changeState(State* state){ state_ = state; }

private:
   State* state_;
   int pid_;
   static int nextID_;
};

// absract state
class State{
public:
   virtual void dispatch(Process*){} 
   virtual void suspend (Process*){}
   virtual void block   (Process*){}
   virtual void unblock (Process*){}
   virtual void exit    (Process*){}

   virtual string report(Process*) =0;

   void changeState(Process* p, State* s){ p->changeState(s); }
};

class Ready: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Ready;
      return onlyInstance;
   }

   void dispatch(Process* p) override;
   string report(Process* p) override;
};

class Running: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Running;
      return onlyInstance;
   }

   void   suspend(Process* p) override;
   void   block  (Process* p) override;
   void   exit   (Process* p) override;
   string report (Process* p) override;
};

class Blocked: public State{
public:
   static State* instance(){
      static State* onlyInstance = new Blocked;
      return onlyInstance;
   }

   void   unblock(Process* p) override;
   string report (Process* p) override;
};

////////////////////////////////////////////////////////////////////////
// Process member functions
int    Process::nextID_ = 0;
Process::Process() : pid_(++nextID_) { state_ = Ready::instance(); }
void   Process::dispatch() { state_->dispatch(this); }
void   Process::suspend () { state_->suspend (this); }
void   Process::block   () { state_->block   (this); }
void   Process::unblock () { state_->unblock (this); }
void   Process::exit    () { state_->exit    (this); }
int    Process::getPID  () { return pid_; }
string Process::report  () { return state_->report(this); }

////////////////////////////////////////////////////////////////////////
// state transition member functions
// Ready
void Ready::dispatch(Process* p) {
   cout << "Dispatching..." << endl;
   changeState(p, Running::instance());
}
string Ready::report(Process* p) { return "Process " + std::to_string(p->getPID()) + " is ready"; }
////////////////////////////////////////////////////////////////////////
// Running
void Running::suspend(Process* p) {
   cout << "Suspending..." << endl;
   changeState(p, Ready::instance());
}
void Running::block  (Process* p) {
   cout << "Blocking..." << endl;
   changeState(p, Blocked::instance());
}
void Running::exit   (Process* p) {
   cout << "Exiting..." << endl;
   delete p;
}
string Running::report (Process* p) { return "Process " + std::to_string(p->getPID()) + " is running"; }
////////////////////////////////////////////////////////////////////////
// Blocked
void Blocked::unblock  (Process* p) {
   cout << "Unblocking..." << endl;
   changeState(p, Ready::instance());
}
string Blocked::report (Process* p) { return "Process " + std::to_string(p->getPID()) + " is blocked"; }

int main(){
   Process* process = new Process();

   cout << process->report() << endl;

   process->dispatch();
   process->exit(); // testing process destruction

   process = new Process(); // testing id incrementation
   cout << process->report() << endl;
   process->dispatch();
   cout << process->report() << endl;
   process->suspend();
   cout << process->report() << endl;
   process->dispatch();
   cout << process->report() << endl;
   process->block();
   cout << process->report() << endl;
   process->unblock();
   cout << process->report() << endl;
   process->dispatch();
   process->exit();
}