// File: proj7-TestMain.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 7
// Due Date: 10/30/2023

// Date Modified: 10/17/2023
//     -File created
// Date Modified: 10/24/2023
//     -File finished

#include <iostream>
#include "proj7-MyVector.h"

using namespace std;

int main(){
    MyVector<int> a;

    cout << "Testing default constructor and getSize" << endl;
    cout << "Should be: 0" << endl;
    cout << "Is: " << a.getSize() << endl << endl;

    cout << "Testing isEmpty()" << endl;
    cout << "Should be: a is empty" << endl << "Is: ";
    if(a.isEmpty()){
        cout << "a is empty" << endl;
    }
    else{
        cout << "isEmpty() failed" << endl;
    }
    cout << endl;

    cout << "Testing pushFront and operator[]" << endl;
    a.pushFront(4);
    a.pushFront(3);
    a.pushFront(2);
    a.pushFront(1);
    a.pushFront(0);
    cout << "Should be: 0 1 2 3 4" << endl << "Is: ";
    for(int i = 0; i < a.getSize(); i++){
        cout << a[i] << " ";
    }
    cout << endl << "Should be: 5" << endl;
    cout << "Is: " << a.getSize() << endl << endl;

    cout << "Testing isEmpty after values are entered" << endl;
    cout << "Should be: a is not empty" << endl << "Is: ";
    if(a.isEmpty()){
        cout << "Error: Should not be empty" << endl;
    }
    else{
        cout << "a is not empty" << endl;
    }
    cout << endl;

    cout << "Testing copy constructor" << endl;
    MyVector<int> b(a);
    cout << "a and b should match" << endl << "a: ";
    for(int i = 0; i < a.getSize(); i++){
        cout << a[i] << " ";
    }
    cout << endl << "b: ";
    for(int i = 0; i < b.getSize(); i++){
        cout << b[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing the overloaded equivalence operator" << endl;
    MyVector<int> c;
    c = b;
    cout << "b and c should match" << endl << "c: ";
    for(int i = 0; i < c.getSize(); i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing pushBack and shiftRight" << endl;
    cout << "Should be: 0 1 2 3 4 5 6 7 8 9" << endl << "Is: ";
    a.pushBack(5);
    a.pushBack(6);
    a.pushBack(7);
    a.pushBack(8);
    a.pushBack(9);
    for(int i = 0; i < a.getSize(); i++){
        cout << a[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing back function" << endl;
    cout << "Should be: 9" << endl;
    cout << "Is: " << a.back() << endl;
    a.pushBack(10);
    cout << "Should be: 10" << endl;
    cout << "Is: " << a.back() << endl << endl;

    cout << "Testing front function" << endl;
    cout << "Should be: 0" << endl;
    cout << "Is: " << a.front() << endl;
    a.pushFront(-1);
    cout << "Should be: -1" << endl;
    cout << "Is: " << a.front() << endl << endl;

    cout << "Testing grow function" << endl;
    cout << "Should output: -1 0 1 2 3 4 5 6 7 8 9 10" << endl << "Is: ";
    for(int i = 0; i < a.getSize(); i++){
        cout << a[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing popBack function" << endl;
    int d, e;
    a.popBack(d);
    cout << "Should return: 10" << endl << "Is: " <<  d << endl;
    a.popBack(e);
    cout << "Should return: 9" << endl << "Is: " << e << endl << endl;

    cout<< "Testing popFront and shiftLeft" << endl;
    int f, g;
    a.popFront(f);
    cout << "Should return: -1" << endl << "Is: " << f << endl;
    a.popFront(g);
    cout << "Should return: 0" << endl << "Is: " << g << endl << endl;

    cout << "Testing erase function" << endl;
    a.erase();
    b.erase();
    if(a.isEmpty() && b.isEmpty()) {
        cout << "Erase function worked, a and b are empty" << endl;
    }
    else{
        cout << "Error: erase() failed" << endl;
    }
    cout << endl;

    cout << "Testing BADINDEX" << endl;
    int x;
    try{
        a.popFront(x);
        cout << "popFront Error";
    }
    catch(BADINDEX ex){
        cout << "popFront BADINDEX successful";
    }
    cout << endl;

    try{
        a.popBack(x);
        cout << "popBack Error";
    }
    catch(BADINDEX ex){
        cout << "popBack BADINDEX successful";
    }
    cout << endl;

    try{
        b.front();
        cout << "front() Error";
    }
    catch(BADINDEX ex){
        cout << "front BADINDEX successful";
    }
    cout << endl;

    try{
        b.back();
        cout << "back() Error";
    }
    catch(BADINDEX ex){
        cout << "back BADINDEX successful";
    }
    cout << endl;

    try{
        c[x];
        cout << "operator[] Error";
    }
    catch(BADINDEX ex){
        cout << "operator[] BADINEX successful";
    }
    cout << endl << endl;

    cout << "Testing with strings instead of ints" << endl;
    MyVector<string> k;
    k.pushBack("Kirby");
    k.pushBack("Coffee");
    k.pushBack("CompSci");
    k.pushBack("Hello World");
    k.pushBack("Goodbye World");
    k.pushBack(":)");
    cout << "Should be: Kirby Coffee CompSci Hello World Goodbye World :)" << endl << "Is: ";
    for(int i = 0; i < k.getSize(); i++){
        cout << k[i] << " ";
    }
    cout << endl << "Should be: 6" << endl << "Is: " << k.getSize() << endl;

    return 0;
}
