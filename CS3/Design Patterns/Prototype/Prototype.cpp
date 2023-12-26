// Prototype Demonstration

enum class Type { TYPE1, TYPE2 };

class Prototype {
public:
    Prototype(Type type) : type_(type) {}

    void changeType(Type type) { type_ = type; }

    // clone() method
    // essential for prototype pattern
    virtual Prototype* clone() =0;

    virtual ~Prototype(){}
private:
    Type type_;
};

class Type1 : public Prototype {
public:
    Type1(Type type) : Prototype(type) {}

    // clone method with covariance
    Type1* clone() override {
        return new Type1(*this);
    }
};