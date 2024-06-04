// File: proj4-main.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 4
// Due Date: 9/25/2023

// Date Modified: 9/15/2023
//     -File created
// Date Modified: 2/24/2023
//     -File Finished
// Solves the problem presented.


#include "proj4-ItemInfo.hpp"
#include <fstream>

using namespace std;

void resizeArray(ItemInfo *&, int&, int);
void sortProfit(ItemInfo *, int);
void printInfo(ItemInfo *);

int main(){
    ifstream inFile;
    char buffer[500];
    int cap = 2;
    int num = 0;
    int ndx = 0;
    int item = 0;
    ItemInfo *arr = new ItemInfo[cap];

    //Open the file
    inFile.open("proj4-productServices.csv");

    //If file fails to open print error message
    if(!inFile){
        printCString(cout, "Bad file name\n");
        return 1;
    }
    else{
        while(inFile.get(buffer[ndx])){ //While reading data
            if(num == cap){
                resizeArray(arr, cap, cap + 2);
            }
            if(buffer[ndx] == ',' || buffer[ndx] == '\n'){
                buffer[ndx] = '\0';
                if(item == 0){
                    item++;
                    ndx = 0;
                    arr[num].setItemId(buffer);
                }
                else if(item == 1){
                    item++;
                    ndx = 0;
                    arr[num].setDescription(buffer);
                }
                else if(item == 2){
                    item++;
                    ndx = 0;
                    arr[num].setManCost(buffer);
                }
                else{
                    item = 0;
                    ndx = 0;
                    arr[num].setSellPrice(buffer);
                    num++;
                }
            }
            else{
                ndx++;
            }
        }
        //Sort and print data
        sortProfit(arr, num);
        printInfo(arr);
    }

    //Close file
    inFile.close();
    // Deallocate memory
    delete[] arr;

    return 0;
}

//
// * resizeArray
// *
// * This function resizes the array when full
// *
// * Parameters: ItemInfo*&, int&, int
// *
// * Output:
// *      return: void
// *      reference parameters: arr
// *      stream: none
//
void resizeArray(ItemInfo *&arr, int &cap, int s){
    ItemInfo *temp = arr;
    arr = new ItemInfo[s];
    for(int i = 0; i < cap; i++){
        arr[i] = temp[i];
    }
    cap = s;
    delete[] temp;
}

//
// * sortProfit
// *
// * This function sorts items by their profit
// *
// * Parameters: ItemInfo *, int
// *
// * Output:
// *      return: void
// *      reference parameters: none
// *      stream: none
//
void sortProfit(ItemInfo *arr, int s){
    for(int i = 0; i < s - 1; i++){
        for(int j = 0; j < s - i - 1; j++){
            if(arr[j].calcProfit() < arr[j + 1].calcProfit()){
                ItemInfo temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//
// * printInfo()
// *
// * This function prints the items
// *
// * Parameters: ItemInfo *
// *
// * Output:
// *      return: void
// *      reference parameters: none
// *      stream: none
//
void printInfo(ItemInfo *a){
    char name[17] = "\"DysonStore\": [\n";
    char arr1[14] = "\t\"firstItem\":";
    char arr2[17] = "\n\t\"secondItem\":";
    char arr3[16] = "\n\t\"thirdItem\":";
    char arr4[17] = "\n\t\"fourthItem\":";
    char arr5[16] = "\n\t\"fifthItem\":";
    printCString(cout, name);
    printCString(cout, arr1);
    a[0].toAmazonJSON(cout);
    cout.put(',');
    printCString(cout, arr2);
    a[1].toAmazonJSON(cout);
    cout.put(',');
    printCString(cout, arr3);
    a[2].toAmazonJSON(cout);
    cout.put(',');
    printCString(cout, arr4);
    a[3].toAmazonJSON(cout);
    cout.put(',');
    printCString(cout, arr5);
    a[4].toAmazonJSON(cout);
    printCString(cout, "\t\n]");
}
