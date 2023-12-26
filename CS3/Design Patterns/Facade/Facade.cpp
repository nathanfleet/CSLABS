// facade for sigure interfaces
// Mikhail Nesterenko
// 04/28/2018

#include <iostream>
#include <vector>
#include <map>

using std::cout; using std::endl;

// base class
class Figure {
public:
   Figure(int size):  size_(size) {}
   void resize(int newSize){size_=newSize;}
   virtual void draw() =0;
   virtual ~Figure(){}
protected:
   int size_;
};


class Line: public Figure{
public: 
   enum class Direction {Horizontal, Vertical};
   Line(int size, Direction dir): Figure(size), dir_(dir){}
   void flip(){dir_ = dir_ == Direction::Horizontal ? Direction::Vertical :
	                      Direction::Horizontal;}
   Direction getDirection(){return dir_;}
   void draw() override {
      for(int i=0; i<size_; ++i){
	 cout << '*';
	 if(dir_ == Direction::Vertical) cout << endl;
      }
      if(dir_ == Direction::Horizontal) cout << endl;
   }
private:
   Direction dir_;
};

class Square: public Figure{
public:
   Square(int size, char fill): Figure(size), fill_(fill) {}
   void draw() override {
      for(int i=0; i<size_; ++i){
	 for(int j=0; j<size_; ++j)
	    cout << fill_;
	 cout << endl;
      }
   }
private:
   char fill_;
};

class Triangle: public Figure{
public:
   Triangle(int size, bool filled): Figure(size), filled_(filled){}
   void draw() override {
      for(int i=0; i<size_; ++i){
	 for(int j=0; j<size_; ++j)
	    if(j == 0 || i == size_-1 || i == j || filled_ && i > j )
	       cout << '*';
	    else
	       cout << ' ';
	 cout << endl;
      }
   }
private:
   bool filled_;
};

// facade over figure classes
// with simplifed interface
class FigureFacade {
public:
   void drawHorizontalLine(int size){
      el_.resize(size);
      if(el_.getDirection() != Line::Direction::Horizontal) el_.flip();
      el_.draw();
   }
   void drawVerticalLine(int size){
      el_.resize(size);
      if(el_.getDirection() != Line::Direction::Vertical) el_.flip();
      el_.draw();
   }
   void drawSquare(int size){
      s_.resize(size);
      s_.draw();
   }
   void drawTriangle(int size){
      t_.resize(size);
      t_.draw();
   }
private:
   Line el_{0, Line::Direction::Horizontal};
   Square s_{0, '^'};
   Triangle t_{0, false};
};


int main(){
   FigureFacade figureDrawer;

   figureDrawer.drawHorizontalLine(10);
   figureDrawer.drawVerticalLine(5);
   figureDrawer.drawSquare(7);
   figureDrawer.drawTriangle(9);
}