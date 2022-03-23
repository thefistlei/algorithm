// Copyright (c) 2022 algorithum sort
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 



#pragma once

#ifndef SELECTSORT_H
#define SELECTSORT_H
 
#include <iostream> 

using namespace std;

namespace selectSort
{
    namespace test1
    {
        void selectSort(int a[], int n)
        {
            int i;        // 有序区的末尾位置
            int j;        // 无序区的起始位置
            int min;    // 无序区中最小元素位置

            for (i = 0; i < n; i++)
            {
                min = i;

                //找"a[i+1]..a[n]"之间最小元素，并赋给min
                for (j = i + 1; j < n; j++)
                {
                    if (a[j] < a[min])
                        min = j;
                }

                //若min!=i，则交换 a[i] 和 a[min]。
                //交换后，保证了a[0]..a[i]之间元素有序。
                if (min != i)
                    swap(a[i], a[min]);
            }
        }
    }  
 
    void test() { 
        int a[] = { 1, 4, 5, 2, 10, 8 };
        int nSize = sizeof(a) / sizeof(int);
        test1::selectSort(a, nSize); 

        std::cout << "end" << std::endl;
    } 
}
 
#endif // !SELECTSORT_H