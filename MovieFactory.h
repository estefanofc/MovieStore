//
// Created by Estefano Felipa on 3/10/20.
//

#ifndef MOVIESTORE_CMAKE_BUILD_DEBUG_MOVIEFACTORY_H
#define MOVIESTORE_CMAKE_BUILD_DEBUG_MOVIEFACTORY_H
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include <algorithm>
#include <sstream>
#include <vector>
//factory class to create movie objects
class MovieFactory {
public:
  //default constructor
  MovieFactory();

  //default destructor
  ~MovieFactory();

  //creates a child of Movie based on the Genre (parameter)
  static Movie *create(const string &MvStr);

  //creates a child of Movie based on the Genre (parameter)/input is separated
  //by spaces
  static Movie *createSpaces(const string &MvSs);
};

#endif //MOVIESTORE_CMAKE_BUILD_DEBUG_MOVIEFACTORY_H
