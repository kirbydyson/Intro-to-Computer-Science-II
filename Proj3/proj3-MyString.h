// File: proj3-MyString.h
// Author: Prof. Matthew Aars
// Course: CSI 1440 02
// Assignment: Project 3
// Due Date: 9/11/2023

// Date Modified: 9/5/2023
//     -File created
// Date Modified: 9/10/2023
//     -File finished
// Functions are created

#ifndef PROJ3_PROJ3_MYSTRING_H
#define PROJ3_PROJ3_MYSTRING_H

#include <iostream>

using namespace std;

const int CAP = 10;

class MyString{
private:
    // The number of characters currently stored in the string
    // object. Do NOT count the NULL character.
    int size;
    // The number of bytes currently allocated. This should always
    // be at least size + 1. The extra byte is needed to store the
    // NULL character.
    int capacity;
    // Character pointer that points to an array of characters.
    char *data;

public:
    /*
     *MyString
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
    MyString( );

    /*
     *MyString
     *
     *This function is the constructor with an initializing character string
     *
     *Parameters:
     *    const char pointer
     *
     *Output:
     *    return: none
     *    reference parameters: none
     *    stream: none
    */
    MyString(const char *);

    /*
     *~MyString
     *
     *This function is the destructor
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: none
     *    reference parameters: none
     *    stream: none
    */
    ~MyString( );

    /*
     *MyString
     *
     *This function is the copy constructor
     *
     *Parameters:
     *    const MyString reference
     *
     *Output:
     *    return: none
     *    reference parameters: const MyString
     *    stream: none
    */
    MyString(const MyString &);

    /*
     *Operator =
     *
     *This function is the overloaded assignment operator, make a copy of
     *MyString object
     *
     *Parameters:
     *    const MyString reference
     *
     *Output:
     *    return: reference to object of MyString
     *    reference parameters: const MyString
     *    stream: none
    */
    MyString& operator = (const MyString&);

    /*
     *operator ==
     *
     *This function is the overloaded equivalence relational
     *operator
     *
     *Parameters:
     *    const MyString reference
     *
     *Output:
     *    return: bool
     *    reference parameters: MyString&
     *    stream: none
    */
    bool operator == (const MyString&) const;

    /*
     *operator [ ]
     *
     *This function should return a char by reference
     *
     *Parameters:
     *    integer
     *
     *Output:
     *    return: character by reference
     *    reference parameters: none
     *    stream: none
    */
    char& operator [ ] (int);

    /*
     *operator +=
     *
     *This function is used to concatenate two MyStrings
     *
     *Parameters:
     *    const MyString reference
     *
     *Output:
     *    return: void
     *    reference parameters: const MyString
     *    stream: none
    */
    void operator += (const MyString&);

    /*
     *operator +
     *
     *This function should create a new MyString object that is the concatenation
     *of two MyString objects
     *
     *Parameters:
     *    const MyString reference
     *
     *Output:
     *    return: object of MyString
     *    reference parameters: const MyString
     *    stream: none
    */
    MyString operator + (const MyString&) const;

    /*
     *getline
     *
     *This function reads an entire line from a istream. Lines are terminated with
     * delimit which is newline '\n' by default
     *
     *Parameters:
     *    istream reference and character
     *
     *Output:
     *    return: void
     *    reference parameters: istream
     *    stream: istream reference
    */
    void getline(istream&, char delimit = '\n');

    /*
     *length
     *
     *This function should return the length of the string
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: integer
     *    reference parameters: none
     *    stream: none
    */
    int length( ) const;

    /*
     *operator<<
     *
     *This function overloaded insertion operator
     *
     *Parameters:
     *    n:ostream reference and MyString reference
     *
     *Output:
     *    return: reference to an ostream
     *    reference parameters: ostream and MyString
     *    stream: ostream
    */
    friend ostream& operator<< (ostream&, MyString&);

};

#endif //PROJ3_PROJ3_MYSTRING_H
