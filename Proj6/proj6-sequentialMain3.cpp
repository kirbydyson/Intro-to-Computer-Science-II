// File: proj6-sequentialMain3.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 6
// Due Date: 10/17/2023

// Date Modified: 10/10/2023
//     -File created
// Date Modified: 10/15/2023
//     -File finished
// Sequential (non-modular) version

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string name, choice;
    int age;
    bool fileRead = false;
    ifstream pFile;
    ofstream opFile;

    // Ask user if they want data read from file
    cout << "Would you like to read the data from a file? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');

    // If user wants to read the data, open the file or print error message
    if(choice == "yes"){
        fileRead = true;
        pFile.open("iperson.txt");
        if(!pFile){
            cerr << "Can't open person.txt for read. " << endl;
            return 1;
        }
    }

    // Open output file
    opFile.open("operson.txt");

    choice = "yes";

    // Read data from the file
    if(fileRead){
        getline(pFile, name);
        pFile >> age;
        pFile.ignore(3, '\n');
        if(!pFile){
            choice = "no";
        }
    }

    // While user wants the data read, put their information in the output file
    while(choice != "no"){
        if(!fileRead){
            cout << "Please enter your name followed by your age." << endl;
            getline(cin, name);
            cin >> age;
            cin.ignore(3, '\n');
        }

        opFile << name << endl;
        opFile << age << endl;

        if(!fileRead){
            cout << "Do you want to read in another person (yes/no)? " << endl;
            cin >> choice;
            cin.ignore(3, '\n');
        }
        else{
            getline(pFile, name);
            pFile >> age;
            pFile.ignore(3, '\n');
            if(!pFile){
                choice = "no";
            }
        }
    }

    // Close input and output file
    if(fileRead){
        pFile.close();
    }
    opFile.close();

    return 0;
}