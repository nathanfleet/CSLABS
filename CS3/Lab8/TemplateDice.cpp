// Games, Template Method example
// Nathan Fleet
// 10/13/2023

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;

// template for any game where players take 
// turns to make moves
// and there is a winner
class Game{
public:
   Game():playersCount_(0), movesCount_(0), playerWon_(noWinner){}

   // template method
   void playGame(const int playersCount = 0) {
      playersCount_ = playersCount;
      movesCount_=0;

      initializeGame();

      for(int i=0; !endOfGame(); i = (i+1) % playersCount_ ){
         makeMove(i);
         if (i==playersCount_-1) 
            ++movesCount_; 
      }
      printWinner();
   }

   virtual ~Game(){}

protected:
   // primitive operations
   virtual void initializeGame() = 0;
   virtual void makeMove(int player) = 0;
   virtual void printWinner() = 0;
   virtual bool endOfGame() { return playerWon_ != noWinner;} // this is a hook
                                                              // returns true if winner is decided
   static const int noWinner=-1;

   int playersCount_;
   int movesCount_;
   int playerWon_;
};

// Monopoly - a concrete game implementing primitive 
// operations for the template method
class Monopoly: public Game {
public:  
   // implementing concrete methods
   void initializeGame(){
      playersCount_ = rand() % numPlayers_ + 1 ; // initialize players
   }

   void makeMove(int player) {
      if (movesCount_ > minMoves_){ 
	      const int chance = minMoves_ + rand() % (maxMoves_ - minMoves_);
	      if (chance < movesCount_) playerWon_= player;
      }
   }

   void printWinner(){
      cout << "Monopoly, player "<< playerWon_<< " won in "
	        << movesCount_<< " moves." << endl;
   }

private:
   static const int numPlayers_ = 8; // max number of players
   static const int minMoves_ = 20; // nobody wins before minMoves_
   static const int maxMoves_ = 200; // somebody wins before maxMoves_
};

// Chess - another game implementing
// primitive operations
class Chess: public Game {
public:
   void initializeGame(){
      playersCount_ = numPlayers_; // initalize players
      for(int i=0; i < numPlayers_; ++i) 
	     experience_[i] = rand() % maxExperience_ + 1 ; 
   }

   void makeMove(int player){
      if (movesCount_ > minMoves_){
	      const int chance = (rand() % maxMoves_) / experience_[player];
	      if (chance < movesCount_) playerWon_= player;
      }
   }

   void printWinner(){
      cout << "Chess, player " << playerWon_ 
	        << " with experience " << experience_[playerWon_]
	        << " won in "<< movesCount_ << " moves over"
	        << " player with experience " << experience_[playerWon_== 0 ? 1:0] 
           << endl;
   }

private:
   static const int numPlayers_ = 2;
   static const int minMoves_ = 2;      // nobody wins before minMoves_
   static const int maxMoves_ = 100;    // somebody wins before maxMoves_
   static const int maxExperience_ = 5; // player's experience
                                        // the higher, the greater probability of winning
   int experience_[numPlayers_]; 
};

class Dice: public Game {
public:
   void initializeGame(){
      playersCount_ = 2;

      cScore_ = 0;
      cPass_ = false;

      hScore_ = 0;
      hPass_ = false;
   }

   void makeMove(int player){
      // print round number if first player
      if(player % playersCount_ == 0) {
         // someone wins before maxMoves_
         if(movesCount_ > maxMoves_) {
            if(cScore_ > hScore_) {
               playerWon_ = computer_;
            } else {
               playerWon_ = human_;
            }
            return;
         }
         cout << endl;
         cout << "Round " << (movesCount_ + 1) << ": ";
      }

      if(player == computer_) {
         rollDice(computer_, cPass_); // computer doesn't pass on first round
         cPass_ = (rand() % 2) == 0;  // radomly pick pass or roll again ???
      } else {
         rollDice(human_, hPass_);    // human doesn't pass on first round
         if(cPass_ && hPass_) {     // if both passed, game is over
            movesCount_ = maxMoves_;
            return;
         } else if(movesCount_ == maxMoves_) { // if maxMoves_ is met, game is over
            return;
         }

         if(!hPass_) {
            char choice;
            cout << "Roll again? [y/n]";
            cin  >> choice;

            if(choice == 'y') {
               hPass_ = false;
            } else {
               hPass_ = true;
            }
         }
      }
   }

   void rollDice(int player, bool pass) {
      (player == computer_) ? cout << "Computer " : cout << "You ";

      int total = 0;

      if(pass) {
         // just print that they passed
         cout << "passed, ";
      } else { 
         // if player didnt pass, roll dice and change score
         cout << "rolled: ";
         for(int i = 0; i < 5; ++i) {
            int roll = (rand() % 6) + 1;
            cout << roll << " ";
            total += roll;
         }
         // update correct player's score
         (player == computer_) ? cScore_ = total : hScore_ = total;
      }

      if(player == computer_) {
         cout << "computer's score = " << cScore_ << endl;
      } else {
         cout << "your score = " << hScore_ << endl;
      }
   }

   void printWinner(){
      if(playerWon_ == computer_) {
         cout << "You lose!" << endl;
      } else {
         cout << "You win!" << endl;
      }
   }

private:
   static const int maxMoves_ = 2;
   static const int computer_ = 0; // values to signify human or computer
   static const int human_    = 1; //

   int  hScore_;  // keep track of score
   bool hPass_; // and wether or not they passed

   int  cScore_;
   bool cPass_;
};


int main() {
   srand(time(nullptr));

   Game* gp = nullptr;

   // // play chess 8 times
   // for (int i = 0; i < 8; ++i){ 
   //    gp = new Chess;
   //    gp->playGame(); 
   //    delete gp;
   // }
      

   // // play monopoly 8 times
   // for (int i = 0; i < 8; ++i){
   //    gp = new Monopoly;
   //    gp->playGame(); 
   //    delete gp;
   // }

   gp = new Dice;
   gp->playGame();
   delete gp;

}
