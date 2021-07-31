#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Dish.h"

using namespace std;

void Dish :: setName(string input){
    name = input;
}

void Dish:: setIngr(){
    ifstream ingrList;
    ingrList.open("ingredients.txt");

    string first;
    ingrList >> first;

    string foodList;

    while(!ingrList.eof()){
        if(first.substr(0, 3) == name.substr(0,3)){
            getline(ingrList, foodList);
        }
        ingrList.ignore(first.at(0), '\n');
        ingrList >> first;
    }

    char character;
    string ingredient;

    for(int i = 0; i < foodList.size(); i++){

    }

}
