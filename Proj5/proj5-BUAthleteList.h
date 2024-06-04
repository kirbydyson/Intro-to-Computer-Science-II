// File: proj5-BUAthlete.h
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 5
// Due Date: 10/9/2023

// Date Modified: 9/26/2023
//     -File created
// Date Modified: 9/26/2023
//     -File finished
// Functions and class are created for BUAthlete

#ifndef PROJ5_PROJ5_BUATHLETELIST_H
#define PROJ5_PROJ5_BUATHLETELIST_H

#include <iostream>
#include <string>
#include "proj5-BUAthlete.h"

using namespace std;

class BUAthleteList{
protected:
    BUAthlete *list;
    int capacity;
    int size;
    /*
     *resizeArray
     *
     *This function resizes array by 2 when capacity is reached
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void resizeArray();

public:
    //Big Four
    BUAthleteList();
    ~BUAthleteList();
    BUAthleteList(BUAthleteList&);
    BUAthleteList& operator =(BUAthleteList&);

    /*
     *addNCAAAthlete
     *
     *This function adds a new player to the list
     *
     *Parameters:
     *    id: integer
     *    name: string
     *    loi: string
     *    school: string
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void addNCAAAthlete(int id, string name, string loi, string school);

    /*
     *setBUInfo
     *
     *This function sets the position and evaluation of a player at a certain
     * index
     *
     *Parameters:
     *    index: integer
     *    pos: Position value
     *    eval: integer
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void setBUInfo(int ndx, Position pos, int eval);

    /*
     *findByID
     *
     *This function finds a player's ID number
     *
     *Parameters:
     *    id: integer
     *
     *Output:
     *    return: integer
     *    reference parameters: none
     *    stream: none
    */
    int findByID(int id);

    /*
     *sortByID
     *
     *This function sorts the players by their ID number
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void sortByID();

    /*
     *sortByPosition
     *
     *This function sorts the players by their position
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void sortByPosition();

    /*
     *sortByEvaluation
     *
     *This function sorts the players by their evaluation
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void sortByEvaluation();

    /*
     *operator[]
     *
     *This function returns a reference at the given index
     *
     *Parameters:
     *    ndx: integer
     *
     *Output:
     *    return: reference to a BUAthlete object
     *    reference parameters: none
     *    stream: none
    */
    BUAthlete& operator[](int ndx);

    /*
     *toString
     *
     *This function converts an instance of a BUAthleteList into a string
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: string
     *    reference parameters: none
     *    stream: none
    */
    string toString();
};

/*
     *quicksortByID
     *
     *This function uses recursion to sort players by their ID
     *
     *Parameters:
     *    *list: pointer to array of BUAthletes
     *    low: integer
     *    high: integer
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
void quicksortByID(BUAthlete *list, int low, int high);

/*
     *partitionByID
     *
     *This function partitions data to use in quicksortByID
     *
     *Parameters:
     *    *list: pointer to array of BUAthletes
     *    low: integer
     *    high: integer
     *
     *Output:
     *    return: integer
     *    reference parameters: none
     *    stream: none
    */
int partitionByID(BUAthlete *list, int low, int high);

/*
     *quicksortByEval
     *
     *This function uses recursion to sort players by their evaluation
     *
     *Parameters:
     *    *list: pointer to array of BUAthletes
     *    low: integer
     *    high: integer
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
void quicksortByEval(BUAthlete *list, int low, int high);

/*
     *partitionByEval
     *
     *This function partions data to use in quicksortByEval
     *
     *Parameters:
     *    *list: pointer to array of BUAthletes
     *    low: integer
     *    high: integer
     *
     *Output:
     *    return: integer
     *    reference parameters: none
     *    stream: none
    */
int partitionByEval(BUAthlete *list, int low, int high);

#endif //PROJ5_PROJ5_BUATHLETELIST_H
