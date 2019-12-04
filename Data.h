//
// Created by Henry Evans on 12/3/19.
//

#ifndef PROJECT9_DATA_H
#define PROJECT9_DATA_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Data {
    friend ostream& operator << (ostream& os, Data a);
public:
    string playerName;
    double shotClock;

    Data();
    Data(string playerName, double shotClock);
    friend bool operator < (const Data &d, const Data & d2);
    friend bool operator > (const Data &d, const Data & d2);
    void setPlayerName (string name) {
        playerName = name;
    }
    string getPlayerName() {
        return playerName;
    }
    void setShotClock (int t) {
        shotClock = t;
    }
    double getShotClock() {
        return shotClock;
    }

};


#endif //PROJECT9_DATA_H
