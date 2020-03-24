//
// Created by Estefano Felipa on 3/12/20.
//

#ifndef MOVIESTORE__BORROW_H
#define MOVIESTORE__BORROW_H

#include "Command.h"
#include "MovieFactory.h"
#include <string>
using namespace std;
class Borrow : public Command {
public:
  //default constructor
  Borrow();

  //overloaded constructor
  Borrow(int CustomerID, const string &MediaType, const string &MovieStr);

  //default destructor
  ~Borrow() override;

  //overriden run method from parent class
  void run(map<char, vector<Movie *> *> Movies,
           const HashMap &Customers) override;

  //displays values from current class
  ostream &display(ostream &Os) const override;
private:
  int CustomerID = 0;
  string MediaType;
  string MovieStr;
};

#endif //MOVIESTORE__BORROW_H
