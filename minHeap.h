//
//  minHeap.h
//  p3
//
//  Created by Rachael So on 10/28/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#ifndef minHeap_h
#define minHeap_h

#include "Node.h"

using namespace std;

class minHeap
{
    friend std::ostream& operator<<(std::ostream& os, const minHeap& rhs);

private:
    int size;
    Node *a;
    Node root;
    int *numItems;
    
public:
    minHeap();
    ~minHeap();
    void add(Node *item);
    void remove();
    void resize();
};

minHeap::minHeap()
{
    this->size = 10;
    this->a = new Node[size];
    this->root;
}

minHeap::~minHeap()
{
    
}

void minHeap::add(Node *item)
{
    
}

void minHeap::remove()
{
    
}

void minHeap::resize()
{
    
}

ostream& operator<<(ostream& os, const minHeap& rhs)
{
    return os;
}


#endif /* minHeap_h */
