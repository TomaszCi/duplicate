/* 
 * File:   DuplicateFinder.cpp
 * Author: Tomasz
 * 
 * Created on 17 styczeń 2016, 20:53
 */

#include "DuplicateFinder.h"
#include <cstdlib>
#include <regex>


using namespace std;

DuplicateFinder::DuplicateFinder() {
    lineRegex = regex("^([0-9]+)(,\\s?[0-9]+)*$");
    uniqueCount = 0;
    duplicateCount = 0;
}

DuplicateFinder::DuplicateFinder(const DuplicateFinder& orig) {
}

DuplicateFinder::~DuplicateFinder() {
    delete currentSet;
}

int DuplicateFinder::process(string token) {
    currentLine = token;
    if (!parseLine()) {
        badInputs.push_back(currentLine);
        return BAD_INPUT;
    }
    if (isDuplicate()) {
        duplicateCount++;
        return DUPLICATE;
    } else {
        uniqueCount++;
        return UNIQUE;
    }
}

bool DuplicateFinder::parseLine() {
    if (regex_match(currentLine, lineRegex)) {
        currentSet = new NumberSet(currentLine);
        return true;
    } else {
        return false;
    }
}

bool DuplicateFinder::isDuplicate() {
    bool duplicate = false;
    bool localDuplicateFlag;
    if (checkedSets.size() > 0) {
        for (int i = 0; i < checkedSets.size(); i++) {
            if (checkedSets[i]->getLength() == currentSet->getLength()) {
                localDuplicateFlag = true;
                for (int j = 0; j < checkedSets[i]->getLength(); j++) {
                    if (checkedSets[i]->getActualSet()[j] != currentSet->getActualSet()[j]) {
                        localDuplicateFlag = false;
                        break;
                    }
                }
                if (localDuplicateFlag)
                    duplicate = true;
            }
            if (duplicate) {
                checkedSets[i]->duplicateFound();
                break;
            }
        }
        if (!duplicate) {
            checkedSets.push_back(currentSet);
        }


    } else {
        checkedSets.push_back(currentSet);
    }
    return duplicate;
}

int DuplicateFinder::getUniqueCount() {
    return uniqueCount;
}

int DuplicateFinder::getDuplicateCount() {
    return duplicateCount;
}

vector <string> DuplicateFinder::printBadInputs() {
    printf("INVALID INPUTS:\n");
    for(string input : badInputs) {
        printf("%s\n", input.c_str());
    }
    return badInputs;
}

NumberSet *DuplicateFinder::listMostFrequentSet() {
    NumberSet *max = checkedSets[0];
    for(int i=1; i < checkedSets.size(); i++) {
        if(checkedSets[i]->getDuplicationCount() > max->getDuplicationCount()) {
            max = checkedSets[i];
        }
    }
    printf("MOST FREQUENTLY DUPLICATED SET:\n%s\n", max->toString().c_str());
    return max;
}