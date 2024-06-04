// File: proj2-main.cpp
// Author: Prof. Matthew Aars
// Course: CSI 1440 02
// Assignment: Project 2
// Due Date: 9/05/2023

// Date Modified: 8/31/2023
//     -File created
// Date Modified: 9/03/2023
//     -File finished
// Unknown numbers are read from integer arrays in a file. Each array will be
// temporarily stores in a dynamically allocated array. The largest, smallest,
// average, and median values of each array will be displayed along with the
// overall largest and smallest values

#include <iostream>
#include <fstream>
#include <sstream>
#include "proj2-arrayFunctions.h"

using namespace std;

int main() {
    // Declare and initialize variables
    ifstream inFile;
    stringstream inSS;
    string data;
    int min, max, med, s, small_min, large_max;
    double avg;
    int count = 0;
    int *arrayPtr;

    // Open file
    inFile.open("arrays.txt");

    //If file fails to open, print error message
    if(!inFile) {
        cout << "Error: Unable to open file" << endl;
        return 1;
    }

    // As long as file is reading array size
    while(inFile >> s){
        inFile.ignore();
        getline(inFile, data);
        inSS.clear();
        inSS << data;

        arrayPtr = new int[s]; // Dynamically allocating array
        count++; // Keeping track of array numbers

        // Storing values in stringstream
        for(int i = 0; i < s; i++) {
            inSS >> arrayPtr[i];
        }

        bubbleSort(arrayPtr, s);
        // Assigning min, max, average, and median for each array
        min = smallestValue(arrayPtr, s);
        max = largestValue(arrayPtr, s);
        avg = averageValue(arrayPtr, s);
        med = medianValue(arrayPtr, s);

        // If there is only one array
        if(count == 1){
            small_min = min;
            large_max = max;
        }
        // If current min is less than overall min
        if(min < small_min){
            small_min = min;
        }
        // If current max is more than overall max
        if(max > large_max){
            large_max = max;
        }

        // Display  min, max, average, and median for each array
        cout << "Values for array #" << count << ":" << endl;
        cout << "Largest value: " << max << endl;
        cout << "Smallest value: " << min << endl;
        cout << "Average value: " << avg << endl;
        cout << "Median value: " << med << endl << endl;

        delete[] arrayPtr; // Free memory allocated for array
    }
    inFile.close();

    // Display overall largest and smallest values of all arrays
    cout << "Overall largest value: " << large_max << endl;
    cout << "Overall smallest value: " << small_min << endl;

    return 0;
}
