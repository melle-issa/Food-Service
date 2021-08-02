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
    cout << endl;

    for(int i = 1; i < 6; i++){
        cout << "What is your choice for day " << i << "?" << endl;
        getline(cin, choice);
        Dish plate;
        
//         plate.setName(choice);
//         plate.setIngr();
        
        picks.push_back(plate);
    }
    
    string answer;
    cout << "Do you have any food allergies? Y/N" << endl;
    cin >> answer;

    while(answer == "Y"){
        string allergies;
        cout << "What is your allergy? (please ender in all lower case)" << endl;
        cin >> allergies;

        int j;
        for(j = 0; j < picks.size(); j++){
            picks.at(j).update(allergies);
        }

        cout << "Do you have another allergy? Y/N" << endl;
        cin >> answer;
    }
    
    cout << "Here's your menu for the week: " << endl;
    for(int k = 0; k < picks.size(); k++){
        picks.at(k).printName();
        picks.at(k).printIngr();
        cout << endl;
    }
    

    return 0;
}
