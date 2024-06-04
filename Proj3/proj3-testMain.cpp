// File: proj3-testMain.cpp
// Author: Prof. Matthew Aars
// Course: CSI 1440 02
// Assignment: Project 3
// Due Date: 9/11/2023

// Date Modified: 9/5/2023
//     -File created
// Date Modified: 9/10/2023
//     -File finished
//  Test cases are implemented.

#include "proj3-MyString.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    MyString a; // default
    MyString b("! ");
    MyString c("Kirby Dyson ");
    MyString d("Baylor Bears ");
    MyString e("1234 ");

    // Testing default constructor
    cout << "***Testing default constructor***" << endl << endl;

    cout << "Should be blank" << endl;
    cout << "Is: " << a << endl;
    cout << "Should be zero" << endl;
    cout << "Is: " << a.length() << endl << endl;

    // Testing constructor with initialized character string
    // Testing length function
    // Testing overloaded insertion operator
    cout << "***Testing constructor with initialized character string***" << endl;
    cout << "***Testing length function***" << endl;
    cout << "***Testing overloaded insertion operator***" << endl << endl;

    cout << "Should be ! with a 2" << endl;
    cout << "Is: " << b << b.length() << endl;
    cout << "Should be Kirby Dyson with 12" << endl;
    cout << "Is: " << c << c.length() << endl;
    cout << "Should be Baylor Bears with a 13" << endl;
    cout << "Is: " << d << d.length() << endl;
    cout << "Should be 1234 with a 5" << endl;
    cout << "Is: " << e << e.length() << endl << endl;

    // Testing copy constructor
    MyString f(c); // copy
    MyString g(e); // copy
    MyString h(a); // copy
    MyString i(b); // copy

    cout << "***Testing copy constructor***" << endl << endl;

    cout << "Should be Kirby Dyson with 12" << endl;
    cout << "Is: " << f << f.length() << endl;
    cout << "Should be 1234 with a 5" << endl;
    cout << "Is: " << g << g.length() << endl;
    cout << "Should be blank with a 0" << endl;
    cout << "Is: " << h << h.length() << endl;
    cout << "Should be ! with a 2" << endl;
    cout << "Is: " << i << i.length() << endl << endl;

    // Testing overloaded assignment operator
    cout << "***Testing operator =***" << endl << endl;

    b = c;
    cout << "b should now have Kirby Dyson: " << endl;
    cout << "b has: " << b << endl;
    a = d;
    cout << "a should now have Baylor Bears: " << endl;
    cout << "a has: " << a << endl;
    d = e;
    cout << "d should now have 1234: " << endl;
    cout << "d has: " << d << endl;
    c = b;
    cout << "c should have Kirby Dyson again: " << endl;
    cout << "c has: " << c << endl << endl;

    // Testing overloaded equivalence relational operator
    cout << "***Testing operator ==***" << endl << endl;

    cout << "Should be: b and e are not equal" << endl;
    if(b == e){
        cout << "Error: b and e are equal" << endl;
    }
    else{
        cout << "Is: b and e are not equal" << endl;
    }
    cout << "Should be: c and d are not equal" << endl;
    if(c == d){
        cout << "Error: c and d are equal" << endl;
    }
    else{
        cout << "Is: c and d are not equal" << endl;
    }
    cout << "Should be: a and c are not equal" << endl;
    if(a == c){
        cout << "Error: a and c are equal" << endl;
    }
    else{
        cout << "Is: a and c are not equal" << endl;
    }
    cout << "Should be: e and g are equal" << endl;
    if(e == g){
        cout << "Is: e and g are equal" << endl;
    }
    else{
        cout << "Error: e and g are not equal" << endl;
    }
    cout << "Should be: c and c are equal" << endl;
    if(c == c){
        cout << "Is: c and c are equal" << endl;
    }
    else{
        cout << "Error: c and c are equal" << endl;
    }
    cout << endl;

    // Testing += operator to concatenate two MyStrings
    cout << "***Testing operator +=***" << endl << endl;

    d += e;
    cout << "Should be 1234 1234" << endl;
    cout << "d += e is: " << d << endl;
    c += a;
    cout << "Should be Kirby Dyson Baylor Bears" << endl;
    cout << "c += a is: " << c << endl;
    b += b;
    cout << "Should be Kirby Dyson Kirby Dyson" << endl;
    cout << "b += b is: " << b << endl;
    a += h;
    cout << "Should be Baylor Bears" << endl;
    cout << "a += h is: " << a << endl;
    cout << endl;

    // Testing creating a new MyString object to concatenate two MyString objects
    cout << "***Testing operator +***" << endl << endl;

    d = d + e;
    cout << "Should be 1234 1234 1234" << endl;
    cout << "d + e = " << d << endl;
    c = c + a;
    cout << "Should be Kirby Dyson Baylor Bears Baylor Bears" << endl;
    cout << "c + a = " << c << endl;
    b = b + b;
    cout << "Should be Kirby Dyson Kirby Dyson Kirby Dyson Kirby Dyson" << endl;
    cout << "b + b = " << b << endl;
    a = a + h;
    cout << "Should be Baylor Bears" << endl;
    cout << "a + h = " << a << endl;
    cout << endl;

    // Testing that function reads an entire line from a istream and lines are
    // terminated with delimit which is newline '\n' by default
    cout << "***Testing getline function***" << endl << endl;
    stringstream inSS;

    cout << "Should output: Hello World!" << endl;
    inSS.str("Hello World!");
    a.getline(inSS);
    cout << "Is: " << a << endl << endl;
    inSS.clear();

    cout << "Should output: I love coffee!" << endl;
    inSS.str("I love coffee!");
    a.getline(inSS);
    cout << "Is: " << a << endl << endl;
    inSS.clear();

    cout << "Should ouput: 29520" << endl;
    inSS.str("29520");
    a.getline(inSS);
    cout << "Is: " << a << endl << endl;
    inSS.clear();

    cout << "Live, laugh, love, compsci :)" << endl;
    inSS.str("Live, laugh, love, compsci :)");
    a.getline(inSS);
    cout << "Is: " <<  a << endl;
    inSS.clear();


    return 0;
}