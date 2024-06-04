// File: proj5-BUAthlete.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 5
// Due Date: 10/9/2023

// Date Modified: 9/26/2023
//     -File created
// Date Modified: 9/26/2023
//     -File finished
// Functions are defined from "proj5-BUAthleteList.h"
#ifndef PROJ5_PROJ5_BUATHLETE_H
#define PROJ5_PROJ5_BUATHLETE_H

#include <iostream>
#include <string>
#include "proj5-NCAAAthlete.h"

using namespace std;

enum Position{OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};

class BUAthlete : public NCAAAthlete{
protected:
    int evaluation;
    Position bestFit;

public:
    /*
     *setEvaluation
     *
     *This function stores the passed parameter in the evaluation data member
     *
     *Parameters:
     *    eval: integer
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void setEvaluation(int);

    /*
     *setPosition
     *
     *This function stores the passed parameter in the Position data member
     *Parameters:
     *    pos: Position value
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
    */
    void setPosition(Position);

    /*
     *getEvaluation
     *
     *This function returns a copy of the evaluation data member
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: a copy of the evaluation data member
     *    reference parameters: none
     *    stream: none
    */
    int getEvaluation();

    /*
     *getPosition
     *
     *This function returns a copy of the position data member
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: a copy of the position data member
     *    reference parameters: none
     *    stream: none
    */
    Position getPosition();

    /*
     *toString
     *
     *This function converts an instance of a BUAthlete into a string
      representation
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: a string representation of the object
     *    reference parameters: none
     *    stream: none
    */
    string toString();
};

#endif //PROJ5_PROJ5_BUATHLETE_H
