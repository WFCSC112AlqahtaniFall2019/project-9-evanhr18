//
// Created by Henry Evans on 12/3/19.
//

#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Data::Data() {                          // default constructor
    playerName = "";
    shotClock = "";
}
Data::Data(string name, string t) {             // alternate constructor
    playerName = name;
    shotClock = t;
}


bool operator > (const Data &d, const Data & d2) {          // operator overload 1
    return d.shotClock > d2.shotClock;
}


bool operator < (const Data &d, const Data &d2){            // operator overload 2
    return d.shotClock < d2.shotClock;
}

ostream& operator << (ostream& os, const Data a){               // file stream operator overload
    os << a.playerName <<  a.shotClock << endl;
    return os;
}
