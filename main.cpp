/* 
 * File:   main.cpp
 * Author: Tomasz
 *
 * Created on 17 styczeń 2016, 20:23
 */

#include "DuplicateFinder.h"
#include <fstream>

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream file;
    string token;
    file.open("input.txt", ifstream::in);
    DuplicateFinder *duplicateFinder = new DuplicateFinder();

    while (getline(file, token)) {

        switch (duplicateFinder->process(token)) {
            case DUPLICATE:
            {
                printf("duplicate found: %s\n", token.c_str());
                break;
            }
            case UNIQUE:
            {
                printf("unique found: %s\n", token.c_str());
                break;
            }
            case BAD_INPUT:
            {
                printf("bad input: %s\n", token.c_str());
                break;
            }
        }
    }

    file.close();
    
    printf("DUPLICATES: %d\nUNIQUES: %d\n", duplicateFinder->getDuplicateCount(), duplicateFinder->getUniqueCount());
    
    duplicateFinder->printBadInputs();
    
    duplicateFinder->listMostFrequentSet();
    
    delete duplicateFinder;
    return 0;
}

