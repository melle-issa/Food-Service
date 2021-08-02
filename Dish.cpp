#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Dish.h"

using namespace std;

void Dish :: setName(string input){
    name = input;
}

void Dish :: printName(){
    cout << name << " - ";
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

    string ingredient = "";

    int i = 0;

    // finds end of dinner name
    while(foodList.at(i) != '-'){
        i ++;
    }

    i = i+2; // accounts for the space after the - and the first letter of the first ingredient

    char character;
    // creates ingredient vector
    for(i=i; i < foodList.size(); i++){
        character = foodList.at(i);

        if(character == ','){
            ingr.push_back(ingredient);
            ingredient = "";
            i = i+1;
        }
        else{
            ingredient = ingredient + character;
        }
    }
    //pushes final ingredient not followed by a comma
    ingr.push_back(ingredient);
}

void Dish :: printIngr(){
    int i;
    for(i = 0; i < ingr.size(); i++){
        cout << ingr.at(i) << ", ";
    }
}

void Dish :: update(string allergy){
    for(int i = 0; i < ingr.size(); i++){
        if(ingr.at(i) == allergy){
            for(int j = i; j < ingr.size()-1; j++){
                string temp = ingr.at(j+1);
                ingr.at(j+1) = allergy;
                ingr.at(j) = temp;
            }

            ingr.pop_back();
            break;
        }
    }
}


