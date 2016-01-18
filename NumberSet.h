/* 
 * File:   NumberSet.h
 * Author: Tomasz
 *
 * Created on 17 styczeń 2016, 21:10
 */
#include <string>
#include <vector>

using namespace std;

#ifndef NUMBERSET_H
#define	NUMBERSET_H

class NumberSet {
public:
    NumberSet();
    NumberSet(string inputString);
    NumberSet(const NumberSet& orig);
    virtual ~NumberSet();
    
    int getDuplicationCount();
    int duplicateFound();
    int getLength();
    string toString();
    vector <int> getActualSet();
private:
    string stringRepresentation;
    int length;
    vector <int> actualSet;
    int duplicationCount;
};

#endif	/* NUMBERSET_H */

