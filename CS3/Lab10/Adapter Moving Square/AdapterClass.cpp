// figures: class adapter pattern
// Nathan Fleet
// 10/23/2023

#include <iostream>

using std::cout; using std::cin; using std::endl;

// base interface
class Square {
public:
   virtual void draw()=0;
   virtual ~Square(){}
   virtual int size() const = 0;
   virtual void resize(int newSize) = 0;
};

// adaptee/implementer
class LegacyRectangle {
public:
   LegacyRectangle(int topLeftX, 
		   int topLeftY, 
		   int bottomRightX, 
		   int bottomRightY): 
      topLeftX_(topLeftX), 
      topLeftY_(topLeftY), 
      bottomRightX_(bottomRightX), 
      bottomRightY_(bottomRightY){}

   void oldDraw() const {
      for(int i=0; i < bottomRightY_; ++i){
         for(int j=0; j < bottomRightX_; ++j)
            if(i >= topLeftY_  && j >= topLeftX_ )
               cout << '*';
            else
               cout << ' ';
         cout << endl;
      }
   }

   void move(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
      topLeftX_     = topLeftX;
      topLeftY_     = topLeftY;
      bottomRightX_ = bottomRightX;
      bottomRightY_ = bottomRightY;
   }

   // getters
   int getTopLeftX()     const    { return topLeftX_; }
   int getTopLeftY()     const    { return topLeftY_; }
   int getBottomRightX() const    { return bottomRightX_; }
   int getBottomRightY() const    { return bottomRightY_; }

// defining top/left and bottom/right coordinates 
private: 
   int topLeftX_;
   int topLeftY_;
   int bottomRightX_;
   int bottomRightY_;
};

// adapter uses multiple inheritance to inherit
// interface and implementation
class SquareAdapter: public Square, private LegacyRectangle {
public:
   SquareAdapter(int size): LegacyRectangle(0, 0, size, size) {};
   void draw() override {
      oldDraw();
   }

   int  size()        const override { return getBottomRightY();    }
   void resize(int newSize) override { move(0, 0, newSize, newSize); }
};

int main(){
   int size;
   cout << "Input size:";
   cin >> size;

   Square *square = new SquareAdapter(size);
   square->draw();

   cout << endl;

   cout << "Input new size:";
   cin >> size;

   square->resize(size);
   square->draw();
}