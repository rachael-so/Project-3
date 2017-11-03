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
    void swapDown(int);
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
    cout << endl;
}

void minHeap::remove()
{
    out_of_range e1("nothing to remove");
    
    try {
        if (numItems == 1) {
            throw e1;
        }
        else {
            numItems--;
            int hole = 1;
            int temp = array[numItems];
            array[hole] = temp;
            
            swapDown(hole);
            
            print(1);
            cout << endl;
        }
    }
    catch (out_of_range &e1) {
        cout << e1.what() << endl;
    }
}

void minHeap::swapDown(int hole)
{
    int child = hole * 2;
    if (child >= numItems) {
        return;
    }
    if (child + 1 < numItems && array[child] > array[child+1]) {
        child++;
    }
    if (array[hole] >= array[child]) {
        int temp = array[hole];
        array[hole] = array[child];
        array[child] = temp;
        hole = child;
        swapDown(hole);
    }
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
    out_of_range e1("heap is empty");
    
    try {
        if (numItems == 1) {
            throw e1;
        }
        else {
        //    cout << "in print method with root: " << array[heapRoot] << endl;
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
    }
    catch (out_of_range &e1) {
        cout << e1.what() << endl;
    }
}

//numItems--;
//int temp = array[numItems];
//int hole = 1;
//array[hole] = temp;
//cout << "hole: " << array[hole] << endl;
//cout << "temp: " << temp << endl;
//
//while (hole <= numItems) {
//    int child = hole * 2;
//    if (child != numItems && array[child+1] < array[child])
//        child++;
//    if (array[child] <= temp) {
//        array[hole] = array[child];
//        array[child] = temp;
//    }
//    hole = child;
//}


#endif /* minHeap_h */
