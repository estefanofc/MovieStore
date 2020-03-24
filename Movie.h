//
// Created by Estefano Felipa on 3/11/20.
//

#ifndef MOVIESTORE__MOVIE_H
#define MOVIESTORE__MOVIE_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Movie {
  //ostream operator to display class' contents
  friend ostream &operator<<(ostream &Os, const Movie &Mv);
public:
  //default constructor
  Movie();

  //overloaded constructor
  Movie(int Stock, const string &Director, const string &Title);

  //increases movie's stock
  void increaseStock(int Quantity);

  //decreases movie stock
  bool decreaseStock(int Quantity);

  //returns movie's stock
  int getStock();

  //default destructor, can be overriden by child classes
  virtual ~Movie();

  //virtual method for sorting, must be overriden by all child classes
  virtual bool lessThan(Movie *Other) const = 0;

  //virtual method for comparison, must be overriden by all child classes
  virtual bool equals(Movie *Other) const = 0;

  //virtual method for displaying class' content, must be overriden by all
  // child classes
  virtual ostream &display(ostream &Os) const = 0;

  //virtual method for returning unique identifier of class, must be overriden
  //by all child classes
  virtual string getUniqueKey() const = 0;

protected:
  int Stock = 0;
  string Director;
  string Title;
};

#endif //MOVIESTORE__MOVIE_H
