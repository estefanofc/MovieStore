//
// Created by Estefano Felipa on 3/10/20.
//

#include "MovieStore.h"
using namespace std;

//reads and stores commands from txt file
void MovieStore::readCommands(ifstream &InCommand) {
  string ReadLine;
  while (!InCommand.eof()) {
    getline(InCommand, ReadLine);
    Command *Curr = CommandFactory::create(ReadLine);
    if (Curr == nullptr)
      continue;
    Commands.push(Curr);
  }

}

//constructor
MovieStore::MovieStore() {
  MovieMap['F'] = Comedies;
  MovieMap['D'] = Dramas;
  MovieMap['C'] = Classics;
}

//destructor
MovieStore::~MovieStore() {
  vector<int> Keys = CustomerMap.getKeySet();
  for (auto Curr: Keys) {
    Customer *Temp = CustomerMap.getValue(Curr);
    delete Temp;
  }
  for (auto Curr: *Comedies)
    delete Curr;
  for (auto Curr: *Dramas)
    delete Curr;
  for (auto Curr: *Classics)
    delete Curr;

  delete Comedies;
  delete Dramas;
  delete Classics;
}

//fills store movies and customer from txt files
void MovieStore::createStore(ifstream &InMovie, ifstream &InCustomer) {
  readMovies(InMovie);
  readCustomers(InCustomer);
}

//executes all commands
void MovieStore::runCommands() {
  while (!Commands.empty()) {
    Command *FrontCmd = Commands.front();
    Commands.pop();
    FrontCmd->run(MovieMap, CustomerMap);
    delete FrontCmd;
  }
}

//creates store's movies
void MovieStore::readMovies(ifstream &InMovie) {
  string ReadLine;
  while (getline(InMovie, ReadLine)) {
    if (ReadLine.empty())
      break;
    char Type = ReadLine[0];
    Movie *Curr = MovieFactory::create(ReadLine);
    if (Curr == nullptr)
      continue;
    addMovie(Curr, getContainer(Type));
  }
}

//creates store's customers
void MovieStore::readCustomers(ifstream &InCustomer) {
  int ID;
  string FirstName, LastName;
  while (!InCustomer.eof()) {
    InCustomer >> ID >> LastName >> FirstName;
    auto *Curr = new Customer(ID, FirstName, LastName);
    if (!CustomerMap.put(ID, Curr))
      delete Curr;
  }

}

//adds movie to container
void MovieStore::addMovie(Movie *Mv, vector<Movie *> *List) {
  for (auto Curr: *List) {
    if (Curr->equals(Mv)) {
      cout << "EXCEPTION: Movie already exist in inventory" << endl;
      return;
    }
  }
  List->push_back(Mv);
  sortByKey(List);
}

//sorts movie based on their sorting attribute
void MovieStore::sortByKey(vector<Movie *> *List) {
  sort(List->begin(), List->end(),
       [](Movie *M1, Movie *M2) { return M1->lessThan(M2); });
}

//retrieves the right container based on movie genre
vector<Movie *> *MovieStore::getContainer(char Type) {
  return MovieMap.at(Type);
}

