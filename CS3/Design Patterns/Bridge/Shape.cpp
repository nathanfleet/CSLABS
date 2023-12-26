// my own bridge pattern example using shapes

#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

// abstract implementation
class Color {
public:
    virtual string getColor() const =0;
    ~Color() {}
};

// concrete implementation 1
class Red : public Color {
public:
    string getColor() const override {
        return "RED";
    }
};

// concrete implementation 2
class Green : public Color {
public:
    string getColor() const override {
        return "GREEN";
    }
};

// concrete implementation 3
class Blue : public Color {
public:
    string getColor() const override {
        return "BLUE";
    }
};

// abstract handle
class Shape {
public:
    Shape(Color* color) : color_(color) {}

    virtual void draw() const = 0;

    ~Shape() {}
protected:
    Color* color_;
};

// concrete handle 1
class Square : public Shape {
public:
    Square(Color* color) : Shape(color) {}

    void draw() const override {
        cout << "I am a SQUARE of color " << color_->getColor();
    }
};

// concrete handle 2
class Triangle : public Shape {
public:
    Triangle(Color* color) : Shape(color) {}

    void draw() const override {
        cout << "I am a TRIANGLE of color " << color_->getColor();
    }
};

int main() {
    Color* color = new Red();
    Shape* shape = new Square(color);

    // red square
    shape->draw();
    cout << endl;

    // green square
    color = new Green();
    shape = new Square(color);

    shape->draw();
    cout << endl;

    // blue triangle
    color = new Blue();
    shape = new Triangle(color);

    shape->draw();
    cout << endl;

    delete color;
    delete shape;

    return 0;
}