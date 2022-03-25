// Copyright (c) 2022 algorithum sort
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 


#pragma once

#ifndef QUICKSORT_H
#define QUICKSORT_H
 
#include <iostream> 
#include <random>


using namespace std;

namespace quickSort
{
    namespace test1
    {
        int Paritition1(int A[], int low, int high) {
            int pivot = A[low];
            while (low < high) {
                while (low < high && A[high] >= pivot) {
                    --high;
                }
                A[low] = A[high];
                while (low < high && A[low] <= pivot) {
                    ++low;
                }
                A[high] = A[low];
            }
            A[low] = pivot;
            return low;
        }

        void QuickSort(int A[], int low, int high) //快排母函数
        {
            if (low < high) {
                int pivot = Paritition1(A, low, high);
                QuickSort(A, low, pivot - 1);
                QuickSort(A, pivot + 1, high);
            }
        }
    }

    namespace test2
    {
        void printArray(int arr[], int size)
        {
            int i;
            for (i = 0; i < size; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        void swap(int& a, int& b)
        {
            int t = a;
            a = b;
            b = t;
        }

        int partition(int arr[], int low, int high)
        {
            int pivot = arr[low]; // pivot
            int j = low+1; // Index of smaller element and indicates the right position of pivot found so far

            for (int i = j; i <= high; i++)
            {
                // If current element is smaller than the pivot
                if (arr[i] < pivot)
                {
                    swap(arr[j], arr[i]);
                    j++; // increment index of smaller element
                }
            }
            swap(arr[j-1], arr[low]);
            return (j-1);
        }

        void quickSort(int A[], int low, int high) //快排母函数
        {
            if (low < high) {
                int pivot = partition(A, low, high);
                quickSort(A, low, pivot - 1);
                quickSort(A, pivot + 1, high);
            }
        }
    }   
 
    namespace test3
    {
        int m = 0;
        int n = 0;

        int getValue(int A[], int B[], int i) {
            if (i < 0)
                i = 0;
            if (i >= m + n)
                i = m + n - 1;

            if (i < m)
                return A[i];
            else
                return B[i - m];
        }

        void setValue(int A[], int B[], int i, int value) {
            if (i < 0)
                i = 0;
            if (i >= m + n)
                i = m + n - 1;

            if (i < m)
                A[i] = value;
            else
                B[i - m] = value;
        }

        void swap(int A[], int B[], int low, int high) {
            int a = getValue(A, B, low);
            int b = getValue(A, B, high);

            setValue(A, B, low, b);
            setValue(A, B, high, a);
        }

        int parititionArray(int A[], int B[], int low, int high) {
            int pivot_idx = low + rand() % (high - low + 1);  // randomly select
            // move pivot to begin
            swap(A, B, pivot_idx, low);

            int pivot = getValue(A, B, low);

            while (low < high) {
                while (low < high && getValue(A, B, high) >= pivot) {
                    --high;
                }
                setValue(A, B, low, getValue(A, B, high));

                while (low < high && getValue(A, B, low) <= pivot) {
                    ++low;
                }
                setValue(A, B, high, getValue(A, B, low));
            }

            setValue(A, B, low, pivot);
            return low;
        }

        void quickSortArray(int A[], int B[], int low, int high)
        {
            if (low < high) {
                int pivot = parititionArray(A, B, low, high);
                quickSortArray(A, B, 0, pivot - 1);
                quickSortArray(A, B, pivot + 1, high);
            }
        }

        void quickSort() {
            int a[] = { 98, 67, 391, 99, 13, 130 };
            int b[] = { 97, 35, 88, 120, 140 };

            m = sizeof(a) / sizeof(int);
            n = sizeof(b) / sizeof(int);

            quickSortArray(a, b, 0, m + n - 1);
            int i = 4;
        }
    }

    void test() { 
        int a[] = { 1, 4, 5, 2, 10, 8 };
        int nSize = sizeof(a) / sizeof(int);
        test1::QuickSort(a, 0, nSize-1);
        int n = 3;

        int b[] = { 1, 4, 5, 2, 10, 8 };
        nSize = sizeof(b) / sizeof(int);
        test2::quickSort(b, 0, nSize - 1);
          
        test3::quickSort();
    } 
}
 
#endif // !QUICKSORT_H