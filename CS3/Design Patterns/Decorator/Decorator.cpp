// Decorator Pattern Demonstration

#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

// component
class Paragraph {
public:
    Paragraph(string text = "") : text_(text) {}
    virtual string getText() const { return text_; }
    
    virtual ~Paragraph() {}
private:
    string text_;
};

// Decorator
class Bold : public Paragraph {
public:
    Bold(const Paragraph* wrapped) : wrapped_(wrapped) {}
    string getText() const override {
        return "<b>" + wrapped_->getText() + "</b>";
    }

private:
    const Paragraph* wrapped_;
};

// Decorator
class Italic : public Paragraph {
public:
    Italic(const Paragraph* wrapped) : wrapped_(wrapped) {}
    string getText() const override {
        return "<i>" + wrapped_->getText() + "</i>";
    }
private:
    const Paragraph* wrapped_;
};

int main() {
    Paragraph p1("Some text");
    Paragraph p2("Some more text");

    Bold b(&p1);
    cout << b.getText() << endl;

    Italic i(&p2);
    cout << i.getText() << endl;

    return 0;
}