// File: proj4-testmain.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 4
// Due Date: 9/25/2023

// Date Modified: 9/15/2023
//     -File created
// Date Modified: 2/24/2023
//     -File Finished
// Test cases are implemented.

#include <iostream>
#include <fstream>
#include "proj4-ItemInfo.hpp"

using namespace std;

int main(){
    ifstream inFile;
    ItemInfo arr1;
    ItemInfo arr2;
    ItemInfo arr3;
    ItemInfo arr4;

    // Testing file
    inFile.open("proj4-productServices.csv");
    if(!inFile){
        printCString(cout, "Bad file name\n");
        return 1;
    }
    else{
        printCString(cout, "File success\n");
    }

    // Testing setItemId(), getItemId(), and printCString()

    printCString(cout, "Testing Item Id Functions\n\n");

    arr1.setItemId("12345\0");
    printCString(cout, "Should be: 12345\n\0");
    printCString(cout, "Is: ");
    cout << arr1.getItemId();
    printCString(cout, "\n\n");

    arr2.setItemId("29520\0");
    printCString(cout, "Should be: 29520\n\0");
    printCString(cout, "Is: ");
    cout << arr2.getItemId();
    printCString(cout, "\n\n");

    arr3.setItemId("76706\0");
    printCString(cout, "Should be: 76706\n\0");
    printCString(cout, "Is: ");
    cout << arr3.getItemId();
    printCString(cout, "\n\n");

    arr4.setItemId("67890\0");
    printCString(cout, "Should be: 67890\n\0");
    printCString(cout, "Is: ");
    cout << arr4.getItemId();
    printCString(cout, "\n\n");

    // Testing setDescription() and getDescription()

    printCString(cout, "Testing Description Functions\n\n");

    arr1.setDescription("Coffee\0");
    printCString(cout, "Should be: Coffee\n\0");
    printCString(cout, "Is: ");
    printCString(cout, arr1.getDescription());
    printCString(cout, "\n\n");

    arr2.setDescription("Chips\0");
    printCString(cout, "Should be: Chips\n\0");
    printCString(cout, "Is: ");
    printCString(cout, arr2.getDescription());
    printCString(cout, "\n\n");

    arr3.setDescription("Quesadilla\0");
    printCString(cout, "Should be: Quesadilla\n\0");
    printCString(cout, "Is: ");
    printCString(cout, arr3.getDescription());
    printCString(cout, "\n\n");

    arr4.setDescription("Espresso\0");
    printCString(cout, "Should be: Espresso\n\0");
    printCString(cout, "Is: ");
    printCString(cout, arr4.getDescription());
    printCString(cout, "\n\n");

    //Testing setManCost(), getManCost(), and stuCstrToDbl

    printCString(cout, "Testing Man Cost Functions\n");
    cout.put('\n');

    arr1.setManCost("3.49\0");
    printCString(cout, "Should be: 3.49\n\0");
    printCString(cout, "Is: ");
    cout << arr1.getManCost();
    printCString(cout, "\n\n");

    arr2.setManCost("1.99\0");
    printCString(cout, "Should be: 1.99\n\0");
    printCString(cout, "Is: ");
    cout << arr2.getManCost();
    printCString(cout, "\n\n");

    arr3.setManCost("2.18\0");
    printCString(cout, "Should be: 2.18\n\0");
    printCString(cout, "Is: ");
    cout << arr3.getManCost();
    printCString(cout, "\n\n");

    arr4.setManCost("1.01\0");
    printCString(cout, "Should be: 1.01\n\0");
    printCString(cout, "Is: ");
    cout << arr4.getManCost();
    printCString(cout, "\n\n");

    //Testing setSellPrice() and getSellPrice()

    printCString(cout, "Testing Sell Price Functions\n\n");

    arr1.setSellPrice("15.99\0");
    printCString(cout, "Should be: 15.99\n\0");
    printCString(cout, "Is: ");
    cout << arr1.getSellPrice();
    printCString(cout, "\n\n");

    arr2.setSellPrice("8.99\0");
    printCString(cout, "Should be: 8.99\n\0");
    printCString(cout, "Is: ");
    cout << arr2.getSellPrice();
    printCString(cout, "\n\n");

    arr3.setSellPrice("10.99\0");
    printCString(cout, "Should be: 10.99\n\0");
    printCString(cout, "Is: ");
    cout << arr3.getSellPrice();
    printCString(cout, "\n\n");

    arr4.setSellPrice("5.99\0");
    printCString(cout, "Should be: 5.99\n\0");
    printCString(cout, "Is: ");
    cout << arr4.getSellPrice();
    printCString(cout, "\n\n");

    //Testing stuCstrLen()

    printCString(cout, "Testing String Length Function\n\n");

    printCString(cout, "Coffee should be: 6\n\0");
    printCString(cout, "Is: ");
    cout << stuCstrLen("Coffee");
    printCString(cout, "\n\n");

    printCString(cout, "Chips should be: 5\n\0");
    printCString(cout, "Is: ");
    cout << stuCstrLen("Chips");
    printCString(cout, "\n\n");

    printCString(cout, "Quesadilla should be: 10\n\0");
    printCString(cout, "Is: ");
    cout << stuCstrLen("Quesadilla");
    printCString(cout, "\n\n");

    printCString(cout, "Espresso should be: 8\n\0");
    printCString(cout, "Is: ");
    cout << stuCstrLen("Espresso");
    printCString(cout, "\n\n");

    //Testing calcProfit()

    printCString(cout, "Testing Calc Profit Function\n\n");

    printCString(cout, "Should be: 12.5\n\0");
    printCString(cout, "Is: ");
    cout << arr1.calcProfit();
    printCString(cout, "\n\n");

    printCString(cout, "Should be: 7\n\0");
    printCString(cout, "Is: ");
    cout << arr2.calcProfit();
    printCString(cout, "\n\n");

    printCString(cout, "Should be: 8.81\n\0");
    printCString(cout, "Is: ");
    cout << arr3.calcProfit();
    printCString(cout, "\n\n");

    printCString(cout, "Should be: 4.98\n\0");
    printCString(cout, "Is: ");
    cout << arr4.calcProfit();
    printCString(cout, "\n\n");


    //Testing toAmazonJSON(), stuDblToCstr(), and stuStrCpy()

    printCString(cout, "Testing Amazon JSON Function\n\n");

    arr1.toAmazonJSON(cout);
    cout.put('\n');

    arr2.toAmazonJSON(cout);
    cout.put('\n');

    arr3.toAmazonJSON(cout);
    cout.put('\n');

    arr4.toAmazonJSON(cout);
    cout.put('\n');

    //Testing displayInfo()
    printCString(cout, "Testing Display Item Info Function\n\n");

    arr1.displayItemInfo(cout);
    cout.put('\n');

    arr2.displayItemInfo(cout);
    cout.put('\n');

    arr3.displayItemInfo(cout);
    cout.put('\n');

    arr4.displayItemInfo(cout);
    cout.put('\n');

    return 0;
}
