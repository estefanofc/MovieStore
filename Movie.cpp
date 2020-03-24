//
// Created by Estefano Felipa on 3/11/20.
//

#include "Movie.h"

//default constructor
Movie::Movie() = default;
Movie::~Movie() = default;

//overloaded constructor
Movie::Movie(int Stock, const string &Director, const string &Title) :
    Stock{Stock}, Director{Director}, Title{Title} {

}

//increases movie's stock
void Movie::increaseStock(int Quantity) {
  Stock += Quantity;
}

//decreases movie stock
bool Movie::decreaseStock(int Quantity) {
  if (Stock - Quantity < 0)
    return false;
  Stock -= Quantity;
  return true;
}

//returns movie's stock
int Movie::getStock() {
  return Stock;
}

//ostream operator to display class' contents
ostream &operator<<(ostream &Os, const Movie &Mv) {
  return Mv.display(Os);
}
