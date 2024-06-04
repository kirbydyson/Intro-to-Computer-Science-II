// File: proj5-test.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 5
// Due Date: 10/9/2023

// Date Modified: 9/26/2023
//     -File created
// Date Modified: 10/6/2023
//     -File finished
// Solves the problem presented

#include <iostream>
#include <fstream>
#include <sstream>
#include "proj5-BUAthleteList.h"

using namespace std;

int main(){
    ifstream inFile;
    BUAthleteList list;
    Position position;
    string blank, name, school, loi, pos;
    int id, eval;
    stringstream ss;
    int athletes = 0;

    // Opening  NCAA file, print error message if wrong
    inFile.open("proj5-NCAAAthlete.csv");

    if(!inFile){
        cout << "Error: Bad File name" << endl;
        return 1;
    }

    // Read information from file
    while(getline(inFile, blank)){
        ss.clear();
        ss.str(blank);
        ss >> id;
        ss.ignore();
        getline(ss, name, ',');
        getline(ss, loi, ',');
        getline(ss, school, ',');

        list.addNCAAAthlete(id, name, loi, school);
    }
    inFile.close();
    // Sorting array by ID
    cout << "List sorted by ID" << endl;
    cout << list.toString() << endl << endl;
    list.sortByID();

    // Opening Aranda file, error message if wrong
    inFile.open("proj5-BUAthlete.csv");
    if(!inFile){
        cout << "Error: Bad file name" << endl;
        return 1;
    }

    // Read in information
    while(inFile >> id){
        int i = 0;
        inFile.ignore();
        getline(inFile, pos, ',');
        inFile >> eval;
        if(pos == "OL") {
            position = OL;
        }
        else if(pos == "QB") {
            position = QB;
        }
        else if(pos == "RB") {
            position = RB;
        }
        else if(pos == "WR") {
            position = WR;
        }
        else if(pos == "TE") {
            position = TE;
        }
        else if(pos == "DL") {
            position = DL;
        }
        else if(pos == "DE") {
            position = DE;
        }
        else if(pos == "LB") {
            position = LB;
        }
        else if(pos == "CB") {
            position = CB;
        }
        else if(pos == "S") {
            position = S;
        }
        else if(pos == "K") {
            position = K;
        }
        i = list.findByID(id);
        list.setBUInfo(i, position, eval);
        athletes++;
    }
    inFile.close();

    // Sorting list by athleteEvaluation (higher values at top)
    cout << "List sorted by Evaluation" << endl;
    list.sortByEvaluation();
    cout << list.toString() << endl << endl;
    // Sorting list by athletePosition (lower values at top)
    cout << "List sorted by Position" << endl;
    list.sortByPosition();
    cout << list.toString() << endl;

    // Output top two players for each position
    cout << "Top 2 BUAthletes for each athletePosition:" << endl;
    Position currPos = OL;
    int count = 0;
    for(int i = 0; i < athletes; ++i) {
        BUAthlete athlete = list[i];
        if(athlete.getPosition() != currPos) {
            currPos = athlete.getPosition();
            count = 1;
        }
        else{
            count++;
        }
        if(count < 3) {
            cout << athlete.toString() << endl;
        }
    }
    cout << endl << endl;
    return 0;
}
