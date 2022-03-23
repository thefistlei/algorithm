// Copyright (c) 2022 algorithum sort
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 

#pragma once

#ifndef INSERTSORT_H
#define INSERTSORT_H
 
#include <iostream> 

using namespace std;

namespace insertSort
{
    namespace test1
    {
        void insertionSort(int arr[], int len) {
            for (int i = 1; i < len; i++) {
                int key = arr[i];
                int j = i - 1;
                while ((j >= 0) && (key < arr[j])) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        }
    }  
 
    void test() { 
        int a[] = { 1, 4, 5, 2, 10, 8 };
        int nSize = sizeof(a) / sizeof(int);
        test1::insertionSort(a, nSize);
        std::cout << "end" << std::endl;
    } 
}
 
#endif // !INSERTSORT_H