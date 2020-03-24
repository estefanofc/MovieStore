//
// Created by Estefano Felipa on 3/12/20.
//

#include "HashMap.h"
#include <iostream>

//default constructor, sets all values to nullptr
HashMap::HashMap() {
  Count = 0;
  for (auto &I: Table)
    I = nullptr;
}
//default destructor
HashMap::~HashMap() = default;

//returns true if map is empty
bool HashMap::isEmpty() const {
  return Count == 0;
}

//retrieves number of entries in map
int HashMap::getNumberOfEntries() {
  return Count;
}

//inserts <key, value> pair into map
bool HashMap::put(int Key, Customer *Val) {
  int Index = hashing(Key);
  if (Table[Index] == nullptr) {
    Table[Index] = Val;
    Count++;
    KeySet.push_back(Key);
    return true;
  }
  cout << "EXCEPTION: Customer already exist in database" << endl;
  return false;
}

//gets value based on key
Customer *HashMap::getValue(int Key) const {
  return Table[hashing(Key)];
}

//returns true if key is present in map
bool HashMap::contains(int Key) const {
  return Table[hashing(Key)] != nullptr;
}

//hash function to determine position in array
int HashMap::hashing(int Key) const {
  return Key % MAX_CAPACITY;
}

//retrieves a collection of all keys
const vector<int> &HashMap::getKeySet() const {
  return KeySet;
}
