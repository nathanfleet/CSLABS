// Adapter Demonstration
// (OBJECT--DELEGATION IMPLEMENTATION)

#include <iostream>

using std::cout; using std::endl;

// interface
class Square {
public:
    virtual void draw() =0;
    virtual ~Square(){}
};

// adaptee
class LegacyRectangle {
public:
    LegacyRectangle(int topLeftX,
                    int topLeftY,
                    int bottomRightX,
                    int bottomRightY) :
    topLeftX_(topLeftX),
    topLeftY_(topLeftY),
    bottomRightX_(bottomRightX),
    bottomRightY_(bottomRightY) {}

    void oldDraw() const {
        for(int i = 0; i < bottomRightY_; ++i) {
            for(int j = 0; j < bottomRightX_; ++j) {
                if(i >= topLeftY_ && j >= topLeftX_) {
                    cout << '*';
                } else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }

private:
    int topLeftX_;
    int topLeftY_;
    int bottomRightX_;
    int bottomRightY_;
};

// adapter class
// diffres from class implementation in that instead of 
// multiple inheritance we use a pointer to the adaptee to 
// access its members
class SquareAdapter : public Square {
public:
    SquareAdapter(int size) {
        adaptee_ = new LegacyRectangle(0, 0, size, size);
    }
    void draw() override {
        adaptee_->oldDraw();
    }
private:
    LegacyRectangle* adaptee_;
};

int main() {
    Square* s = new SquareAdapter(10);

    s->draw();

    cout << endl << endl;

    s = new SquareAdapter(15);
    s->draw();

    delete s;
    return 0;
}