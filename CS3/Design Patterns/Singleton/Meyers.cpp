// Meyers singleton demonstration
#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::vector;

class SingletonMeyers {
public:
    static SingletonMeyers& instance() {
        static SingletonMeyers s;
        return s;
    }
    
    void addChar(char c) { payload_.push_back(c); }

    void print() {
        for(auto c : payload_) {
            cout << c << ' ';
        }
    }

private:
    // copy and creation prohibited
    SingletonMeyers(){}
    SingletonMeyers(const SingletonMeyers&){}
    SingletonMeyers& operator=(const SingletonMeyers&){}

    vector<char> payload_;
};

int main() {
    for(int i = 0; i < 10; ++i) {
        SingletonMeyers::instance().addChar('a');
    }

    // we use dot operator since instance() returns 
    // singleton reference instead of pointer
    SingletonMeyers::instance().addChar('\n');
    SingletonMeyers::instance().print();
}