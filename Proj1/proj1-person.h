//
// Created by kdyso on 8/27/2023.
//

#ifndef PROJ1_PROJ1_PERSON_H
#define PROJ1_PROJ1_PERSON_H

#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

istream &getAPersonFromStream(istream &, Person *); // reads a single Person from the stream
void sortPersonArrayByAge(Person **, int); // implements selection sort ascending order
void sortPersonArrayByName(Person **, int); // implements bubble sort ascending order
Person * findAPerson(Person **, int, string); // implements linear search
void displayAPerson(ostream &, const Person *); // writes a single Person to the stream

#endif //PROJ1_PROJ1_PERSON_H
