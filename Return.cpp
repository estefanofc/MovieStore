//
// Created by Estefano Felipa on 3/12/20.
//

#include "Return.h"
#include "Customer.h"

//default constructor
Return::Return() = default;

//default destructor
Return::~Return() = default;

//overloaded constructor
Return::Return(int CustomerID, const string &MediaType, const string
&MovieStr) : CustomerID{CustomerID}, MediaType{MediaType}, MovieStr{MovieStr} {
}

//overriden run method to perform class commands
void Return::run(map<char, vector<Movie *> *> Movies,
                 const HashMap &Customers) {
  Customer *Customer = Customers.getValue(CustomerID);
  Movie *Mv = MovieFactory::createSpaces(MovieStr);
  if (Mv == nullptr || Customer == nullptr) {
    cout << "EXCEPTION: Invalid Customer/Movie input" << endl;
    return;
  }
  auto List = Movies.at(MovieStr[0]);
  int Stock = Mv->getStock();
  if (Customer->returnMovie(Mv, Stock)) {
    Movie *InventoryMv = getMovie(List, Mv);
    if (InventoryMv == nullptr) {
      cout << "EXCEPTION: Cannot return unregistered movie" << endl;
    } else {
      InventoryMv->increaseStock(Stock);
      stringstream Ss;
      Ss << *this;
      Customer->addToHistory(Ss);
    }
  } else {
    cout << "EXCEPTION: Cannot return movie that customer doesn't possess" <<
         endl;
  }
  delete Mv;
}

//overriden display method to output class' contents
ostream &Return::display(ostream &Os) const {
  Os << "R: " << MediaType << ", " << MovieStr << endl;
  return Os;
}

