#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Dish.h"

using namespace std;

void printMenu(){
    cout << endl << "Menu options: ";
    ifstream MenuText;
    MenuText.open("ingredients.txt");
    char letter;

    MenuText >> letter;
    while(letter != '-'){
        cout << letter;
        MenuText >> letter;
        if(isupper(letter)){
            cout << " ";
        }
        if(letter == '-'){
            MenuText.ignore(letter, '\n');
            cout << ", "; // fix so that end of list doens't have a comma
            MenuText >> letter;
        }
    }
    
    MenuText.close();
}

int main(){

    vector <Dish> picks;

    string choice;
    cout << "Let's pick your meal plan for the week!" << endl;
    printMenu();

    for(int i = 0; i < 4; i++){
        cout << "What is your choise for day " << i << "?" << endl;
        getline(cin, choice);
        Dish plate;
        
        plate.setName(choice);
        plate.setIngr();
        
        picks.push_back(plate);
    }
    

    return 0;
}