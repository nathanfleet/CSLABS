// drink class to be used in Coffee Shack lab
// Nathan Fleet
// 10/30/2023

#ifndef DRINK_HPP_
#define DRINK_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;
using std::unordered_set;

enum class DrinkType {small, medium, large};

class Drink{
public:
   Drink(DrinkType type=DrinkType::small, int price=0): type_(type), price_(price) {}

   // void setName(string name) { name_ = name; }
   virtual int    getPrice() const { return price_; }
   virtual string getName () const { 
      if(type_ == DrinkType::large) {
         return "large coffee with ";
      } else if (type_ == DrinkType::medium) {
         return "medium coffee with ";
      } else {
         return "small coffee with ";
      }
   }
private: 
   int price_;
   DrinkType type_;
   // string name_;
};

class Sugar : public Drink {
public:
   Sugar(Drink *wrapped) : wrapped_(wrapped) {}

   int    getPrice() const override { return wrapped_->getPrice() + 1;      }
   string getName () const override { return wrapped_->getName() + "sugar, "; }

private:
   const Drink *wrapped_;
};

class Cream : public Drink {
public:
   Cream(Drink *wrapped) : wrapped_(wrapped) {}

   int    getPrice() const override { return wrapped_->getPrice() + 2;      }
   string getName () const override { return wrapped_->getName() + "cream, "; }

private:
   const Drink *wrapped_;
};

class Honey : public Drink {
public:
   Honey(Drink *wrapped) : wrapped_(wrapped) {}

   int    getPrice() const override { return wrapped_->getPrice() + 3;      }
   string getName () const override { return wrapped_->getName() + "honey, "; }

private:
   const Drink *wrapped_;
};

class Barista; // forward declaration needed for reasons

class Observer { // observer interface
public:
   Observer(class Subject *subject);
   virtual void notify(Drink *drink) const = 0;
};

class Subject { // subject interface
private:
   unordered_set<Observer*> customers_;
public:
   void registerObserver(Observer *customer) { customers_.insert(customer); }
   void deregisterObserver(Observer *customer) { customers_.erase(customer); }
   void notifyObservers(Drink *drink) const {
      for (auto e: customers_) e->notify(drink);
   }
};

Observer::Observer(Subject *subject=nullptr) {
   subject->registerObserver(this);
}

class Customer : public Observer { // concrete observer
private:
   string name_;
   Drink *drink_;
public:
   Customer(string name, Barista *barista);

   void setDrink(Drink *drink) { drink_ = drink; }

   void notify(Drink *drink) const override {
      if(drink == drink_) {
         cout << name_ << ", your " << drink_->getName() << "is ready. It will be $" 
              << drink_->getPrice() << ", please." << endl;
      }
   }
};

class Barista : public Subject { // concrete subject
private:
   Barista *successor_;
public:
   Barista(Barista *successor = nullptr) : successor_(successor) {}

   void takeOrder() {
      srand(time(nullptr));

      char choice;
      cout << "Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee? ";
      std::cin >> choice;

      Drink *coffee = nullptr;

      switch (choice) {
      case 'l':
         coffee = new Drink(DrinkType::large, 10);
         break;
      case 'm':
         coffee = new Drink(DrinkType::medium, 7);
         break;
      case 's':
         coffee = new Drink(DrinkType::small, 5);
         break;
      default:
         exit(1);
      }

      do {
         cout << "Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one?";
         cin >> choice;

         switch(choice) {
         case 's':
               coffee = new Sugar(coffee);
               break;
         case 'c':
               coffee = new Cream(coffee);
               break;
         case 'h':
               coffee = new Honey(coffee);
               break;
         }
      } while(choice != 'd');

      cout << "Can I get your name?";
      string name;
      std::cin.ignore();
      std::getline(cin, name);

      Customer *customer = new Customer(name, this);
      customer->setDrink(coffee);
      registerObserver(customer);

      if(rand() % 2 == 0) notifyObservers(coffee);

      delete coffee;
      delete customer;
   }

   virtual void prepareDrink(Drink* drink) {
      if(successor_ != nullptr) successor_->prepareDrink(drink);
      else cout << "Nobody can prepare this drink." << endl;
   }
};

// had to move definition here as compiler would not recognize that barista is derived from Subject otherwise
Customer::Customer(string name, Barista *barista) 
   : Observer(static_cast<Subject*>(barista)), name_(name), drink_(nullptr) {}

class JuniorBarista : public Barista {
public:
   JuniorBarista(Barista *successor = nullptr) : Barista(successor) {}

   void prepareDrink(Drink *drink) override {
      // attempt to cast drink pointer into derived classes
      // if result is nullptr, drink does not contain that ingredient 
      if(dynamic_cast<Sugar*>(drink) == nullptr &&
         dynamic_cast<Cream*>(drink) == nullptr &&
         dynamic_cast<Honey*>(drink) == nullptr) {
         cout << "A junior barista is preparing your coffee..." << endl;
       } else {
         Barista::prepareDrink(drink);
       }
   }
};

class SeniorBarista : public Barista {
public:
   SeniorBarista(Barista *successor = nullptr) : Barista(successor) {}

   void prepareDrink(Drink *drink) override {
      if(dynamic_cast<Honey*>(drink) == nullptr) cout << "A senior barista is preparing your coffee..." << endl;
      else Barista::prepareDrink(drink);
   }
};

class Manager : public Barista {
public:
   Manager(Barista *successor = nullptr) : Barista(successor) {}

   void prepareDrink(Drink *drink) override {
      cout << "A manager is preparing your coffee..." << endl;
   }
};

#endif