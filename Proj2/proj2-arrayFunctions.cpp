// File: proj2-main.cpp
// Author: Prof. Matthew Aars
// Course: CSI 1440 02
// Assignment: Project 2
// Due Date: 9/05/2023

// Date Modified: 8/31/2023
//     -File created
// Date Modified: 9/03/2023
//     -File finished
// Functions are defined from proj2-arrayFunctions.h

#include <iostream>
#include "proj2-arrayFunctions.h"

using namespace std;

/*
 *bubbleSort
 *
 *This function sorts the array in ascending order
 *
 *Parameters:
 *    n: pointer array and integer
 *
 *Output:
 *    return: void
 *    reference parameters: none
 *    stream: none
*/
void bubbleSort(int *array, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j + 1]);
            }
        }
    }
}

/*
 *largestValue
 *
 *This function displays the largest value in the array
 *
 *Parameters:
 *    n: pointer array and integer
 *
 *Output:
 *    return: integer
 *    reference parameters: none
 *    stream: none
*/
int largestValue(int *array, int size){
    int max = array[0];

    for(int i = 1; i < size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

/*
 *smallestValue
 *
 *This function displays the smallest value in the array
 *Parameters:
 *    n: pointer array and integer
 *
 *Output:
 *    return: integer
 *    reference parameters: none
 *    stream: none
*/
int smallestValue(int *array, int size){
    int min = array[0];

    for(int i = 1; i < size; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    return min;
}

/*
 *averageValue
 *This function displays the average value of the array
 *
 *Parameters:
 *    n: pointer array and integer
 *
 *Output:
 *    return: double
 *    reference parameters: none
 *    stream: none
*/
double averageValue(int *array, int size){
    int count = 0;
    int sum = 0;
    double avg = 0;

    for(int i = 0; i < size; i++){
        sum += array[i];
        count++;
    }
    avg = static_cast<double>(sum) / count;

    return avg;
}

/*
 *medianValue
 *
 *This function displays the median value of the sorted array
 *
 *Parameters:
 *    n: pointer array and integer
 *
 *Output:
 *    return: integer
 *    reference parameters: none
 *    stream: none
*/
int medianValue(int *array, int size){
    int med = 0;

    if(size % 2 == 0){
        med = array[(size / 2) - 1];
    }
    else{
        med = array[size / 2];
    }

    return med;
}


