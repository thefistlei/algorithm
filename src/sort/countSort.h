// Copyright (c) 2022 algorithum sort
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 


#pragma once

#ifndef COUNTSORT_H
#define COUNTSORT_H
 
#include <iostream> 

using namespace std;

namespace countSort
{
    namespace test1
    {  
       // void countSort(vector<int>& arr)
       // {
           /* int max = *max_element(arr.begin(), arr.end());
            int min = *min_element(arr.begin(), arr.end());
            int range = max - min + 1;

            vector<int> count(range), output(arr.size());
            for (int i = 0; i < arr.size(); i++)
                count[arr[i] - min]++;

            for (int i = 1; i < count.size(); i++)
                count[i] += count[i - 1];

            for (int i = arr.size() - 1; i >= 0; i--) {
                output[count[arr[i] - min] - 1] = arr[i];
                count[arr[i] - min]--;
            }

            for (int i = 0; i < arr.size(); i++)
                arr[i] = output[i];*/
      //  }
        
        void countSort(int arr[], int len) { 
            //1.获得数列的最大值
            int max = arr[0];
            for (int i = 1; i < len; i++) {
                if (arr[i] > max)
                    max = arr[i];
            }

            //2.根据数列的最大值肯定统计数组的长度
            int* countArray = new int[max + 1]{};

            //3.遍历数列，填充统计数组
            for (int i = 0; i < len; i++)
                countArray[arr[i]]++;

            //4.遍历统计数组，输出结果
            int index = 0; 
            for (int i = 0; i < max + 1; i++) {
                while (countArray[i] > 0) { 
                    arr[index++] = i;
                    countArray[i]--;
                }
            } 
        }
    }  

    namespace test2
    {
        void countSort(int arr[], int len) {
            //1.获得数列的最大值和最小值
            int max = arr[0];
            for (int i = 1; i < len; i++) {
                if (arr[i] > max)
                    max = arr[i];
            } 
            int min = arr[0];
            for (int i = 1; i < len; i++) {
                if (arr[i] < min)
                    min = arr[i];
            }

            //2.初始化计数数组count的长度
            int* countArray = new int[max - min + 1]{};

            //3.遍历数列，填充统计数组
            for (int i = 0; i < len; i++)
                countArray[arr[i] - min]++;// A中的元素要减去最小值，再作为新索引

            //4.遍历统计数组，输出结果
            int index = 0;
            for (int i = 0; i < max + 1; i++) {
                while (countArray[i] > 0) {
                    arr[index++] = i + min;
                    countArray[i]--;
                }
            }
        } 
    }
 
    void test() { 
        int a[] = { 1, 4, 5, 2, 10, 8 };
        int nSize = sizeof(a) / sizeof(int);
        test1::countSort(a, nSize);

        int b[] = { 1, 4, 5, 2, 10, 8 };
        nSize = sizeof(b) / sizeof(int);
        test2::countSort(b, nSize);

        std::cout << "end" << std::endl;
    } 
}
 
#endif // !COUNTSORT_H