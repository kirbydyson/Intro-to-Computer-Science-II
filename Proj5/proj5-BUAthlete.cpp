// File: proj5-BUAthlete.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 5
// Due Date: 10/9/2023

// Date Modified: 9/26/2023
//     -File created
// Date Modified: 9/30/2023
//     -File finished
// Functions are defined from "proj5-BUAthlete.h"

#include "proj5-BUAthlete.h"
#include <sstream>

//Set evaluation to eval
void BUAthlete::setEvaluation(int eval){
    this->evaluation = eval;
}

//Set position to pos
void BUAthlete::setPosition(Position pos){
    this->bestFit = pos;
}

//Return evaluation
int BUAthlete::getEvaluation(){
    return this->evaluation;
}

//Return position
Position BUAthlete::getPosition(){
    return this->bestFit;
}

string BUAthlete::toString(){
    ostringstream out;

    //Output data from NCAAAthlete toString function
    out << this->NCAAAthlete::toString();
    //Output evaluation and position of player
    out << "Evaluation: " << this->evaluation << endl;
    out << "Position: ";
    switch(this->bestFit){
        case 0:
            out << "OL";
            break;
        case 1:
            out << "QB";
            break;
        case 2:
            out << "RB";
            break;
        case 3:
            out << "WR";
            break;
        case 4:
            out << "TE";
            break;
        case 5:
            out << "DL";
            break;
        case 6:
            out << "DE";
            break;
        case 7:
            out << "LB";
            break;
        case 8:
            out << "CB";
            break;
        case 9:
            out << "S";
            break;
        case 10:
            out << "K";
            break;
    }
    out << endl;

    return out.str();
}
