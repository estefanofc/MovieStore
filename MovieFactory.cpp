//
// Created by Estefano Felipa on 3/10/20.
//

#include "MovieFactory.h"

//default constructor
MovieFactory::MovieFactory() = default;

//default destructor
MovieFactory::~MovieFactory() = default;

//creates a child of Movie based on the Genre (parameter)
Movie *MovieFactory::create(const string &MvStr) {
  char Type;
  int Stock, Year, ReYear, ReMonth;
  string Director, Title, MFirstName, MLastName, Curr;
  vector<string> Split;
  stringstream Ss(MvStr);
  while (getline(Ss, Curr, ',')) {
    if (Curr.size() > 1)
      Curr = Curr.substr(1);
    Split.push_back(Curr);
  }
  Type = Split[0][0];
  Stock = stoi(Split[1]);
  Director = Split[2];
  Title = Split[3];
  switch (Type) {
  case 'F':Year = stoi(Split[4]);
    return new Comedy(Stock, Director, Title, Year);
  case 'D':Year = stoi(Split[4]);
    return new Drama(Stock, Director, Title, Year);
  case 'C':Ss.str("");
    Ss.clear();
    Ss << Split[4];
    Ss >> MFirstName >> MLastName >> ReMonth >> ReYear;
    return new Classic(Stock, Director, Title, MFirstName, MLastName,
                       ReMonth, ReYear);
  default:cout << "EXCEPTION: Invalid Movie Type --> " << Type << endl;
    return nullptr;
  }
}

//creates a child of Movie based on the Genre (parameter)/input is separated
//by spaces
Movie *MovieFactory::createSpaces(const string &Mv) {
  stringstream MvSs(Mv);
  char Type;
  int Stock = 1;
  int Year, ReYear, ReMonth;
  string Director, Title, MFirstName, MLastName, Curr;
  MvSs >> Type;
  switch (Type) {
  case 'F':getline(MvSs, Curr, ',');
    Title = Curr.substr(1);
    getline(MvSs, Curr, ',');
    Year = stoi(Curr.substr(1));
    return new Comedy(Stock, "", Title, Year);
  case 'D':getline(MvSs, Curr, ',');
    Director = Curr.substr(1);
    getline(MvSs, Curr, ',');
    Title = Curr.substr(1);
    return new Drama(Stock, Director, Title, 0);
  case 'C':MvSs >> ReMonth >> ReYear >> MFirstName >> MLastName;
    return new Classic(Stock, "", "", MFirstName, MLastName,
                       ReMonth, ReYear);
  default:cout << "EXCEPTION: Invalid Movie Type --> " << Type << endl;
    return nullptr;
  }
}
