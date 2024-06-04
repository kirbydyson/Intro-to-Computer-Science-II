// File: proj4-ItemInfo.cpp
// Author: Kirby Dyson
// Course: CSI 1440 02
// Assignment: Project 4
// Due Date: 9/25/2023

// Date Modified: 9/15/2023
//     -File created
// Date Modified: 2/24/2023
//     -File Finished
// Functions are defined from "proj4-ItemInfo.hpp"

#include "proj4-ItemInfo.hpp"

/**
 * setItemId
 *
 * This function stores an integer representation of a cstring into the itemId data
 * member of the ItemInfo class.
 *
 * Parameters:
 *      num:  a cstring representation of an integer value
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void ItemInfo::setItemId(const char *num){
    this->itemId = 0;
    for(int i = 0; num[i] != '\0'; i++){
        this->itemId *= 10;
        this->itemId += num[i] - '0';
    }
}

/**
 * setDescription
 *
 * This function stores a copy of the passed cstring into the description data member
 * of the ItemInfo class
 *
 * Parameters:
 *      cstr:  a cstring containing the description of the product
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void ItemInfo::setDescription(const char *cstr){
    int i = 0;
    while(cstr[i] != '\0'){
        this->description[i] = cstr[i];
        i++;
    }
    this->description[i] = '\0';
}

/**
 * setManCost
 *
 * This function stores an double representation of a cstring into the manCost data
 * member of the ItemInfo class.
 *
 * Parameters:
 *      num:  a cstring representation of an double value
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void ItemInfo::setManCost(const char *num){
    this->manCost = stuCstrToDbl(num);
}

/**
 * setSellPrice
 *
 * This function stores an double representation of a cstring into the sellPrice data
 * member of the ItemInfo class.
 *
 * Parameters:
 *      num:  a cstring representation of an double value
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void ItemInfo::setSellPrice(const char *num){
    this->sellPrice = stuCstrToDbl(num);
}

/**
 * getItemId
 *
 * This function returns a copy of the value stored in the itemId data memeber of the
 * ItemInfo class.
 *
 * Parameters: none
 *
 * Output:
 *      return: a copy of itemId
 *      reference parameters: none
 *      stream: none
 */
int ItemInfo::getItemId(){
    return this->itemId;
}

/**
 * getDescription
 *
 * This function returns a const reference to the description data member of the
 * ItemInfo class.
 *
 * Parameters: none
 *
 * Output:
 *      return: a const reference to description
 *      reference parameters: none
 *      stream: none
 */
const char *ItemInfo::getDescription(){
    return this->description;
}

/**
 * getManCost
 *
 * This function returns a copy of the value stored in the manCost data memeber of the
 * ItemInfo class.
 *
 * Parameters: none
 *
 * Output:
 *      return: a copy of manCost
 *      reference parameters: none
 *      stream: none
 */
double ItemInfo::getManCost(){
    return this->manCost;
}

/**
 * getSellPrice
 *
 * This function returns a copy of the value stored in the sellPrice data memeber of
 * the ItemInfo class.
 *
 * Parameters: none
 *
 * Output:
 *      return: a copy of sellPrice
 *      reference parameters: none
 *      stream: none
 */
double ItemInfo::getSellPrice(){
    return this->sellPrice;
}

/**
 * toAmazonJSON
 *
 * This function outputs the data members of the ItemInfo class in a JSON formate
 * specified by Amazon.
 *
 * Parameters:
 *      out: the ouput stream for the JSON format
 *
 * Output:
 *      return: none
 *      reference parameters: the updated ostream
 *      stream: none
 */
void ItemInfo::toAmazonJSON(ostream &out){
    char *info = new char[40];

    printCString(out, " {\n\t\t\"itemId\": ");
    stuDblToCstr(info, this->itemId);
    printCString(out, info);
    printCString(out, ",\n");

    printCString(out, "\t\t\"description\": ");
    out.put('"');
    stuCstrCpy(info, this->description);
    printCString(out, info);
    out.put('"');
    printCString(out, ",\n");

    printCString(out, "\t\t\"manPrice\": ");
    stuDblToCstr(info, this->manCost);
    printCString(out, info);
    printCString(out, ",\n");

    printCString(out, "\t\t\"sellPrice\": ");
    stuDblToCstr(info, this->sellPrice);
    printCString(out, info);
    printCString(out, "\n\t}");

    delete[] info;
}

/**
 * displayItemInfo
 *
 * This function outputs the data members of the ItemInfo class in a formate specified
 * by Prof. Aars.
 *
 * Parameters:
 *      out: the ouput stream for the specified format
 *
 * Output:
 *      return: none
 *      reference parameters: the updated ostream
 *      stream: none
 */
