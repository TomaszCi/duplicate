/* 
 * File:   NumberSet.cpp
 * Author: Tomasz
 * 
 * Created on 17 styczeń 2016, 21:10
 */

#include "NumberSet.h"
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

NumberSet::NumberSet(std::string inputString) {
    duplicationCount = 0;
    stringstream stringStream = stringstream(inputString);
    string token;
    char delimiter = ',';
    int numberToPush;
    stringRepresentation = inputString;
    
    while (getline(stringStream, token, delimiter)) {
        sscanf(token.c_str(), "%d", &numberToPush);
        actualSet.push_back(numberToPush);
    }

    sort(actualSet.begin(), actualSet.end());

    //let's calculate it once and then use it withot processing
    length = actualSet.size();

}

NumberSet::NumberSet(const NumberSet& orig) {
}

NumberSet::NumberSet() {
}

NumberSet::~NumberSet() {
}

int NumberSet::duplicateFound() {
    duplicationCount++;
    return duplicationCount;
}

int NumberSet::getLength() {
    return length;
}

vector <int> NumberSet::getActualSet() {
    return actualSet;
}

int NumberSet::getDuplicationCount() {
    return duplicationCount;
}

string NumberSet::toString() {
    return stringRepresentation;
}