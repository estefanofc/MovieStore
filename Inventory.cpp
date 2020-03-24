//
// Created by Estefano Felipa on 3/12/20.
//

#include "Inventory.h"

//default constructor
Inventory::Inventory() = default;

//default overriden destructor
Inventory::~Inventory() = default;

//overriden run method to peroform class commands
void Inventory::run(map<char, vector<Movie *> *> Movies,
                    const HashMap &Customers) {
  auto Comedies = Movies.at('F');
  auto Dramas = Movies.at('D');
  auto Classics = Movies.at('C');
  cout << "STORE INVENTORY" << endl;
  cout << "Comedies:" << endl;
  for (auto Curr: *Comedies)
    cout << *Curr;
  cout << endl;
  cout << "Dramas:" << endl;
  for (auto Curr: *Dramas)
    cout << *Curr;
  cout << endl;
  cout << "Classics:" << endl;
  for (auto Curr: *Classics)
    cout << *Curr;
  cout << endl;
}

//overriden display method to display class' methods
ostream &Inventory::display(ostream &Os) const {
  Os << "Showing Current Inventory of Store";
  return Os;
}


