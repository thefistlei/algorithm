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
            int i;        // ��������ĩβλ��
            int j;        // ����������ʼλ��
            int min;    // ����������СԪ��λ��

            for (i = 0; i < n; i++)
            {
                min = i;

                //��"a[i+1]..a[n]"֮����СԪ�أ�������min
                for (j = i + 1; j < n; j++)
                {
                    if (a[j] < a[min])
                        min = j;
                }

                //��min!=i���򽻻� a[i] �� a[min]��
                //�����󣬱�֤��a[0]..a[i]֮��Ԫ������
                if (min != i)
                    swap(a[i], a[min]);
            }
        }
    }  
 
    void test() { 
        int a[] = { 1, 4, 5, 2, 10, 8 };
        int nSize = sizeof(a) / sizeof(int);
        test1::selectSort(a, nSize); 
        int c = 3;
    } 
}
 
#endif // !SELECTSORT_H