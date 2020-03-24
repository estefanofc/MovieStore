//
// Created by Estefano Felipa on 3/10/20.
//

#ifndef MOVIESTORE__COMEDY_H
#define MOVIESTORE__COMEDY_H
#include "Movie.h"
class Comedy : public Movie {
public:
  //default constructor
  Comedy();

  //default destructor
  ~Comedy() override;

  //overloaded constructor
  Comedy(int Stock, const string &Director, const string &Title, int Year);

  //displays contents of current class
  ostream &display(ostream &Os) const override;

  //returns an unique identifier based no sorting attributes
  string getUniqueKey() const override;
private:
  int Year = 0;

  //overriden method for sorting
  bool lessThan(Movie *Other) const override;

  //overiden method for comparison
  bool equals(Movie *Other) const override;
};


#endif //MOVIESTORE__COMEDY_H
