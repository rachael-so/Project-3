//
//  minHeap.h
//  p3
//
//  Created by Rachael So on 10/28/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#ifndef minHeap_h
#define minHeap_h

#include<iostream>
#include <string>

using namespace std;

/****************************************************************************
 ****************************************************************************
 *                                                                          *
 *                       class minHeap declaration                          *
 *                                                                          *
 ****************************************************************************
 ****************************************************************************/

class minHeap
{
private:
    int size;
    int *array;
    int numItems;

public:
    minHeap();
    ~minHeap();
    void insert(int);
    void remove();
    void resize();
    void print(int);
};

minHeap::minHeap()
{
    this->size = 2;
    this->array = new int[size];
    this->numItems = 1;
}

minHeap::~minHeap()
{
    delete [] array;
}

void minHeap::insert(int val)
{
    if (numItems == size) {
        resize();
    }
    int hole = numItems;
    while (val < array[hole/2]) {
        array[hole] = array[hole/2];
        hole = hole/2;
    }
    array[hole] = val;
//    cout << "inserting: " << val << " at index: " << hole << endl;
    numItems++;
    
    print(1);
}

void minHeap::remove()
{
    int temp = array[numItems];
    numItems--;
    int hole = 1;
    
    while (hole <= numItems) { //while there exists a child traverse down
        int child = hole * 2; //check left child
        if (child != numItems && array[child+1] < array[child]) {
            child++;
        }
        if (array[child] < temp) {
            array[hole] = array[child];
            hole = child;
        }
        else
            break;
    }
    array[hole] = temp;
    
    print(1);
}

void minHeap::resize()
{
    size *= 2;
    int *temp = new int[size];
    for(int i = 0; i < size; i++)
        temp[i] = array[i];
    
    delete [] array;
    array = temp;
}

void minHeap::print(int heapRoot)
{
//    cout << "in print method for heapRoot of " << heapRoot << " ";
    int left = heapRoot * 2;
    int right = heapRoot * 2 + 1;
//    cout << "left: " << left << " ";
//    cout << "right: " << right << " " << endl;
    cout << array[heapRoot];
    if (left < numItems) {
//        cout << "this is left: " << left << " " << array[left];
        cout << " [";
        print(left);
        cout << "]";
    }
    if (right < numItems) {
//        cout << "this is right: " << right << " " << array[right];
        cout << " [";
        print(right);
        cout << "]";
    }
}

#endif /* minHeap_h */
