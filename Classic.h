//
// Created by Estefano Felipa on 3/10/20.
//

#ifndef MOVIESTORE__CLASSIC_H
#define MOVIESTORE__CLASSIC_H
#include "Movie.h"
class Classic : public Movie {
public:
  //default constructor
  Classic();

  //default destructor
  ~Classic() override;

  //overloaded constructor
  Classic(int Stock, const string &Director, const string &Title,
          const string &MFirstName, const string &MLastName, int Month,
          int Year);

  //overriden method to display current class
  ostream &display(ostream &Os) const override;

  //gets an unique identifier for the class based on sorting attributes
  string getUniqueKey() const override;
private:
  int Month = 0;
  int Year = 0;
  string MFirstName;
  string MLastName;

  //overriden method for sorting
  bool lessThan(Movie *Other) const override;

  //overriden method for comparison
  bool equals(Movie *Other) const override;
};

#endif //MOVIESTORE__CLASSIC_H
