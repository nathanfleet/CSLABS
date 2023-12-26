// needed for lab
// Mikhail Nesterenko
// 3/18/2022

#include <iostream>
#include <vector>
#include <cstdlib>
#include "CarFactory.hpp"

using std::vector;
using std::cout; using std::endl;

class CarLot{
public:
   CarLot();

   Car *testDriveCar() {
      if(currentCarIT_ != cars4sale_.end()) { return *(currentCarIT_); }
      currentCarIT_ = cars4sale_.begin();
      return *(currentCarIT_);
   }

   // if a car is bought, requests a new one
   Car *buyCar(){ 
      if(currentCarIT_ == cars4sale_.end()) { return nullptr; }
      
      Car *bought = *currentCarIT_;
      currentCarIT_ = cars4sale_.erase(currentCarIT_); // remove purchased car
      cars4sale_.push_back(factories_[rand() % factories_.size()]->requestCar()); // replace bought car with new one
      return bought;
   }

   Car *nextCar() {
      if(currentCarIT_ !=  cars4sale_.end()) {
         return *(currentCarIT_++);
      }
      currentCarIT_ = cars4sale_.begin();
      return *(currentCarIT_);
   }

   int lotSize() const { return cars4sale_.size(); };
		     
private:
   vector<Car *> cars4sale_;
   vector<Car *>::iterator currentCarIT_;
   vector<CarFactory *> factories_;
};


CarLot::CarLot(){
   // creates 2 Ford factories and 2 Toyota factories 
   factories_.push_back(new FordFactory());   
   factories_.push_back(new ToyotaFactory());
   factories_.push_back(new FordFactory());
   factories_.push_back(new ToyotaFactory());

   // gets the first eight cars for sale
   for(int i = 0; i < 8; ++i) {
      cars4sale_.push_back(factories_[rand() % factories_.size()] -> requestCar());  
   }

   currentCarIT_ = cars4sale_.begin();
}



CarLot *carLotPtr = nullptr; // global pointer instantiation

// test-drives a car
// buys it if Toyota 4Runner
void toyotaLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();
      Car* toyota = new Toyota();

   cout << "Looking for " << toyota -> getModel() << " " << toyota -> getMake() << endl;

   for(int i = 0; i < carLotPtr->lotSize(); ++i) {
      Car *toBuy = carLotPtr -> testDriveCar();

      cout << "Jill Toyoter " << id << endl;
      cout << " test driving " << toBuy -> getMake() << " " << toBuy -> getModel() << " ...";

      if(toBuy -> getMake() == "Toyota" && toBuy -> getModel() == toyota -> getMake()) {
         cout << " love it! buying it!" << endl;
         carLotPtr -> buyCar();
         return;
      } else {
         cout << " did not like it! " << endl;
         carLotPtr -> nextCar();
      }
      cout << endl;
   }
}

// test-drives a car
// buys it if Ford Mustang
void fordLover(int id){
   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();
      Car* ford = new Ford();

   cout << "Looking for " << ford -> getModel() << " " << ford -> getMake() << endl;

   for(int i = 0; i < carLotPtr->lotSize(); ++i) {
      Car *toBuy = carLotPtr -> testDriveCar();

      cout << "Jack Fordman " << id << endl;
      cout << " test driving " << toBuy -> getMake() << " " << toBuy -> getModel() << " ...";

      if(toBuy -> getMake() == "Ford" && toBuy -> getModel() == ford->getModel()) {
         cout << " love it! buying it!" << endl;
         carLotPtr -> buyCar();
         return;
      } else {
         cout << " did not like it! " << endl;
         carLotPtr -> nextCar();
      }
      cout << endl;
   }
}



int main() {
   srand(time(nullptr));

   const int numBuyers=20;
   for(int i=0; i < numBuyers; ++i)
      if(rand()% 2 == 0)
	 toyotaLover(i);
      else
	 fordLover(i);
}