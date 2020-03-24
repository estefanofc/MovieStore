//
// Created by Estefano Felipa on 3/10/20.
//

#ifndef MOVIESTORE__CUSTOMER_H
#define MOVIESTORE__CUSTOMER_H
#include "Movie.h"
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
class Customer {
public:
  //default constructor
  Customer();

  //overloaded constructor
  Customer(int ID, const string &FirstName, const string &LastName);

  //default destructor
  ~Customer();

  //adds a command to customer's history
  void addToHistory(stringstream &Ss);

  //borrows movie from store
  void borrowMovie(Movie *Mv, int Stock);

  //returns movie to store
  bool returnMovie(Movie *Mv, int Stock);

  //display customer's history
  string showHistory() const;

private:
  int ID = 0;
  string FirstName;
  string LastName;
  vector<string> History;
  map<string, int> Borrowed;
};

#endif //MOVIESTORE__CUSTOMER_H
