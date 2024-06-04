// File: proj5-BUAthleteList.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 5
// Due Date: 10/9/2023

// Date Modified: 9/26/2023
//     -File created
// Date Modified: 10/1/2023
//     -File finished
// Functions are defined from "proj5-BUAthleteList.h"

#include "proj5-BUAthleteList.h"
#include <sstream>

//Default constructor
BUAthleteList::BUAthleteList(){
    this->size = 0;
    this->capacity = 2;
    this->list = new BUAthlete[this->capacity];
}

//Destructor
BUAthleteList::~BUAthleteList(){
    delete[] this->list;
}

//Copy constructor
BUAthleteList::BUAthleteList(BUAthleteList& other){
    this->size = other.size;
    this->capacity = other.capacity;
    this->list = new BUAthlete[this->capacity];
    for(int i = 0; i < this->size; i++) {
        this->list[i] = other.list[i];
    }
}

//Overloaded copy assignment operator
BUAthleteList& BUAthleteList::operator =(BUAthleteList& other){
    if(this != &other){
        delete[] this->list;
        this->size = other.size;
        this->capacity = other.capacity;
        this->list = new BUAthlete[this->capacity];
        for(int i = 0; i < this->size; i++){
            this->list[i] = other.list[i];
        }
    }
    return *this;
}

//Resize array if it exceeds capacity
void BUAthleteList::resizeArray(){
    this->capacity += 2;
    BUAthlete *temp = new BUAthlete[this->capacity];
    for(int i = 0; i < this->size; i++){
        temp[i] = list[i];
    }
    delete[] list;
    list = temp;
}

//Adding a player to the list
void BUAthleteList::addNCAAAthlete(int id, string name, string loi, string school){
    if(this->size == this->capacity){
        this->resizeArray();
    }
    this->list[this->size].setID(id);
    this->list[this->size].setName(name);
    this->list[this->size].setLOI(loi);
    this->list[this->size].setSchool(school);
    this->size++;
}

//Sets the position and evaluation of a player at given index
void BUAthleteList::setBUInfo(int i, Position pos, int eval){
    this->list[i].setPosition(pos);
    this->list[i].setEvaluation(eval);
}

//Finds a player by their ID number
int BUAthleteList::findByID(int id){
    int low = 0;
    int mid;
    int high = this->size - 1;

    while(high >= low){
        mid = (high + low) / 2;
        if(list[mid].getID() > id){
            high = mid - 1;
        }
        else if(list[mid].getID() < id){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

//Sorts players by their ID number
void BUAthleteList::sortByID(){
    quicksortByID(this->list, 0, this->size - 1);
}

//Sorts players by their position
void BUAthleteList::sortByPosition(){
    for(int i = 0; i < this->size - 1; i++){
        for(int j = 0; j < this->size - 1 - i; j++){
            if(this->list[j].getPosition() > this->list[j + 1].getPosition()){
                swap(this->list[j], this->list[j + 1]);
            }
        }
    }
}

//Sorts players by their evaluation
void BUAthleteList::sortByEvaluation(){
    quicksortByEval(this->list, 0, this->size - 1);
}

//Overloaded operator function
BUAthlete& BUAthleteList::operator[](int ndx){
    return this->list[ndx];
}

//Outputs players index and data
string BUAthleteList::toString(){
    ostringstream out;

    for(int i = 0; i < this->size; ++i){
        out << "[ " << i << " ]" << endl;
        out << this->list[i].toString();
    }
    return out.str();
}

//Partitioning used for quicksortByID
int partitionByID(BUAthlete *list, int low, int high){
    int mid, pivot;
    bool done = false;

    mid = low + (high - low) / 2;
    pivot = list[mid].getID();

    while(!done){
        while(list[low].getID() <  pivot){
            low++;
        }
        while(pivot < list[high].getID()){
            high--;
        }
        if(low >= high){
            done = true;
        }
        else{
            swap(list[high], list[low]);
            low++;
            high--;
        }
    }
    return high;
}

//Sorts players by their ID number
void quicksortByID(BUAthlete *list, int low, int high){
    int ndx;
    if(low >= high){
        return;
    }
    ndx = partitionByID(list, low, high);
    quicksortByID(list, low, ndx);
    quicksortByID(list, ndx + 1, high);
}

//Sorts players by their evaluation number
void quicksortByEval(BUAthlete *list, int low, int high){
    int ndx;
    if(low >= high){
        return;
    }
    ndx = partitionByEval(list, low, high);
    quicksortByEval(list, low, ndx);
    quicksortByEval(list, ndx + 1, high);
}

//Partitioning used for quicksortByEval
int partitionByEval(BUAthlete *list, int low, int high){
    int mid, pivot;
    bool done = false;

    mid = low + (high - low) / 2;
    pivot = list[mid].getEvaluation();

    while(!done){
        while(list[low].getEvaluation() >  pivot){
            low++;
        }
        while(pivot > list[high].getEvaluation()){
            high--;
        }
        if(low >= high){
            done = true;
        }
        else{
            swap(list[high], list[low]);
            low++;
            high--;
        }
    }
    return high;
}
