// example opening file for appending with singleton logger
// Nathan Fleet
// 10/13/2023

#include <fstream>
#include <string>
#include <iostream>

using std::cout; using std::cin; using std::endl;
using std::string;

void beginLog();
void endLog();

class Logger {
public:
   // creates instance upon invocation, otherwise
   // returns existing instance
   static Logger& instance() {
      static Logger log;
      return log;
   }

   void report(const string &message) {
      if(file.is_open()) {
         file << message;
      }
   }


private:
   // private constructor invoked on creation of first instance
   Logger() {
      file.open("log.txt", std::fstream::out | std::fstream::app);
   }

   ~Logger() {
      if(file.is_open()) {
         file.close();
      }
   }

   // copy and assignment disallowed
   Logger(const Logger&);
   Logger& operator=(const Logger&);

   // payload
   std::ofstream file;
};

int main () {
   beginLog();

   // testing copy and creationg (disallowed)
   // Logger log1 = Logger::instance();
   // Logger log2;

   for(int i = 1; i <= 10; ++i) {
      Logger::instance().report("Message\n");
   }

   endLog();
}

void beginLog() {
   Logger::instance().report("Beginning log...\n");
}

void endLog() {
   Logger::instance().report("End of log.");
}