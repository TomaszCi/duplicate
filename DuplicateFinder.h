/* 
 * File:   DuplicateFinder.h
 * Author: Tomasz
 *
 * Created on 17 styczeń 2016, 20:53
 */
#include <string>
#include <regex>
#include <vector>
#include "NumberSet.h"

#ifndef DUPLICATEFINDER_H
#define	DUPLICATEFINDER_H


#define DUPLICATE 0
#define UNIQUE 1
#define BAD_INPUT -1

using namespace std;

class DuplicateFinder {
public:
    DuplicateFinder();
    DuplicateFinder(const DuplicateFinder& orig);

    int process(string token);
    vector <string> printBadInputs();
    int getUniqueCount();
    int getDuplicateCount();
    NumberSet* listMostFrequentSet();
    
    virtual ~DuplicateFinder();
private:
    bool parseLine();
    bool isDuplicate();

    string inputFilename;
    string currentLine;
    regex lineRegex;
    int duplicateCount;
    int uniqueCount;
    NumberSet *currentSet;
    vector <string> badInputs;
    vector <NumberSet *> checkedSets;
};

#endif	/* DUPLICATEFINDER_H */