void ItemInfo::displayItemInfo(ostream &out){
    char *info = new char[50];

    printCString(out, "itemId: ");
    stuDblToCstr(info, this->itemId);
    printCString(out, info);
    out.put('\n');

    printCString(out, "description: ");
    stuCstrCpy(info, this->description);
    printCString(out, info);
    out.put('\n');

    printCString(out, "manCost: ");
    stuDblToCstr(info, this->manCost);
    printCString(out, info);
    out.put('\n');

    printCString(out, "sellPrice: ");
    stuDblToCstr(info, this->sellPrice);
    printCString(out, info);
    out.put('\n');

    printCString(out, "calculatedProfit: ");
    stuDblToCstr(info, calcProfit());
    printCString(out, info);
    out.put('\n');

    delete[] info;
}


/**
 * calcProfit
 *
 * This function computes the difference beteween an ItemInfo's manCost and sellPrice
 * data memebers.
 *
 * Parameters: none
 *
 * Output:
 *      return: the difference between manCost and sellPrice
 *      reference parameters: none
 *      stream: none
 */
double ItemInfo::calcProfit(){
    return this->sellPrice - this->manCost;
}

/**
 * stuCstrToDbl
 *
 * This function converts a cstring representation of a double into a double value
 *
 * Parameters:
 *      num: the cstring holding a ascii representation of a double
 *
 * Output:
 *      return: a double value that reflects the ascii representation found in num
 *      reference parameters: none
 *      stream: none
 */
double stuCstrToDbl(const char *num){
    double result = 0;
    double dec = 0.1;

    //Until end of string or decimal
    while(*num != '\0' && *num != '.'){
        result = (result * 10) + (*num - '0');
        num++;
    }

    if(*num == '.'){ //If decimal
        num++;
        while(*num != '\0'){
            result += dec * (*num - '0');
            dec /= 10;
            num++;
        }
    }
    return result;
}

/**
 * stuDblToCstr
 *
 * This function converts a double value into a cstring representation of a double
 *
 * Parameters:
 *      cstr: the char array holding enough space to store a ascii representation of num
 *      num: the double value that is converted into an ascii representation
 *
 * Output:
 *      return: none
 *      reference parameters: str should hold the ascii representatiton of num
 *      stream: none
 */
void stuDblToCstr(char *cstr, double num){
    int ndx = 0;
    int sum = 0;
    int num2;
    char c;
    double dec;

    num2 = num;
    while(num2 > 0){
        //Int to char
        cstr[ndx] = char(num2 % 10 + '0');
        num2 /= 10;
        ndx++;
        sum++;
    }
    //Reversing characters in front of decimal
    for(int i = 0; i < sum / 2; ++i){
        c = cstr[i];
        cstr[i] = cstr[sum - i - 1];
        cstr[sum - i - 1] = c;
    }
    //Check for decimals
    dec = num - static_cast<int>(num);
    if(dec > 0){
        cstr[ndx] = '.';
        ndx++;

        for(int i = 0; i < 2; ++i){
            dec *= 10;
            cstr[ndx] = char(int(dec) + '0');
            dec = dec - static_cast<int>(dec);
            ndx++;
        }
    }
    cstr[ndx] = '\0';
}

/**
 * stuCstrCpy
 *
 * This function copies the cstring src into dest
 *
 * Parameters:
 *      dest: the char array that hold a copy of the contents of src.  dest must have
 *            enough space to store the copy
 *      src: the cstring to be copied
 *
 * Output:
 *      return: none
 *      reference parameters: dest should hold a copy of src
 *      stream: none
 */
void stuCstrCpy(char *dest, const char *src){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/**
 * stuCstrLen
 *
 * This function caculates the length of a cstring
 *
 * Parameters:
 *      src: the cstring for which the length is calculated
 *
 * Output:
 *      return: an integer storing the length of the cstring
 *      reference parameters: none
 *      stream: none
 */
int stuCstrLen(const char *src){
    int len = 0;
    while(*src != '\0'){
        len++;
        src++;
    }
    return len;
}

/**
 * printCString
 *
 * This function writes a cstring to the passed ostream
 *
 * Parameters:
 *      out: the ostream for the cstring to be displayed
 *      src: the cstring to be displayed
 *
 * Output:
 *      ostream &: a reference to the passed ostream
 *      reference parameters: out
 *      stream: none
 */
ostream& printCString(ostream &out, const char *src){
    int i = 0;
    while(src[i] != '\0'){
        out.put(src[i]);
        i++;
    }
    return out;
}
