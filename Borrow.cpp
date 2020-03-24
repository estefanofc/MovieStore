//
// Created by Estefano Felipa on 3/12/20.
//

#include "Borrow.h"
#include "Customer.h"

//default constructor
Borrow::Borrow() = default;

//overloaded constructor
Borrow::Borrow(int CustomerID, const string &MediaType,
               const string &MovieStr) : CustomerID{CustomerID},
                                         MediaType{MediaType},
                                         MovieStr{MovieStr} {

}

//default destructor
Borrow::~Borrow() = default;

//overriden run method from parent class
void Borrow::run(map<char, vector<Movie *> *> Movies,
                 const HashMap &Customers) {
  Customer *Customer = Customers.getValue(CustomerID);
  Movie *Mv = MovieFactory::createSpaces(MovieStr);
  if (Mv == nullptr || Customer == nullptr)
    return;
  auto List = Movies.at(MovieStr[0]);
  Movie *InventoryMv = getMovie(List, Mv);
  if (InventoryMv == nullptr) {
    cout << "EXCEPTION: Cannot borrow from movie not present in inventory" <<
         endl;
    delete Mv;
    return;
  }
  int Stock = Mv->getStock();
  if (InventoryMv->decreaseStock(Stock)) {
    Customer->borrowMovie(Mv, Stock);
    stringstream Ss;
    Ss << *this;
    Customer->addToHistory(Ss);
  } else {
    cout << "EXCEPTION: Not enough stock to borrow from movie " << endl;
  }
  delete Mv;
}

//displays values from current class
ostream &Borrow::display(ostream &Os) const {
  Os << "B: " << MediaType << ", " << MovieStr << endl;
  return Os;
}


