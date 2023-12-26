// Flyweight Demonstration

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <set>
#include <vector>

using std::string;
using std::cout; using std::endl;

enum class rank { lieutenant, captain, major, general };

// abstract flyweight
class Rank {
public:
    virtual string image() =0;
};

// concrete flyweight
class Lieutenant : public Rank {
public:
    string image() override { return "*"; }
};

// concrete flyweight
class Captain : public Rank {
public:
    string image() override { return "**"; }
};

// concrete flyweight
class Major : public Rank {
public:
    string image() override { return "***"; }
};

// concrete flyweight
class General : public Rank {
public:
    string image() override { return "****"; }
};

// factory
class Academy {
public:
    static Rank* makeRank(rank r) {
        if(ranks_.find(r) == ranks_.end()) {
            switch(r) {
            case rank::lieutenant: ranks_[r] = new Lieutenant; break;
            case rank::captain:    ranks_[r] = new Captain; break;
            case rank::major:      ranks_[r] = new Major; break;
            case rank::general:    ranks_[r] = new General; break;
            }
        }
        return ranks_[r];
    }
private:
    static std::map<rank, Rank*> ranks_;
};

std::map<rank, Rank*> Academy::ranks_;

// client with extrinsic state
class Officer {
public:
    Officer(string name, rank r) : name_(name) {
        rank_ = Academy::makeRank(r);
    }
    void report() const {
        cout << name_ << " " << rank_->image() << endl;
    }
    void promote(rank r) {
        rank_ = Academy::makeRank(r);
    }
    friend bool operator<(const Officer& lhs, const Officer& rhs) {
        return lhs.name_ < rhs.name_;
    }
private:
    const string name_;
    Rank* rank_;
};

int main() {
    std::set<Officer> troops = {
        Officer("Nathan Smith", rank::lieutenant),
        Officer("Adam Eve", rank::captain),
        Officer("Connor Fart", rank::major),
        Officer("Jared Turd", rank::lieutenant),
    };

    for(const auto &e : troops) {
        e.report();
    }

    std::cout << "\nPromote everyone\n";

    std::set<Officer> generals;

    std::transform(
        troops.begin(), troops.end(),
        std::inserter(generals, generals.end()),
        [](Officer o){o.promote(rank::general); return o;}
    );

    for(const auto &e : troops) {
        e.report();
    }

    return 0;
}