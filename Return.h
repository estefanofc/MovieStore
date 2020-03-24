//
// Created by Estefano Felipa on 3/12/20.
//

#ifndef MOVIESTORE__RETURN_H
#define MOVIESTORE__RETURN_H
#include "Command.h"
#include "MovieFactory.h"
class Return : public Command {
public:
  //default constructor
  Return();

  //overloaded constructor
  Return(int CustomerID, const string &MediaType, const string &MovieStr);

  //default destructor
  ~Return() override;

  //overriden run method to perform class commands
  void run(map<char, vector<Movie *> *> Movies,
           const HashMap &Customers) override;

  //overriden display method to output class' contents
  ostream &display(ostream &Os) const override;
private:
  int CustomerID = 0;
  string MediaType;
  string MovieStr;
};

#endif //MOVIESTORE__RETURN_H
