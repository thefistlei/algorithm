// Copyright (c) 2022 algorithum sort
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 

#pragma once

#ifndef BUCKETSORT_H
#define BUCKETSORT_H
 
#include <iostream> 
#include <iomanip>


#include "common.h"


using namespace std;

namespace bucketSort
{
    namespace test1
    {  
        // Bucket sort in C++
         
#define NARRAY 7   // Array size
#define NBUCKET 6  // Number of buckets
#define INTERVAL 10  // Each bucket capacity

        struct Node {
            int data;
            struct Node* next;
        };

        void BucketSort(int arr[]);
        struct Node* InsertionSort(struct Node* list); 
        void printBuckets(struct Node* list);

        int getBucketIndex(int value) {
            return value / INTERVAL;
        }

        // Sorting function
        void BucketSort(int arr[]) {
            int i, j;
            struct Node** buckets;

            // Create buckets and allocate memory size
            buckets = (struct Node**)malloc(sizeof(struct Node*) * NBUCKET);

            // Initialize empty buckets
            for (i = 0; i < NBUCKET; ++i) {
                buckets[i] = NULL;
            }

            // Fill the buckets with respective elements
            for (i = 0; i < NARRAY; ++i) {
                struct Node* current;
                int pos = getBucketIndex(arr[i]);
                current = (struct Node*)malloc(sizeof(struct Node));
                current->data = arr[i];
                current->next = buckets[pos];
                buckets[pos] = current;
            }

            // Print the buckets along with their elements
            for (i = 0; i < NBUCKET; i++) {
                cout << "Bucket[" << i << "] : ";
                printBuckets(buckets[i]);
                cout << endl;
            }

            // Sort the elements of each bucket
            for (i = 0; i < NBUCKET; ++i) {
                buckets[i] = InsertionSort(buckets[i]);
            }

            cout << "-------------" << endl;
            cout << "Bucktets after sorted" << endl;
            for (i = 0; i < NBUCKET; i++) {
                cout << "Bucket[" << i << "] : ";
                printBuckets(buckets[i]);
                cout << endl;
            }

            // Put sorted elements on arr
            for (j = 0, i = 0; i < NBUCKET; ++i) {
                struct Node* node;
                node = buckets[i];
                while (node) {
                    arr[j++] = node->data;
                    node = node->next;
                }
            }

            for (i = 0; i < NBUCKET; ++i) {
                struct Node* node;
                node = buckets[i];
                while (node) {
                    struct Node* tmp;
                    tmp = node;
                    node = node->next;
                    free(tmp);
                }
            }
            free(buckets);
            return;
        }

        // Function to sort the elements of each bucket
        struct Node* InsertionSort(struct Node* list) {
            struct Node* k, * nodeList;
            if (list == 0 || list->next == 0) {
                return list;
            }

            nodeList = list;
            k = list->next;
            nodeList->next = 0;
            while (k != 0) {
                struct Node* ptr;
                if (nodeList->data > k->data) {
                    struct Node* tmp;
                    tmp = k;
                    k = k->next;
                    tmp->next = nodeList;
                    nodeList = tmp;
                    continue;
                }

                for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
                    if (ptr->next->data > k->data)
                        break;
                }

                if (ptr->next != 0) {
                    struct Node* tmp;
                    tmp = k;
                    k = k->next;
                    tmp->next = ptr->next;
                    ptr->next = tmp;
                    continue;
                }
                else {
                    ptr->next = k;
                    k = k->next;
                    ptr->next->next = 0;
                    continue;
                }
            }
            return nodeList;
        }


        void printBuckets(struct Node* list) {
            struct Node* cur = list;
            while (cur) {
                cout << setw(3) << cur->data;
                cur = cur->next;
            }
        }

        // Driver code
        void test(void) {
            int array[NARRAY] = { 42, 32, 33, 52, 37, 47, 51 };
             
            BucketSort(array);
            cout << "-------------" << endl; 
            print(array);
        }
    }   
 
    void test() {  
        test1::test(); 
    } 
}
 
#endif // !BUCKETSORT_H