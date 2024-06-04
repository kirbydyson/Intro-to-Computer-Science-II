// File: proj8-bFileSort.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 8
// Due Date: 11/6/2023

// Date Modified: 10/30/2023
//     -File created
// Date Modified: 11/1/2023
//     -File finished
// In place sorting in a Binary file

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream file;
    int x, y;
    int count = 0;
    bool sort = false;

    // open file
    file.open("sortedInts", ios::in | ios::out | ios::binary);

    // if file fails to open, print error message
    if(!file){
        cout << "Error: unable to open file" << endl;
        return 1;
    }

    // output list of stored integers in file
    cout << "Stored Integers: " << endl;
    while(file.read((char*)&y, sizeof(int))){
        cout << y << " ";
        count++;
    }
    cout << endl << endl;

    // ask user to enter a integer
    cout << "Please enter a new integer X: ";
    cin >> x;
    cout << endl;

    // clear the end of file flag
    file.clear();
    // seek to the end of file
    file.seekg(0, ios::end);

    // insert the user integer into sorted place
    for(int i = 0; i < count && !sort; i++){
        file.seekg(-1 * sizeof(int), ios::cur);
        file.read((char*)&y, sizeof(int));
        file.write((char*)&y, sizeof(int));
        file.seekg(-1 * sizeof(int), ios::cur);
        if(y < x){
            file.write((char*)&x, sizeof(int));
            sort = true;
        }
        else{
            file.seekg(-1 * sizeof(int), ios::cur);
        }
    }

    // if input is smallest value, insert at front
    if(!sort){
        file.write((char*)&x, sizeof(int));
    }
    count++;

    // output the updated, sorted list to screen
    file.seekg(0, ios::beg);
    cout << "Sorted integers:" << endl;
    for(int i = 0; i < count; i++) {
        file.read((char*)&y, sizeof(int));
        cout << y << " ";
    }
    cout << endl;

    // Close file
    file.close();

    return 0;
}

