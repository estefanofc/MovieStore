//
// Created by Estefano Felipa on 3/12/20.
//

#include "History.h"
#include "Customer.h"

//default constructor
History::History() = default;

//explicit overloaded constructor
History::History(int CustomerID) : CustomerID{CustomerID} {
}

//default destructor
History::~History() = default;

//overriden run method to perform command
void History::run(map<char, vector<Movie *> *> Movies,
                  const HashMap &Customers) {
  Customer *Curr = Customers.getValue(CustomerID);
  if (Curr == nullptr) {
    cout << "EXCEPTION: Cannot show history of non existing Customer" << endl;
    return;
  }
  cout << Curr->showHistory();
}

//overriden display method to display class' contents
ostream &History::display(ostream &Os) const {
  Os << "Showing History of Customer: " << CustomerID;
  return Os;
}

