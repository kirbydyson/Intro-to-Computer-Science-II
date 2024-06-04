// File: proj1-testmain.cpp
// Author: Prof. Matthew Aars
// Course: CSI 1440 02
// Assignment: Project 1
// Due Date: 8/28/2023

// Date Modified: 8/24/2023
//     -File created
// Date Modified: 8/27/2023
//     -File finished
// Test cases are implemented to prove the correctness of the program.

#include <iostream>
#include <sstream>
#include "proj1-person.h"

using namespace std;

const int MAX_PPL = 25;

int main(){
    Person thePeople[MAX_PPL];
    Person *testPerson;
    Person *referenceToThePeople[MAX_PPL];
    stringstream infoSS;
    string name, testName;

    // Test name and ages
    infoSS <<
           "\nKirby Dyson, 19\n"
           "Bradford Dyson, 20\n"
           "Wesley Dyson, 23\n"
           "Jonah Dyson, 24\n"
           "Temple Dyson, 50\n"
           "Joel Dyson, 52\n"
           "Mya Johnson, 17\n"
           "Hollis Dusa, 42\n"
           "Chloe Holloway, 56\n"
           "Cale Burch, 31\n"
           "Taylor Swift, 33\n"
           "Zach Bryan, 44\n"
           "John Smith, 89\n"
           "Jane Doe, 12\n"
           "Alpha Phi, 100\n"
           "Sarah Balding, 67\n"
           "Kayla Morales, 98\n"
           "Taylor Dundore, 21\n"
           "Megan Red, 23\n"
           "Gabe Finley, 45\n"
           "Harry Potter, 15\n"
           "Coffee Addict, 11\n"
           "Love Life, 10\n"
           "Comp Sci, 43\n"
           "Baylor Bears, 54\n";

    // Assigning people their pointer
    for(int i = 0; i < MAX_PPL; i++){
        referenceToThePeople[i] = thePeople + i;
    }

    // Testing getAPersonFromStream and displayAPerson function
    cout << "Testing getAPersonFromStream and displayAPerson" << endl;
    for(int i = 0; i < MAX_PPL; i++){
        getAPersonFromStream(infoSS, referenceToThePeople[i]);
        displayAPerson(cout, referenceToThePeople[i]);
    }
    cout << endl << "End Test 1" << endl;

    // Testing sortPersonArrayByAge function
    cout << endl << "Testing sortPersonArrayByAge" << endl;
    sortPersonArrayByAge(referenceToThePeople, MAX_PPL);
    for(int i = 0; i < MAX_PPL; i++){
        displayAPerson(cout, referenceToThePeople[i]);
    }
    cout << endl << "End Test 2" << endl;

    // Testing sortPersonArrayByName function
    cout << endl << "Testing sortPersonArrayByName" << endl;
    sortPersonArrayByName(referenceToThePeople, MAX_PPL);
    for(int i = 0; i < MAX_PPL; i++){
        displayAPerson(cout, referenceToThePeople[i]);
    }
    cout << endl << "End Test 3" << endl;

    // Should output five people sorted by age
    cout << endl << "First 5 sorted by age" << endl;
    sortPersonArrayByAge(referenceToThePeople, MAX_PPL);
    for(int i = 0; i < 5; i++){
        displayAPerson(cout, referenceToThePeople[i]);
    }
    cout << endl << "End Test 4 should have ages: 10, 11, 12, 15, 17" << endl;

    // Should output five people sorted by name
    cout << endl << "First 5 sorted by name" << endl;
    sortPersonArrayByName(referenceToThePeople, MAX_PPL);
    for(int i = 0; i < 5; i++){
        displayAPerson(cout, referenceToThePeople[i]);
    }
    cout << endl << "End Test 5 should be names: ";
    cout << endl << "Alpha P, Baylor B, Bradford D, Cale B, Chloe H" << endl;

    // Testing findAPerson function
    cout << endl << "Testing findAPerson" << endl;
    testName = "\nKirby Dyson";
    testPerson = findAPerson(referenceToThePeople, MAX_PPL, testName);
    cout << endl << "Should be Kirby Dyson, 19" << endl;
    if(testPerson == nullptr){
        cout << "Person not found" << endl;
    }
    else{
        cout << "Person found: ";
        displayAPerson(cout, testPerson);
    }

    testName = "Starbucks";
    testPerson = findAPerson(referenceToThePeople, MAX_PPL, testName);
    cout << "Should be Person not found" << endl;
    if(testPerson == nullptr){
        cout << "Person not found" << endl;
    }
    else{
        cout << "Person found: ";
        displayAPerson(cout, testPerson);
    }
    cout << endl << "End of testing" << endl;

    return 0;
}
