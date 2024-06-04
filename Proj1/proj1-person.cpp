// File: proj1-person.cpp
// Author: Prof. Matthew Aars
// Course: CSI 1440 02
// Assignment: Project 1
// Due Date: 8/28/2023

// Date Modified: 8/24/2023
//     -File created
// Date Modified: 8/27/2023
//     -File finished
// Functions are defined from the .hpp

#include "proj1-person.h"

/*
 *getAPersonFromStream
 *
 *This function creates the pointer of the age and name from a file
 *
 *Parameters:
 *    n: istream and person pointers
 *
 *Output:
 *    return: istream of data
 *    reference parameters: data
 *    stream: istream
*/
istream &getAPersonFromStream(istream &data, Person *person){
    string name;
    int age;

    getline(data, name, ',');
    person->name = name;
    data >> age;
    person->age = age;

    return data;
}

/*
 *sortPersonArrayByAge
 *
 *This function sorts an array of people by age using pointers
 *
 *Parameters:
 *    n: integer and person pointer pointer
 *
 *Output:
 *    return: void
 *    reference parameters: none
 *    stream: none
*/
void sortPersonArrayByAge(Person **person, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(person[j]->age > person[j + 1]->age){
                swap(person[j], person[j + 1]);
            }
        }
    }
}

/*
 *sortPersonArrayByName
 *
 *This function sorts an array of people by name using pointers
 *
 *Parameters:
 *    n: integer and person pointer pointer
 *
 *Output:
 *    return: void
 *    reference parameters: none
 *    stream: none
*/
void sortPersonArrayByName(Person **person, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(person[j]->name > person[j + 1]->name){
                swap(person[j], person[j + 1]);
            }
        }
    }
}

/*
 *findAPerson
 *
 *This function finds a person's name using pointers
 *
 *Parameters:
 *    n: person pointer pointer, integer, and string
 *
 *Output:
 *    return: pointer
 *    reference parameters: none
 *    stream: none
*/
Person * findAPerson(Person **person, int n, string name){
    for(int i = 0; i < n; i++){
        if(person[i]->name == name){
            return person[i];
        }
    }
    return nullptr;
}

/*
 *displayAPerson
 *
 *This function outputs the people's name and age
 *
 *Parameters:
 *    n: ostream, constant person pointer
 *
 *Output:
 *    return: void
 *    reference parameters: out
 *    stream: none
*/
void displayAPerson(ostream &out, const Person *person){
    out << person->name << ", " << person->age << endl;
}

