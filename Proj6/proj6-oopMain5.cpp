// File: proj6-oopMain5.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 6
// Due Date: 10/17/2023

// Date Modified: 10/10/2023
//     -File created
// Date Modified: 10/17/2023
//     -File finished
// Oop version (no inheritance or polymorphism)

#include <iostream>
#include <fstream>

using namespace std;

const int PLIST_SIZE = 10;

class Person {
private:
    string name;
    int age;

public:
    /*
     *getName
     *
     *This function returns the name of a person
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: string
     *    reference parameters: none
     *    stream: none
    */
    string getName() { return name; }
    void readPerson(istream &);
    void writePerson(ostream &);

};

/*
 *readPerson
 *
 *This function reads data from a file
 *
 *Parameters:
 *    in: istream reference
 *
 *Output:
 *    return: void
 *    reference parameters: in
 *    stream: istream
*/
void Person::readPerson(istream &in) {
    getline(in, name);
    in >> age;
    in.ignore(3, '\n');
}

/*
 *writePerson
 *
 *This function prints data
 *
 *Parameters:
 *    out: ostream reference
 *
 *Output:
 *    return: void
 *    reference parameters: out
 *    stream: ostream
*/
void Person::writePerson(ostream &out) {
    out << name << endl;
    out << age << endl;
}

/*
 *requestInfo
 *
 *This function prints a message
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
string readAgain(ostream &out, istream &in) {
    string choice;

    out << "Do you want to read in another person (yes/no)? " << endl;
    in >> choice;
    in.ignore(3, '\n');

    return choice;
}

class Customer {
private:
    double shippingRate;
    string name;
    int age;

public:
    Customer();
    double getShippingRate();
    void readPerson(istream & );
    void writePerson(ostream & );
    /*
     *getName
     *
     *This function returns the name of a person
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: string
     *    reference parameters: none
     *    stream: none
    */
    string getName(){ return name; }
};

/*
 *Customer
 *
 *This function is the default constructor
 *
 *Parameters:
 *    none
 *
 *Output:
 *    return: none
 *    reference parameters: none
 *    stream: none
*/
Customer::Customer() {
    shippingRate = 5.0;
}

/*
 *getShippingRate
 *
 *This function returns the shipping rate
 *
 *Parameters:
 *    none
 *
 *Output:
 *    return: double
 *    reference parameters: none
 *    stream: none
*/
double Customer::getShippingRate() {
    return shippingRate;
}

/*
 *readPerson
 *
 *This function reads data from a file
 *
 *Parameters:
 *    in: istream reference
 *
 *Output:
 *    return: void
 *    reference parameters: in
 *    stream: istream
*/
void Customer::readPerson(istream &in) {
    getline(in, name);
    in >> age;
    in.ignore(3, '\n');
    in >> shippingRate;
    cin.ignore(3, '\n');
}

/*
 *writePerson
 *
 *This function prints data about a person
 *
 *Parameters:
 *    out: ostream reference
 *
 *Output:
 *    return: void
 *    reference parameters: out
 *    stream: ostream
*/
void Customer::writePerson(ostream &out) {
    out << name << endl;
    out << age << endl;
    out << shippingRate << endl;
}

class MegaCustomer {
private:
    double shippingRate;
    string name;
    int age;

public:
    MegaCustomer();
    void readPerson(istream & );
    void writePerson(ostream &);
    /*
     *getName
     *
     *This function returns the name of a person
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: string
     *    reference parameters: none
     *    stream: none
    */
    string getName(){ return name; }
    double getShippingRate();
};

/*
 *MegaCustomer
 *
 *This function is the default constructor
 *
 *Parameters:
 *    none
 *
 *Output:
 *    return: none
 *    reference parameters: none
 *    stream: none
*/
MegaCustomer::MegaCustomer() {
    shippingRate = 0;
}

/*
 *readPerson
 *
 *This function reads data from a file
 *
 *Parameters:
 *    in: istream reference
 *
 *Output:
 *    return: void
 *    reference parameters: in
 *    stream: istream
*/
void MegaCustomer::readPerson(istream &in){
    getline(in, name);
    in >> age;
    in.ignore(3, '\n');
}

/*
 *writePerson
 *
 *This function prints data about a person
 *
 *Parameters:
 *    out: ostream reference
 *
 *Output:
 *    return: void
 *    reference parameters: out
 *    stream: ostream
*/
void MegaCustomer::writePerson(ostream &out){
    out << name << endl;
    out << age << endl;
    out << shippingRate << endl;
}

/*
 *getShippingRate
 *
 *This function returns the shipping rate
 *
 *Parameters:
 *    none
 *
 *Output:
 *    return: double
 *    reference parameters: none
 *    stream: none
*/
double MegaCustomer::getShippingRate(){
    return shippingRate;
}

/*
 *findPerson
 *
 *This function finds the name of a person in an array
 *
 *Parameters:
 *    pList[]: pointer to array from Person class
 *    name: string
 *
 *Output:
 *    return: integer
 *    reference parameters: none
 *    stream: none
*/
int findPerson(Person *pList[], string name) {
    int pos = -1, i = 0;

    while (pos == -1 && i < PLIST_SIZE) {
        if (pList[i]->getName() == name) {
            pos = i;
        }
        i++;
    }

    return pos;
}

