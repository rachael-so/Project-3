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
//    friend std::ostream& operator<<(std::ostream& os, const minHeap& rhs);

private:
    int size;
    int *array;
    int numItems;
    int root;
    
public:
    minHeap();
    minHeap(int,int);
    ~minHeap();
    void insert(int);
    void remove();
    void resize();
    void print(minHeap);
};

minHeap::minHeap()
{
    this->size = 10;
    this->array = new int[size];
    this->numItems = 0;
}

minHeap::minHeap(int size, int numItems) {
    this->size = size;
    this->array = new int[size];
    this->numItems = numItems;
}

minHeap::~minHeap()
{
    delete [] array;
}

void minHeap::insert(int val)
{
    
    if (numItems == size) {
        resize();
        insert(val);
    }
    else {
        int hole = numItems = numItems + 1;
        while (val < array[hole/2]) {
            array[hole] = array[hole/2];
            hole = hole/2;
            array[hole] = val;
        }
    }
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
    
}

void minHeap::resize()
{
    int* doubled = new int[size * 1];
    for(int i = 0; i < numItems-1; i++)
        doubled[i] = array[i];
    
    size++;
    array = doubled;
    delete[] doubled;
}

void minHeap::print(minHeap heap)
{
    int root = 1;
    cout << heap.array[root-1];
    cout << "[" << heap.array[root*2-1] << "]";
    
    
    
}

//ostream& operator<<(ostream& os, const minHeap& rhs)
//{
//    return os;
//}


#endif /* minHeap_h */
