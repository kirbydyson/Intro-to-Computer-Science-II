// File: proj3-MyString.cpp
// Author: Prof. Matthew Aars
// Course: CSI 1440 02
// Assignment: Project 3
// Due Date: 9/11/2023

// Date Modified: 9/5/2023
//     -File created
// Date Modified: 9/10/2023
//     -File finished
// Functions are defined from "proj3-MyString.h"

#include "proj3-MyString.h"

// default constructor
MyString::MyString( ){
    this->size = 0;
    this->capacity = CAP;
    this->data = new char[this->capacity];
    this->data[this->size] = '\0';
}

// convert constructor
MyString::MyString(const char *s){
    int i = 0;
    this->size = 0;
    this->capacity = CAP;
    // count characters in string
    while (s[i] != '\0'){
        this->size++;
        i++;
    }

    // double capacity if size exceeds capacity
    while(this->size >= this->capacity){
        this->capacity *= 2;
    }

    // allocate memory
    this->data = new char[this->capacity];
    // copy characters from input string to string object
    for(int j = 0; j < this->size; j++) {
        this->data[j] = s[j];
    }
    this->data[this->size] = '\0';
}

// destructor
MyString::~MyString( ){
    // deallocate memory
    delete[] data;
}

// copy constructor
MyString::MyString(const MyString& other){
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new char [this->capacity];

    // copy data
    for (int i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
    this->data[this->size] = '\0';
}

// overloaded assignment operator
MyString& MyString::operator = (const MyString& other){
    // if objects are not the same
    if(this != &other) {
        delete[] this->data;
        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new char [this->capacity];

        // copy data
        for(int i = 0; i < size; i++){
            this->data[i] = other.data[i];
        }

        this->data[this->size] = '\0';
    }
    return *this;
}

// overloaded equivalence relational operator
bool MyString::operator == (const MyString& other) const{
    bool equal = true;

    // if sizes are not equal
    if(this->size != other.size){
        equal = false;
    }

    // compare characters
    for(int i = 0; i  < this->size; i++){
        if (this->data[i] != other.data[i]) {
            equal = false;
        }
    }
    return equal;
}

// overloaded [] operator
char& MyString::operator [ ] (int i){
    return this->data[i];
}

// overloaded += operator
void MyString::operator += (const MyString& other){
    int newSize = this->size + other.size;

    // if greater than or equal to current capacity, double it
    if(newSize + 1 >= this->capacity){
        while(newSize + 1 >= this->capacity){
            this->capacity *= 2;
        }
        // temporary array with increased capacity
        char *temp = new char[this->capacity];
        // copy data
        for(int i = 0; i < this->size; i++){
            temp[i] = this->data[i];
        }
        delete[] this->data;
        this->data = temp;
    }
    // concatenate data
    for(int i = 0; i < other.size; i++){
        this->data[this->size + i] = other.data[i];
    }
    // update size
    this->size = newSize;
    this->data[newSize] = '\0';
}

// create a new MyString object that is the concatenation of two MyString
// objects
MyString MyString::operator + (const MyString& other) const{
    MyString temp = this->data;
    temp += other;
    return temp;
}

// reads line from istream
void MyString::getline(istream& in, char delimit){
    char a;
    int i = 0;

    if (delimit == '\n') {
        a = '\0';
    }
    else {
        a = '\n';
    }

    // store characters in array until delimit is reached
    while(in.get(a) && a != delimit){
        this->data[i] = a;
        i++;
        // if exceeds current capacity, double and reallocate
        if (i >= this->capacity) {
            this->capacity *= 2;
            char *temp = new char [this->capacity];
            for (int j = 0; j < i; j++) {
                temp[j] = this->data[j];
            }
            delete [] this->data;
            this->data = temp;
        }
    }
    // set size
    this->size = i;
    this->data[this->size] = '\0';

    // if string capacity is less than 25% current capacity and not equal to
    // ten, halve the capacity and reallocate
    if(this->size * 4 < this->capacity && this->capacity != 10){
        this->capacity /= 2;
        char *temp = new char [this->capacity];

        for (int j = 0; j < this->size; j++) {
            temp[j] = this->data[j];
        }

        delete[] this->data;
        this->data = temp;
    }
}

// return length of string
int MyString::length( ) const{
    return this->size;
}

// overloaded insertion operator
ostream& operator<< (ostream& out, MyString& other){
    out << other.data;
    return out;
}
