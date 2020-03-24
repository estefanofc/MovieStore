/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "MovieStore.h"
#include <cassert>
#include <iostream>
#include <map>

using namespace std;

void testStore1() {
  cout << "Start testStore2" << endl;
  string Mfile = "data4movies.txt";
  string Cfile = "data4customers.txt";
  string Cmfile = "data4commands.txt";
  stringstream Out;
  ifstream Fs1(Mfile);
  ifstream Fs2(Cfile);
  ifstream Fs3(Cmfile);
  assert(Fs1.is_open());
  //create a store object
  MovieStore Store;
  Store.createStore(Fs1, Fs2);
  Store.readCommands(Fs3);
  Store.runCommands();
  Fs1.close();
  Fs2.close();
  Fs3.close();
  //string Result = "IHHBRIBBIH";
  //assert(out.str() == result);
  cout << "End testStore2" << endl;
}

void testStore2() {

}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  testStore1();
  testStore2();
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStoreFinal();
}
