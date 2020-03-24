//
// Created by Estefano Felipa on 3/10/20.
//

#include "Comedy.h"
//overloaded constructor
Comedy::Comedy(int Stock, const string &Director, const string &Title,
               int Year) : Movie(Stock, Director, Title), Year{Year} {
}

//overriden method for sorting
bool Comedy::lessThan(Movie *Other) const {
  auto OtherMv = dynamic_cast<Comedy *>(Other);
  return Title < OtherMv->Title || ((Title == OtherMv->Title) &&
      (Year < OtherMv->Year));
}

//overiden method for comparison
bool Comedy::equals(Movie *Other) const {
  auto OtherMv = dynamic_cast<Comedy *>(Other);
  return Title == OtherMv->Title && Year == OtherMv->Year;
}

//displays contents of current class
ostream &Comedy::display(ostream &Os) const {
  Os << Stock << ", " << Director << ", " << Title << ", " << Year << endl;
  return Os;
}

//returns an unique identifier based no sorting attributes
string Comedy::getUniqueKey() const {
  stringstream Ss;
  Ss << Title << Year;
  return Ss.str();
}

//default constructor
Comedy::Comedy() = default;

//default destructor
Comedy::~Comedy() = default;
