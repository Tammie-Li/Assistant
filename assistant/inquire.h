//
// Created by li on 2020/12/11.
//


#ifndef FIND_H
#define FIND_H


#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;


typedef struct msgNameLocation
{
    string eegName;
    int eegLocationX;
    int eegLocationY;
};


msgNameLocation getFindResult(string name);



#endif // find_H



