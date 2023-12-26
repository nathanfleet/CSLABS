// filled/hollow figures demonstrates Bridge Design Pattern,
// square is either hollow or square and is painted with a particular character,
// it is bridged over Figure --> Fill abstract body/handle
// Nathan Fleet
// 10/19/2023

#include <iostream>


using std::cout; using std::endl; using std::cin;

// abstract body
class Fill{
public:
   Fill(char borderChar, char internalChar): borderChar_(borderChar), internalChar_(internalChar) {}
   virtual char getBorder()=0;
   virtual char getInternal()=0;
   virtual ~Fill() {}
protected:
   char borderChar_;
   char internalChar_;
};

// concrete body
class Hollow: public Fill{
public:
   Hollow(char borderChar) : Fill(borderChar, ' ') {}
   char getBorder()   override {return borderChar_;} 
   char getInternal() override {return ' ';}
   ~Hollow()          override {}
};


// another concrete body
class Filled: public Fill {
public:
   Filled(char fillChar) : Fill(fillChar, fillChar) {}
   char getBorder()   override {return borderChar_;}
   char getInternal() override {return internalChar_;}
   ~Filled()          override {}
};

class FullyFilled: public Fill {
public:
   FullyFilled(char borderChar, char internalChar) : Fill(borderChar, internalChar) {}
   char getBorder()   override { return borderChar_;   }
   char getInternal() override { return internalChar_; }
   ~FullyFilled()     override {}
};

class RandomFilled: public Fill {
public:
   RandomFilled(char borderChar, char internalChar) : Fill(borderChar, internalChar) {}
   char getBorder()   override {
      if(rand() % 2 == 0) {
         return borderChar_;
      } else {
         return internalChar_;
      }
   }
   char getInternal() override {
      if(rand() % 2 == 0) {
         return borderChar_;
      } else {
         return internalChar_;
      }
   }
   ~RandomFilled()    override {}
};

// abstract handle
class Figure {
public:
   Figure(int size, Fill* fill): size_(size), fill_(fill){}
   virtual void draw() =0;
   virtual ~Figure(){}
protected:
   int size_;
   Fill *fill_;
};

// concrete handle
class Square: public Figure{
public:
   Square(int size, Fill* fill): Figure(size, fill){}
   void draw() override;

};

void Square::draw(){
   for(int i=0; i < size_; ++i){
      for(int j=0; j < size_; ++j)
	 if(i==0 || j==0 || i==size_-1 || j==size_-1 )
	    cout << fill_ -> getBorder();
	 else
	    cout << fill_ -> getInternal();
      cout << endl;
   }
}

int main(){
   // Filled square
   Square *userBox = new Square(10, static_cast<Fill*>(new Filled('%')));
   userBox->draw();
   cout << endl;

   // Hollow square
   userBox = new Square(10, static_cast<Fill*>(new Hollow('^')));
   userBox->draw();
   cout << endl;

   // Filled square with different border and fill
   userBox = new Square(10, static_cast<Fill*>(new FullyFilled('#', '&')));
   userBox->draw();
   cout << endl;

   srand(time(nullptr));

   // Randomly filled square
   userBox = new Square(10, static_cast<Fill*>(new RandomFilled('@', '~')));
   userBox->draw();
   cout << endl;
}