// File: proj2-main.cpp
// Author: Prof. Matthew Aars
// Course: CSI 1440 02
// Assignment: Project 2
// Due Date: 9/05/2023

// Date Modified: 8/31/2023
//     -File created
// Date Modified: 9/03/2023
//     -File finished
// Test cases are implemented.


#include <iostream>
#include "proj2-arrayFunctions.h"

using namespace std;

int main()
{
    // Test arrays
    int *testOne{new int[5]{-1, 5, 3, 4, 0}};
    int *testTwo{new int [6]{78, 9, 4, 26, 100, 1}};
    int *testThree{new int[2]{8, 8}};
    int *testFour{new int[1]{65}};
    int *testFive{new int[3]{-45, 0, -8}};

    cout << "Testing bubbleSort()" << endl << endl;
    cout << "Test One should be: -1, 0, 3, 4, 5" << endl;
    cout << "Test One is: ";
    bubbleSort(testOne, 5);
    for(int i = 0; i < 5;i ++){
        cout << testOne[i] << ", ";
    }
    cout << endl << endl;

    cout << "Test Two should be: 1, 4, 9, 26, 78, 100" << endl;
    cout << "Test Two is: ";
    bubbleSort(testTwo, 6);
    for(int i = 0; i < 6; i++){
        cout << testTwo[i] << ", ";
    }
    cout << endl << endl;

    cout << "Test Three should be: 8, 8" << endl;
    cout << "Test Three is: ";
    bubbleSort(testThree, 2);
    for(int i = 0; i < 2; i++){
        cout << testThree[i] << ", ";
    }
    cout << endl << endl;

    cout << "Test Four should be: 65" << endl;
    cout << "Test Four is: ";
    bubbleSort(testFour, 1);
    for(int i = 0; i < 1; i++){
        cout << testFour[i];
    }
    cout << endl << endl;

    cout << "Test Five should be: -45, -8, 0" << endl;
    cout << "Test Five is: ";
    bubbleSort(testFive, 3);
    for(int i = 0; i < 3; i++){
        cout << testFive[i] << ", ";
    }
    cout << endl << endl;

    // Testing the largestValue() function
    cout << "Testing largestValue()" << endl << endl;

    // Display the largest value of each array
    cout << "Test One should be: 5" << endl;
    cout << "Test One is: " << largestValue(testOne, 5) << endl << endl;

    cout << "Test Two should be: 100" << endl;
    cout << "Test Two is: " << largestValue(testTwo, 6) << endl << endl;

    cout << "Test Three should be: 8" << endl;
    cout << "Test Three is: " << largestValue(testThree, 2) << endl << endl;

    cout << "Test Four should be: 65" << endl;
    cout << "Test Four is: " << largestValue(testFour, 1) << endl << endl;

    cout << "Test Five should be: 0" << endl;
    cout << "Test Five is: " << largestValue(testFive, 3) << endl << endl;

    // Testing smallestValue() function
    cout << "Testing smallestValue()" << endl << endl;

    // Display the smallest value of each array
    cout << "Test One should be: -1" << endl;
    cout << "Test One is: " << smallestValue(testOne, 5) << endl << endl;

    cout << "Test Two should be: 1" << endl;
    cout << "Test Two is: " << smallestValue(testTwo, 6) << endl << endl;

    cout << "Test Three should be: 8" << endl;
    cout << "Test Three is: " << smallestValue(testThree, 2) << endl << endl;

    cout << "Test Four should be: 65" << endl;
    cout << "Test Four is: " << smallestValue(testFour, 1) << endl << endl;

    cout << "Test Five should be: -45" << endl;
    cout << "Test Five is: " << smallestValue(testFive, 3) << endl << endl;

    // Testing the averageValue() function
    cout << "Testing averageValue()" << endl << endl;

    // Display the average value of each array
    cout << "Test One should be: 2.2" << endl;
    cout << "Test One is: " << averageValue(testOne, 5) << endl << endl;

    cout << "Test Two should be: 36.33..." << endl;
    cout << "Test Two is: " << averageValue(testTwo, 6) << endl << endl;

    cout << "Test Three should be: 8" << endl;
    cout << "Test Three is: " << averageValue(testThree, 2) << endl << endl;

    cout << "Test Four should be: 65" << endl;
    cout << "Test Four is: " << averageValue(testFour, 1) << endl << endl;

    cout << "Test Five should be: -17.66..." << endl;
    cout << "Test Five is: " << averageValue(testFive, 3) << endl << endl;

    // Testing the medianValue() function
    cout << "Testing medianValue()" << endl << endl;

    // Display the median value of each array
    cout << "Test One should be: 3" << endl;
    cout << "Test One is: " << medianValue(testOne, 5) << endl << endl;

    cout << "Test Two should be: 9" << endl;
    cout << "Test Two is: " << medianValue(testTwo, 6) << endl << endl;

    cout << "Test Three should be: 8" << endl;
    cout << "Test Three is: " << medianValue(testThree, 2) << endl << endl;

    cout << "Test Four should be: 65" << endl;
    cout << "Test Four is: " << medianValue(testFour, 1) << endl << endl;

    cout << "Test Five should be: -8" << endl;
    cout << "Test Five is: " << medianValue(testFive, 3) << endl << endl;

    // Deleting allocated memory
    delete[] testOne;
    delete[] testTwo;
    delete[] testThree;
    delete[] testFour;
    delete[] testFive;

    return 0;
}


