//
// Created by Estefano Felipa on 3/10/20.
//

#include "Command.h"

//default constructor
Command::Command() = default;

//virtual destructor, can be implemented by child classes
Command::~Command() = default;

//virtual run method, must be overriden by all child classes
Movie *Command::getMovie(const vector<Movie *> *Movies, Movie *Mv) const {
  for (auto Curr: *Movies) {
    if (Curr->equals(Mv)) {
      return Curr;
    }
  }
  return nullptr;
}

//ostream operator
ostream &operator<<(ostream &Os, const Command &Cmd) {
  return Cmd.display(Os);
}

