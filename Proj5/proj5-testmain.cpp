// File: proj5-testmain.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 5
// Due Date: 10/9/2023

// Date Modified: 9/26/2023
//     -File created
// Date Modified: 10/1/2023
//     -File finished
// Functions are tested from files

#include <iostream>
#include <fstream>
#include "proj5-BUAthleteList.h"

using namespace std;

int main(){
    ifstream inFile;
    ifstream inFile2;
    BUAthlete athlete1;
    BUAthlete athlete2;

    // Testing opening file
    inFile.open("proj5-NCAAAthlete.csv");
    if(!inFile){
        cout << "Error: Bad File name" << endl;
        return 1;
    }
    inFile2.open("proj5-BUAthlete.csv");
    if(!inFile2){
        cout << "Error: Bad File name" << endl;
        return 1;
    }

    //Tests from BUAthlete are implemented
    cout << "Testing BUAthlete toString with Athlete1's information" << endl;
    cout << "Testing set functions" << endl;
    cout << "Information should be: 1234, Kirby, Baylor, 8, QB" << endl;
    athlete1.setID(1234);
    athlete1.setName("Kirby");
    athlete1.setLOI("yes");
    athlete1.setSchool("Baylor");
    athlete1.setEvaluation(8);
    athlete1.setPosition(QB);
    cout << athlete1.toString() << endl;

    cout << "Testing the get functions" << endl;
    cout << athlete1.getID() << ", ";
    cout << athlete1.getName() << ", ";
    cout << athlete1.getLOI() << ", ";
    cout << athlete1.getSchool() << ", ";
    cout << athlete1.getEvaluation() << ", ";
    cout << athlete1.getPosition() << ", ";
    cout << endl << endl;

    cout << "Athlete2's information" << endl;
    athlete2.setID(9756);
    athlete2.setName("Joel");
    athlete2.setLOI("no");
    athlete2.setSchool("Clemson");
    athlete2.setEvaluation(5);
    athlete2.setPosition(WR);
    cout << athlete2.toString() << endl;

    // Tests from BUAthleteLists are implemented

    cout << "Testing copy constructor" << endl;
    cout << "Athlete3's information from Athlete2" << endl;
    cout << "Information should: 9756, Joel, available, 5, WR" << endl;
    BUAthlete athlete3 = BUAthlete(athlete2);
    cout << athlete3.toString() << endl;

    BUAthleteList list;

    cout << "Testing BUAthleteList addNCAAAthlete" << endl;
    cout << "Should be 2342, Wesley Dyson, Citadel, 0, OL" << endl;
    list.addNCAAAthlete(2342,"Wesley Dyson","yes","Citadel");
    cout << list.toString() << endl;

    cout << "Testing setBUInfo" << endl;
    cout << "Should now be 2342, Wesley Dyson, Citadel, 9, LB" << endl;
    list.setBUInfo(0,LB,9);
    cout << list.toString() << endl;

    cout << "Adding more players..." << endl;
    cout << "Should be Wesley, Bradford, Jonah" << endl;
    list.addNCAAAthlete(9856,"Bradford","no","Auburn");
    list.setBUInfo(1,TE,3);
    list.addNCAAAthlete(4561,"Jonah","yes","Auburn");
    list.setBUInfo(2,DE,8);
    cout << list.toString() << endl;

    cout << "Testing findByID" << endl;
    cout << "Should find id 9856 and output 1" << endl;
    cout << "Is: " << list.findByID(9856) << endl;
    cout << "Should find id 2342 and output 0" << endl;
    cout << "Is: " << list.findByID(2342) << endl << endl;

    cout << "Testing sortByID" << endl;
    cout << "Should now be Wesley, Jonah, Bradford" << endl;
    list.sortByID();
    cout << list.toString() << endl;

    list.sortByEvaluation();
    cout << "Testing sortByEvaluation" << endl;
    cout << "Should be Wesley, Jonah, Bradford" << endl;
    cout << list.toString() << endl;

    list.sortByPosition();
    cout << "Testing sortByPosition" << endl;
    cout << "Should be Bradford, Jonah, Wesley" << endl;
    cout << list.toString() << endl;

    return 0;
}
