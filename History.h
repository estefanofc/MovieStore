//
// Created by Estefano Felipa on 3/12/20.
//

#ifndef MOVIESTORE__HISTORY_H
#define MOVIESTORE__HISTORY_H
#include "Command.h"
class History : public Command {
public:

  //default constructor
  History();

  //explicit overloaded constructor
  explicit History(int CustomerID);

  //default destructor
  ~History() override;

  //overriden run method to perform command
  void run(map<char, vector<Movie *> *> Movies, const HashMap &Customers)
  override;

  //overriden display method to display class' contents
  ostream &display(ostream &Os) const override;
private:
  int CustomerID = 0;
};

#endif //MOVIESTORE__HISTORY_H
