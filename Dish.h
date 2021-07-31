#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#ifndef DISH_H
#define DISH_H

using namespace std;

class Dish{
    public:
        void setIngr();
        void setName(string);
        void update(string);
        void printIngr();
        void printName();
    private:
       vector<string> ingr;
       string name;
};

#endif
