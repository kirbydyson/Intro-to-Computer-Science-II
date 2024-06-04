// File: proj10-driver.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 10
// Due Date: 12/04/2023

// Date Modified: 11/28/2023
//     -File created
// Date Modified: 12/02/2023
//     -File finished
// Driver for queue1, queue2, and queue3

#include <iostream>
#include "proj10-Queue1.h"
#include "proj10-Queue2.h"
#include "proj10-Queue3.h"
#include <ctime>

using namespace std;

int main() {
    Queue1<int> q1;
    Queue2<int> q2;
    Queue3<int> q3;
    int val;
    double t1, t2, t3;
    clock_t start, stop;

    //Randomize time
    srand(time(NULL));

    //Enqueue values
    for(int i = 0; i < 100; i++){
        q1.enqueue(rand() % 100);
        q2.enqueue(rand() % 100);
        q3.enqueue(rand() % 100);
    }

    //Time dequeue for q1
    start = clock();
    for(int i = 0; i < 100; ++i){
        q1.dequeue(val);
    }
    stop = clock();

    t1 = stop - start;
    cout << "Time for Queue1: " << t1 << endl;

    //Time dequeue for q2
    start = clock();
    for(int i = 0; i < 100; ++i){
        q2.dequeue(val);
    }
    stop = clock();

    t2 = stop - start;
    cout << "Time for Queue2: " << t2 << endl;

    //Time dequeue for q3
    start = clock();
    for(int i = 0; i < 100; ++i){
        q3.dequeue(val);
    }
    stop = clock();

    t3 = stop - start;
    cout << "Time for Queue3: " << t3 << endl;


    return 0;
}
