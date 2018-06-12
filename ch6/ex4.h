#ifndef EX4_H
#define EX4_H
#include "std_lib_facilities.h"

class Name_score {
public:
     Name_score() :name {""}, score {0} {}
     Name_score(string name, int score) :name {name}, score {score} {}
     string name;
     int score;
     bool operator==(const Name_score&) const;
     bool operator!=(const Name_score&) const;
     bool operator<=(const Name_score&) const;
     bool operator<(const Name_score&) const;
};

istream& operator>>(istream& is, Name_score& ns);
ostream& operator<<(ostream& os, const Name_score &ns);

#endif
