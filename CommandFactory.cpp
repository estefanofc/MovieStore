//
// Created by Estefano Felipa on 3/11/20.
//

#include "CommandFactory.h"

//default constructor
CommandFactory::CommandFactory() = default;

//default destructor
CommandFactory::~CommandFactory() = default;

//static method to create command objects based on their type
Command *CommandFactory::create(const string &CmdStr) {
  char Type;
  int ID;
  string Media;
  stringstream Ss(CmdStr);
  stringstream SSQ;
  string MovieStr;
  Ss >> Type;
  switch (Type) {
  case 'I':return new Inventory();
  case 'H':Ss >> ID;
    return new History(ID);
  case 'B':Ss >> ID >> Media;
    getline(Ss, MovieStr);
    MovieStr = MovieStr.substr(1);
    return new Borrow(ID, Media, MovieStr);
  case 'R':Ss >> ID >> Media;
    getline(Ss, MovieStr);
    MovieStr = MovieStr.substr(1);
    return new Return(ID, Media, MovieStr);
  default:cout << "EXCEPTION: Invalid Command Type --> " << Type << endl;
    return nullptr;
  }
}
