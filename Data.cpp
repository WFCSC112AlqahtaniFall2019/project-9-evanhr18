//
// Created by Henry Evans on 12/3/19.
//

#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Data::Data() { //default constructor
    playerName = "";
    shotClock = 0;
}
Data::Data(string name, double t) { //alternate constructor
    playerName = name;
    shotClock = t;
}


bool operator > (const Data &d, const Data & d2) { // > overloader
    return d.shotClock > d2.shotClock;
}


bool operator < (const Data &d, const Data &d2){ // < overloader
    return d.shotClock < d2.shotClock;
}

ostream& operator << (ostream& os, const Data a){ //overloaded to print to the files
    os << "Player Name: " << a.playerName << " Time Left on Shot Clock: " << a.shotClock << endl;
    cout << "Printing" << endl;
    return os;
}
