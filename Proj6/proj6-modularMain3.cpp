// File: proj6-modularMain3.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 6
// Due Date: 10/17/2023

// Date Modified: 10/10/2023
//     -File created
// Date Modified: 10/15/2023
//     -File finished
// Modular version

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int PLIST_SIZE = 10;

/*
 *readPerson
 *
 *This function reads data from a file
 *
 *Parameters:
 *    in: istream reference
 *    info: string
 *    name: string reference
 *    age: int reference
 *    rate: double reference
 *
 *Output:
 *    return: void
 *    reference parameters: in, name, age, and rate
 *    stream: istream
*/
void readPerson(istream &in, string info, string &name, int &age, double &rate) {
    getline( in, name );
    in >> age;
    in.ignore(3, '\n');
    if(info != "person"){
        in >> rate;
        in.ignore(3, '\n');
    }
}

/*
 *writePerson
 *
 *This function prints data about a person
 *
 *Parameters:
 *    out: ostream reference
 *    info: string
 *    name: string
 *    age: int
 *    rate: double
 *
 *Output:
 *    return: void
 *    reference parameters: out
 *    stream: ostream
*/
void writePerson(ostream &out, string info, string name, int age, double rate) {
    out << name << endl;
    out << age << endl;
    if(info != "person"){
        out << rate << endl;
    }
}

/*
 *requestInfo
 *
 *This function outputs a message
 *
 *Parameters:
 *    out: ostream reference
 *    msg: string
 *
 *Output:
 *    return: void
 *    reference parameters: out
 *    stream: ostream
*/
void requestInfo(ostream &out, string msg) {
    out << msg << endl;
}

/*
 *readAgain
 *
 *This function asks the user to continue reading data
 *
 *Parameters:
 *    out: ostream reference
 *    in: istream reference
 *
 *Output:
 *    return: string
 *    reference parameters: out, in
 *    stream: ostream and istream
*/
string readAgain( ostream &out, istream &in ) {
    string choice;

    out << "Do you want to read in another person (yes/no)? " << endl;
    in >> choice;
    in.ignore(3, '\n');

    return choice;
}

/*
 *findPerson
 *
 *This function finds the name of a person in an array
 *
 *Parameters:
 *    pList[]: array of strings
 *    name: string
 *
 *Output:
 *    return: integer
 *    reference parameters: none
 *    stream: none
*/
int findPerson(string pList[], string name){
    int pos = -1;
    int i = 0;

    while(pos == -1 && i < PLIST_SIZE){
        if(pList[i] == name){
            pos = i;
        }
        i++;
    }
    return pos;
}

int main() {
    string name, choice, msg, pTypeChoice;
    string nameList[PLIST_SIZE];
    int ageList[PLIST_SIZE];
    double rateList[PLIST_SIZE];
    int i = 0;
    bool fileRead = false;
    ifstream pfile;
    ofstream opfile;

    // Ask user if they want data read from file
    cout << "Would you like to read the data from a file (yes/no)? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');

    // If user wants to read the data, open the file or print error message
    if(choice == "yes" ) {
        fileRead = true;
        pfile.open("iperson.txt");
        if(!pfile ) {
            cerr << "Can't open person.txt for read." << endl;
            return 1;
        }
        pfile >> pTypeChoice; // read type
        pfile.ignore(3, '\n');
    }
    else{
        cout << "What type of Person? (person/customer)" << endl;
        cin >> pTypeChoice;
        cin.ignore(3, '\n');
    }

    // Open file based on type
    if(pTypeChoice == "person"){
        opfile.open("operson.txt");
        msg = "Please enter your name followed by your age.";
    }
    else{
        opfile.open("ocustomer.txt");
        msg = "Please enter your name followed by your age then shipping rate.";
    }

    choice = "yes";

    // While user does not enter no and index is not bigger than list size
    while(choice != "no" && i < PLIST_SIZE){
        if(!fileRead) {
            requestInfo(cout, msg);
            readPerson(cin, pTypeChoice, nameList[i], ageList[i], rateList[i] );
            writePerson(opfile, pTypeChoice, nameList[i], ageList[i], rateList[i]);
            choice = readAgain(cout, cin);
        }
        else{
            readPerson(pfile, pTypeChoice, nameList[i], ageList[i], rateList[i]);
            if(!pfile ) {
                choice = "no";
            }
            else{
                writePerson(opfile, pTypeChoice, nameList[i], ageList[i], rateList[i]);
            }
        }
        i++;
    }

    // Close input and output file
    if(fileRead) {
        pfile.close();
    }
    opfile.close();

    // Ask user who they are looking for and try to find them
    cout << "Which person are you looking for? " << endl;
    getline(cin, choice);
    if((i = findPerson(nameList, choice)) != -1){
        cout << "Found your person: " << endl;
        writePerson(cout, pTypeChoice, nameList[i], ageList[i], rateList[i]);
    }
    else{
        cout << "Couldn't find your person: " << choice << endl;
    }

    return 0;
}