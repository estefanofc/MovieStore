//
// Created by Estefano Felipa on 3/12/20.
//

#ifndef MOVIESTORE__INVENTORY_H
#define MOVIESTORE__INVENTORY_H
#include "Command.h"

class Inventory : public Command {
public:

  //default constructor
  Inventory();

  //default overriden destructor
  ~Inventory() override;

  //overriden run method to perform class commands
  void run(map<char, vector<Movie *> *> Movies, const HashMap &Customers)
  override;

  //overriden display method to display class' methods
  ostream &display(ostream &Os) const override;
};

#endif //MOVIESTORE__INVENTORY_H
