// File: proj9-TestMain.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 9
// Due Date: 11/20/2023

// Date Modified: 11/9/2023
//     -File created
// Date Modified: 11/14/2023
//     -File finished
// Test cases implemented

#include <iostream>
#include "proj9-MyList.h"

using namespace std;

int main(){
    MyList<int> a;

    cout << "Testing default constructor and getSize" << endl;
    cout << "Should be: 0" << endl;
    cout << "Is: " << a.getSize() << endl << endl;

    cout << "Testing isEmpty()" << endl;
    cout << "Should be: a is empty" << endl << "Is: ";
    if(a.isEmpty()){
        cout << "a is empty" << endl;
    }
    else{
        cout << "isEmpty test failed" << endl;
    }
    cout << endl;

    cout << "Testing getSize after values entered and pushFront" << endl;
    cout << "This also tests operator []" << endl;
    a.pushFront(4);
    a.pushFront(3);
    a.pushFront(2);
    a.pushFront(1);
    a.pushFront(0);
    cout << "Should be: 0 1 2 3 4" << endl << "Is: ";
    for(int i = 0; i < a.getSize(); i++){
        cout << a[i] << " ";
    }
    cout << endl << "Size should be: 5 " << endl;
    cout << "Is: " << a.getSize() << endl << endl;

    cout << "Testing isEmpty after values entered" << endl;
    cout << "Should be: a is not empty" << endl << "Is: ";
    if(a.isEmpty()){
        cout << "a is empty" << endl;
    }
    else{
        cout << "a is not empty" << endl;
    }
    cout << endl;

    cout << "Testing copy constructor and overloaded equivalence operator";
    cout << endl;
    MyList<int>b(a);
    MyList<int>c;
    c = b;
    cout << "a, b, and c should match" << endl;
    cout << "a: ";
    for(int i = 0; i < a.getSize(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "b: ";
    for(int i = 0; i < b.getSize(); i++){
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "c: ";
    for(int i = 0; i < c.getSize(); i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing pushBack" << endl;
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
    cout << "Should be: 9" << endl << "Is: " << a.back() << endl;
    a.pushBack(10);
    cout << "Should be: 10" << endl << "Is: " << a.back() << endl << endl;

    cout << "Testing front function" << endl;
    cout << "Should be: 0" << endl << "Is: " << a.front() << endl;
    a.pushFront(100);
    cout << "Should be: 100" << endl << "Is: " << a.front() << endl << endl;

//    cout << "Testing dequeue" << endl;
//    int d, e;
//    a.dequeue(d);
//    cout << "Should be 10" << endl << "Is: " << d << endl;
    cout << "Testing popBack function" << endl;
    int d, e;
    a.popBack(d);
    cout << "Should be: 10" << endl << "Is: " <<  d << endl;
    a.popBack(e);
    cout << "Should be: 9" << endl << "Is: " << e << endl << endl;


    cout<< "Testing popFront" << endl;
    int f, g;
    a.popFront(f);
    cout << "Should be: 100" << endl << "Is: " << f << endl;
    a.popFront(g);
    cout << "Should be: 0" << endl << "Is: " << g << endl << endl;


    cout << "Testing erase function" << endl;
    a.erase();
    b.erase();
    c.erase();
    if(a.isEmpty() && b.isEmpty() && c.isEmpty()){
        cout << "Erase function successful: a, b, and c are empty";
    }
    else{
        cout << "Error";
    }
    cout << endl << endl;

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
    cout << endl;
    return 0;

}