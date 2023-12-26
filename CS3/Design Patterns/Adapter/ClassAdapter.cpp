// Adapter Demonstration
// (CLASS IMPLEMENTATION)

#include <iostream>

using std::cout; using std::endl;

// interface
class Square {
public:
    virtual int size() const =0;
    virtual void resize(int size) =0;
    virtual void draw() = 0;
    virtual ~Square(){}
};

// adaptee
// (this is the class with an incompatible interface)
// we will be 'adapting' it to work with above square interface
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

    void move(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
        topLeftX_ = topLeftX;
        topLeftY_ = topLeftY;
        bottomRightX_ = bottomRightX;
        bottomRightY_ = bottomRightY;
    }

    int getTopLeftX    () const { return topLeftX_;     }
    int getTopLeftY    () const { return topLeftY_;     }
    int getBottomRightX() const { return bottomRightX_; }
    int getBottomRightY() const { return bottomRightY_; }

private:
    int topLeftX_;
    int topLeftY_;
    int bottomRightX_;
    int bottomRightY_;
};

// this is the Adapter
// uses multiple inheritance
// wraps the adaptee to make its interface usable by the Square
// interface
class SquareAdapter : public Square, private LegacyRectangle {
public:
    SquareAdapter(int size) : LegacyRectangle(0, 0, size, size) {}
    void draw() override { oldDraw(); }
    int size() const override { return getBottomRightY(); }
    void resize(int size) override { move(0, 0, size, size); }
};

int main() {
    int size = 10;

    Square* square = new SquareAdapter(size);
    square->draw();

    cout << endl << endl;

    square->resize(15);
    square->draw();

    cout << "Square is currently size: " << std::to_string(square->size()) << endl;


    delete square;
    return 0;
}