//
// Created by Estefano Felipa on 3/11/20.
//

#ifndef MOVIESTORE__DRAMA_H
#define MOVIESTORE__DRAMA_H

#include "Movie.h"
class Drama : public Movie {
public:
  //overriden destructor
  ~Drama() override;

  //default constructor
  Drama();

  //overloaded constructor
  Drama(int Stock, const string &Director, const string &Title,
        int Year);

  //displays class' contents
  ostream &display(ostream &Os) const override;

  //returns unique identifier based on sorting attributes
  string getUniqueKey() const override;
private:
  int Year = 0;

  //comparison method for sorting
  bool lessThan(Movie *Other) const override;

  //comparison method
  bool equals(Movie *Other) const override;
};

#endif //MOVIESTORE__DRAMA_H

