//
// Created by Estefano Felipa on 3/12/20.
//

#ifndef MOVIESTORE__HASHMAP_H
#define MOVIESTORE__HASHMAP_H

class Customer;
#include <iostream>
#include <vector>
using namespace std;
//hashmap implementaion with <int, Customer*> pair
class HashMap {
public:
  //default constructor, sets all values to nullptr
  HashMap();

  //default destructor
  ~HashMap();

  //returns true if map is empty
  bool isEmpty() const;

  //retrieves number of entries in map
  int getNumberOfEntries();

  //inserts <key, value> pair into map
  bool put(int Key, Customer *Val);

  //gets value based on key
  Customer *getValue(int Key) const;

  //returns true if key is present in map
  bool contains(int Key) const;

  //retrieves a collection of all keys
  const vector<int> &getKeySet() const;

private:
  static const int MAX_CAPACITY = 727;

  //container for all values
  Customer *Table[MAX_CAPACITY];
  vector<int> KeySet;
  int Count;

  //hash function to determine position in array
  int hashing(int Key) const;

};

#endif //MOVIESTORE__HASHMAP_H
