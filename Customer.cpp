//
// Created by Estefano Felipa on 3/10/20.
//

#include "Customer.h"

//default constructor
Customer::Customer() = default;

//overloaded constructor
Customer::Customer(int ID, const string &FirstName, const string &LastName) :
    ID{ID}, FirstName{FirstName}, LastName{LastName} {
  if (ID > 999 && ID < 10000)
    cout << "EXCEPTION: Invalid customerID" << endl;
}

//default destructor
Customer::~Customer() = default;

//borrows movie from store
void Customer::borrowMovie(Movie *Mv, int Stock) {
  string Key = Mv->getUniqueKey();
  if (Borrowed.count(Key) == 1) {
    Borrowed[Key] += Stock;
  } else {
    Borrowed[Key] = Stock;
  }
}

//returns movie to store
bool Customer::returnMovie(Movie *Mv, int Stock) {
  string Key = Mv->getUniqueKey();
  if (Borrowed.count(Key) == 1) {
    int CurrStock = Borrowed.at(Key);
    if (CurrStock - Stock < 0)
      return false;
    if (CurrStock - Stock == 0) {
      Borrowed.erase(Key);
    } else {
      Borrowed[Key] -= Stock;
    }
    return true;
  }
  return false;
}

//adds a command to customer's history
void Customer::addToHistory(stringstream &Ss) {
  History.push_back(Ss.str());
}

//display customer's history
string Customer::showHistory() const {
  stringstream Ss;
  Ss << "History of Customer " << FirstName << " " << LastName << endl;
  for (const auto &Curr: History)
    Ss << Curr << endl;
  return Ss.str();
}
