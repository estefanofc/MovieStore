//
// Created by Estefano Felipa on 3/11/20.
//

#ifndef MOVIESTORE__COMMANDFACTORY_H
#define MOVIESTORE__COMMANDFACTORY_H
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"
#include <sstream>
//factory class to create command objects
class CommandFactory {
public:
  //default constructor
  CommandFactory();

  //default destrucor
  ~CommandFactory();

  //static method to create command objects based on their type
  static Command *create(const string &CmdStr);
};

#endif //MOVIESTORE__COMMANDFACTORY_H
