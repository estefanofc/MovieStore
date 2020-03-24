//
// Created by Estefano Felipa on 3/10/20.
//

#ifndef MOVIESTORE__MOVIESTORE_H
#define MOVIESTORE__MOVIESTORE_H

#include "Command.h"
#include "CommandFactory.h"
#include "Customer.h"
#include "HashMap.h"
#include "MovieFactory.h"
#include <fstream>
#include <map>
#include <queue>

using namespace std;
class Movie;

class MovieStore {
public:
  //constructor
  MovieStore();

  //destructor
  ~MovieStore();

  //fills store movies and customer from txt files
  void createStore(ifstream &InMovie, ifstream &InCustomer);

  //reads and stores commands from txt file
  void readCommands(ifstream &InCommand);

  //executes all commands
  void runCommands();
private:
  HashMap CustomerMap;
  vector<Movie *> *Comedies = new vector<Movie *>;
  vector<Movie *> *Dramas = new vector<Movie *>;
  vector<Movie *> *Classics = new vector<Movie *>;
  map<char, vector<Movie *> *> MovieMap;
  queue<Command *> Commands;

  //creates store's movies
  void readMovies(ifstream &InMovie);

  //creates store's customers
  void readCustomers(ifstream &InCustomer);

  //adds movie to container
  void addMovie(Movie *Mv, vector<Movie *> *List);

  //sorts movie based on their sorting attribute
  void sortByKey(vector<Movie *> *List);

  //retrieves the right container based on movie genre
  vector<Movie *> *getContainer(char Type);
};

#endif //MOVIESTORE__MOVIESTORE_H
