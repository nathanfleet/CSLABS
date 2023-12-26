// picking the best quality lemons
// converting vectors to priority queue
// Nathan Fleet
// 9/25/2023

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue> // for priority queue

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
using std::priority_queue;

struct Lemon {
    double quality;
    friend bool operator<(const Lemon& left, const Lemon& right) {
        return left.quality < right.quality;
    }
};

const int maxBoxSize = 30;
const int highestQuality = 10;

int main() {
    srand(time(nullptr));
    // Template type: Lemon
    // Container type: deque
    // Compare: std::less ... since operator< is defined, will cause highest quality to be at the top
    priority_queue <Lemon, std::deque<Lemon>, std::less<Lemon>> box;

    // random quality assignment
    // adding random number of lemons to box
    for(int i = 0; i < (rand() % maxBoxSize + 1); ++i) {
        Lemon lemon;
        lemon.quality = static_cast<double>(rand()) / RAND_MAX * highestQuality;
        box.push(lemon);
    }

    cout << "Here are the lemons (best first): ";

    // displaying the lemons in order of quality (best first)
    // using priority queue
    while (!box.empty())  {
        cout << box.top().quality;
        box.pop();
        if(!box.empty()) cout << ", ";
    }

    cout << endl;
}
