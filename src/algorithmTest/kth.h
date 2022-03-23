// Copyright (c) 2022 algorithum sort
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 


#pragma once

#ifndef KTH_H
#define KTH_H
 
#include <iostream> 
#include <queue>

using namespace std;

namespace kth
{
    namespace priorityQueue
    {
        int findKthLargest(int a[], int nSize, int k)
        { 
            // Creating a min-heap using priority queue
            priority_queue<int, vector<int>, greater<int> > q;

            for (int i = 0; i < nSize; i++) {
                q.push(a[i]);
                if (q.size() > k)
                    q.pop();
            }
            return q.top();
        }

        void test() {
            int a[] = { 1, 4, 5, 2, 10, 8 };
            int aSize = sizeof(a) / sizeof(int); 
            int k = findKthLargest(a, aSize, 3);
            std::cout << "end" << std::endl;
        }
    }

    namespace quickSelect
    {  
        int partition(std::vector<int>& nums, int start, int end) {
            int pivot = nums[end], i = start;
            for (int j = start; j < end; ++j) {
                if (nums[j] < pivot) {
                    swap(nums[j], nums[i++]);
                }
            }
            swap(nums[end], nums[i]);
            return i;
        }

        int findKthLargest(std::vector<int> nums, int k)
        {
            int target_pos = nums.size() - k;
            int start = 0, end = nums.size() - 1;
            int mid = partition(nums, start, end);
            while (mid != target_pos) {
                if (mid < target_pos)
                    start = mid + 1;
                else
                    end = mid - 1;
                mid = partition(nums, start, end);
            }
            return nums[mid];
        }

        int partition(int a[], int start, int end) {
            int pivot = a[end], i = start;
            for (int j = start; j < end; ++j) {
                if (a[j] < pivot) {
                    swap(a[j], a[i++]);
                }
            }
            swap(a[end], a[i]);
            return i;
        }

        int findKthLargest(int a[], int nSize, int k)
        {
            int target_pos = nSize - k;
            int start = 0, end = nSize - 1;
            int mid = partition(a, start, end);
            while (mid != target_pos) {
                if (mid < target_pos)
                    start = mid + 1;
                else
                    end = mid - 1;
                mid = partition(a, start, end);
            }
            return a[mid];
        }

        void test() {
            std::vector<int>nums = { 1, 4, 5, 2, 10, 8 };
            int k1 = quickSelect::findKthLargest(nums, 3);

            int a[] = { 1, 4, 5, 2, 10, 8 };
            int nSize = sizeof(a) / sizeof(int);
            int k2 = quickSelect::findKthLargest(a, nSize, 3);

            std::cout << "end" << std::endl;
        }
    }   

    namespace twoArray
    {
        int kth(int* arr1, int* arr2, int* end1, int* end2, int k)
        {
            if (arr1 == end1)
                return arr2[k];
            if (arr2 == end2)
                return arr1[k];
            int mid1 = (end1 - arr1) / 2;
            int mid2 = (end2 - arr2) / 2;
            if (mid1 + mid2 < k)
            {
                if (arr1[mid1] > arr2[mid2])
                    return kth(arr1, arr2 + mid2 + 1, end1, end2,
                        k - mid2 - 1);
                else
                    return kth(arr1 + mid1 + 1, arr2, end1, end2,
                        k - mid1 - 1);
            }
            else
            {
                if (arr1[mid1] > arr2[mid2])
                    return kth(arr1, arr2, arr1 + mid1, end2, k);
                else
                    return kth(arr1, arr2, end1, arr2 + mid2, k);
            }
        }

        void test() {  
            int a[] = {1, 2, 4, 5, 800, 1000};
            int aSize = sizeof(a) / sizeof(int);

            int b[] = {10, 20, 40, 50, 80, 100};
            int bSize = sizeof(b) / sizeof(int);

            int k = kth(a, b, &a[aSize-1], &b[bSize - 1], 3);
            std::cout << "end" << std::endl;
        }
    }
 
    void test() { 
        priorityQueue::test();
        quickSelect::test(); 
        twoArray::test();

        std::cout << "end" << std::endl;
    }
}
 
#endif // !KTH_H