// File: proj1-main.cpp
// Author: Prof. Matthew Aars
// Course: CSI 1440 02
// Assignment: Project 1
// Due Date: 8/28/2023

// Date Modified: 8/24/2023
//     -File created
// Date Modified: 8/27/2023
//     -File finished
// Names and ages are sorted using pointers from a file and functions
// in proj1-person.h. The names and ages are then displayed on the screen.

#include <iostream>
#include <fstream>
#include <sstream>
#include "proj1-person.h"
using namespace std;

const int MAX_PPL = 25;

int main(){

    // Declaration of variables
    ifstream inFile;
    stringstream infoSS;
    string data, name;
    int p = 0;
    Person thePeople[MAX_PPL];
    Person *referenceToThePeople[MAX_PPL];

    // Opening the data file
    inFile.open("people.dat");

    //If file fails to open, print error message
    if(!inFile) {
        cout << "Error: Unable to open file" << endl;
        return 1;
    }

    // As long as data is being read from the file and there are no more
    // than 25 people
    while(getline(inFile, data) && p < MAX_PPL){
        // As long as line contains data
        if(data.size() > 1){
            infoSS << data;
            getAPersonFromStream(infoSS, &thePeople[p]);
            p++;
        }
        infoSS.clear();
    }

    // As long as there are no more than 25 people
    for(int i = 0; i < MAX_PPL; i++){
        // Getting the addresses of the array into the pointers
        referenceToThePeople[i] = thePeople + i;
    }

    // Closing the data file
    inFile.close();

    // As long as there are 5 people
    if(p > 4){
        // Sort and display the ages to the screen
        sortPersonArrayByAge(referenceToThePeople, p);
        for(int i = 0; i < 5; i++){
            displayAPerson(cout, referenceToThePeople[i]);
        }

        cout << endl;

        // Sort and display the names to the screen
        sortPersonArrayByName(referenceToThePeople, p);
        for(int i = 0; i < 5; i++){
            displayAPerson(cout, referenceToThePeople[i]);
        }
    }

    // As long as "no more" is not entered
    while(name != "no more"){
        getline(cin, name);
        findAPerson(referenceToThePeople, p, name);
    }

    return 0;
}

