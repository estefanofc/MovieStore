//
// Created by Estefano Felipa on 3/10/20.
//

#ifndef MOVIESTORE__COMMAND_H
#define MOVIESTORE__COMMAND_H
#include"HashMap.h"
#include "Movie.h"
#include <map>
#include <sstream>
#include <string>
#include <vector>
class Customer;
using namespace std;

class Command {
  //ostream operator
  friend ostream &operator<<(ostream &Os, const Command &Cmd);
public:
  //default constructor
  Command();

  //virtual destructor, can be implemented by child classes
  virtual ~Command();

  //virtual run method, must be overriden by all child classes
  virtual void run(map<char, vector<Movie *> *> Movies,
                   const HashMap &Customers) = 0;

  //virtual display method, must be overriden by all child classes
  virtual ostream &display(ostream &Os) const = 0;
protected:
  //retrieves a certain movie from collection
  Movie *getMovie(const vector<Movie *> *Movies, Movie *Mv) const;
};

#endif //MOVIESTORE__COMMAND_H
