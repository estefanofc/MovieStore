//
// Created by Estefano Felipa on 3/10/20.
//

#include "Classic.h"

//overloaded constructor
Classic::Classic(int Stock,
                 const string &Director,
                 const string &Title,
                 const string &MFirstName,
                 const string &MLastName,
                 int Month,
                 int Year) : Movie(Stock, Director, Title),
                             MFirstName{MFirstName}, MLastName{MLastName},
                             Year{Year},
                             Month{Month} {

}

//overriden method for sorting
bool Classic::lessThan(Movie *Other) const {
  auto OtherMv = dynamic_cast<Classic *>(Other);
  string Actor = MFirstName + MLastName;
  string OtherActor = OtherMv->MFirstName + OtherMv->MLastName;
  return ((Year < OtherMv->Year) ||
      ((Year == OtherMv->Year) && (Month < OtherMv->Month)) ||
      ((Year == OtherMv->Year) && (Month == OtherMv->Month) &&
          (Actor < OtherActor)));
}

//overriden method for comparison
bool Classic::equals(Movie *Other) const {
  auto OtherMv = dynamic_cast<Classic *>(Other);
  string Actor = MFirstName + MLastName;
  string OtherActor = OtherMv->MFirstName + OtherMv->MLastName;
  return ((Actor == OtherActor) && (Year == OtherMv->Year) &&
      (Month == OtherMv->Month));
}

//overriden method to display current class
ostream &Classic::display(ostream &Os) const {
  Os << Stock << ", " << Director << ", " << Title << ", " <<
     Month << "/" << Year << ", " << MFirstName << " " << MLastName << endl;
  return Os;
}

//gets an unique identifier for the class based on sorting attributes
string Classic::getUniqueKey() const {
  stringstream Ss;
  Ss << Month << Year << MFirstName << MLastName;
  return Ss.str();
}

//default constructor
Classic::Classic() = default;

//default destructor
Classic::~Classic() = default;