/*
 *findPerson
 *
 *This function finds the name of a person in an array
 *
 *Parameters:
 *    pList[]: pointer to array from Customer class
 *    name: string
 *
 *Output:
 *    return: integer
 *    reference parameters: none
 *    stream: none
*/
int findPerson(Customer *pList[], string name) {
    int pos = -1, i = 0;

    while (pos == -1 && i < PLIST_SIZE) {
        if (pList[i]->getName() == name) {
            pos = i;
        }
        i++;
    }

    return pos;
}

/*
 *findPerson
 *
 *This function finds the name of a person in an array
 *
 *Parameters:
 *    pList[]: pointer to array from MegaCustomer class
 *    name: string
 *
 *Output:
 *    return: integer
 *    reference parameters: none
 *    stream: none
*/
int findPerson(MegaCustomer *pList[], string name) {
    int pos = -1, i = 0;

    while (pos == -1 && i < PLIST_SIZE) {
        if (pList[i]->getName() == name) {
            pos = i;
        }
        i++;
    }

    return pos;
}

int main() {
    Person **pList = new Person *[PLIST_SIZE];
    Customer **cList = new Customer *[PLIST_SIZE];
    MegaCustomer **mcList = new MegaCustomer *[PLIST_SIZE];
    string choice, pTypeChoice, msg = "Please enter your name followed by your age.";
    int index = 0;
    bool fileRead = false;
    ifstream pfile;
    ofstream opfile;

    // Ask user if they want data read from file
    cout << "Would you like to read the data from a file (yes/no)? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');

    // If user wants to read the data, open the file or print error message
    if(choice == "yes") {
        fileRead = true;
        pfile.open("iperson.txt");

        if(!pfile) {
            cerr << "Can't open person.txt for read." << endl;
            return 1;
        }
        pfile >> pTypeChoice;
        pfile.ignore(3, '\n');

    }
    else{
        cout << "What type of Person? (person/customer/mega)" << endl;
        cin >> pTypeChoice;
        cin.ignore(3, '\n');
    }

    // Allocate memory for pList, cList, and mcList
    if(pTypeChoice == "person"){
        for(int i = 0; i < PLIST_SIZE; i++){
            pList[i] = new Person;
        }
    }
    else if(pTypeChoice == "customer"){
        for(int i = 0; i < PLIST_SIZE; i++){
            cList[i] = new Customer;
        }
        msg = "Please enter your name followed by your age then shipping rate.";
    }
    else{
        for(int i = 0; i < PLIST_SIZE; i++ ){
            mcList[i] = new MegaCustomer;
        }
    }

    // Open output file
    opfile.open("operson.txt");

    choice = "yes";

    // Check which list to read
    if(fileRead) {
        if(pTypeChoice == "person"){
            pList[index]->readPerson(pfile);
        }
        else if(pTypeChoice == "customer"){
            cList[index]->readPerson(pfile);
        }
        else{
            mcList[index]->readPerson(pfile);
        }
        if(!pfile){
            choice = "no";
        }
    }

    // While user does not enter no and index is not bigger than list size
    while(choice != "no" && index < PLIST_SIZE){
        if(!fileRead) {
            requestInfo(cout, msg);
            if(pTypeChoice == "person"){
                pList[index]->readPerson(cin);
                pList[index]->writePerson(opfile);
            }
            else if(pTypeChoice == "customer"){
                cList[index]->readPerson(cin);
                cList[index]->writePerson(opfile);
            }
            else{
                mcList[index]->readPerson(cin);
                mcList[index]->writePerson(opfile);
            }
        }
        index++;
        if(!fileRead){
            choice = readAgain(cout, cin);
        }
        else{
            if(pTypeChoice == "person"){
                pList[index]->readPerson(pfile);
            }
            else if(pTypeChoice == "customer"){
                cList[index]->readPerson(pfile);
            }
            else{
                mcList[index]->readPerson(pfile);
            }
            if(!pfile){
                choice = "no";
            }
        }
    }

    // Close input and output file
    if(fileRead){
        pfile.close();
    }
    opfile.close();

    // Ask user who they are looking for and try to find them
    cout << "Which person are you looking for? " << endl;
    getline(cin, choice);

    if(pTypeChoice == "person"){
        if((index = findPerson(pList, choice)) != -1){
            cout << "Found your person: " << endl;
            pList[index]->writePerson(cout);
        }
        else{
            cout << "Couldn't find your person: " << choice << endl;
        }
    }
    else if(pTypeChoice == "customer"){
        if((index = findPerson(cList, choice)) != -1){
            cout << "Found your person: " << endl;
            cList[index]->writePerson(cout);
        }
        else{
            cout << "Couldn't find your person: " << choice << endl;
        }
    }
    else{
        if((index = findPerson(mcList, choice)) != -1){
            cout << "Found your person: " << endl;
            mcList[index]->writePerson(cout);
        }
        else{
            cout << "Couldn't find your person: " << choice << endl;
        }
    }

    // Deallocate memory
    delete[] pList;
    delete[] cList;
    delete[] mcList;

    return 0;
}

