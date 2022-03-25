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
using namespace common;

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

            int nSize = sizeof(array) / sizeof(int);
            print(array, nSize);
        }
    }   

    namespace test2 {
#include<vector>
        using namespace std;
        const int BUCKET_NUM = 10;

        struct ListNode {
            explicit ListNode(int i = 0) :mData(i), mNext(NULL) {}
            ListNode* mNext;
            int mData;
        };

        ListNode* insert(ListNode* head, int val) {
            ListNode dummyNode;
            ListNode* newNode = new ListNode(val);
            ListNode* pre, * curr;
            dummyNode.mNext = head;
            pre = &dummyNode;
            curr = head;
            while (NULL != curr && curr->mData <= val) {
                pre = curr;
                curr = curr->mNext;
            }
            newNode->mNext = curr;
            pre->mNext = newNode;
            return dummyNode.mNext;
        }


        ListNode* Merge(ListNode* head1, ListNode* head2) {
            ListNode dummyNode;
            ListNode* dummy = &dummyNode;
            while (NULL != head1 && NULL != head2) {
                if (head1->mData <= head2->mData) {
                    dummy->mNext = head1;
                    head1 = head1->mNext;
                }
                else {
                    dummy->mNext = head2;
                    head2 = head2->mNext;
                }
                dummy = dummy->mNext;
            }
            if (NULL != head1) dummy->mNext = head1;
            if (NULL != head2) dummy->mNext = head2;

            return dummyNode.mNext;
        }

        void BucketSort(int n, int arr[]) {
            vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
            for (int i = 0; i < n; ++i) {
                int index = arr[i] / BUCKET_NUM;
                ListNode* head = buckets.at(index);
                buckets.at(index) = insert(head, arr[i]);
            }
            ListNode* head = buckets.at(0);
            for (int i = 1; i < BUCKET_NUM; ++i) {
                head = Merge(head, buckets.at(i));
            }
            for (int i = 0; i < n; ++i) {
                arr[i] = head->mData;
                head = head->mNext;
            }
        }
    }

 
    void test() {  
        test1::test(); 
    } 
}
 
#endif // !BUCKETSORT_H