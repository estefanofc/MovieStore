//
// Created by Estefano Felipa on 3/11/20.
//

#include "Drama.h"
//overloaded constructor
Drama::Drama(int Stock, const string &Director, const string &Title,
             int Year) : Movie(Stock, Director, Title), Year{Year} {
}

//comparison method for sorting
bool Drama::lessThan(Movie *Other) const {
  auto OtherMv = dynamic_cast<Drama *>(Other);
  return Director < OtherMv->Director ||
      ((Director == OtherMv->Director) && (Title < OtherMv->Title));
}

//comparison method
bool Drama::equals(Movie *Other) const {
  auto OtherMv = dynamic_cast<Drama *>(Other);
  return Director == OtherMv->Director && Title == OtherMv->Title;
}

//displays class' contents
ostream &Drama::display(ostream &Os) const {
  Os << Stock << ", " << Director << ", " << Title << ", " << Year << endl;
  return Os;
}

//returns unique identifier based on sorting attributes
string Drama::getUniqueKey() const {
  stringstream Ss;
  Ss << Director << Title;
  return Ss.str();
}

//default constructor
Drama::Drama() = default;

//overriden destructor
Drama::~Drama() = default;
