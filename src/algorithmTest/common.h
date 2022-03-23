// Copyright (c) 2022 algorithum sort
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 

#pragma once

#ifndef COMMON_H
#define COMMON_H
 
#include <iostream> 
#include <iomanip>

using namespace std;

namespace common
{ 
    void print(int arr[]);    

        
    // Print buckets
    void print(int ar[], int nSize) {
        int i;
        for (i = 0; i < nSize; ++i) {
            cout << setw(3) << ar[i];
        }
        cout << endl;
    }  
}
 
#endif // !COMMON_H