//
//  main.cpp
//  p3
//
//  Created by Rachael So on 10/28/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#include <iostream>
#include "minHeap.h"

using namespace std;

int main(int argc, const char * argv[]) {
    minHeap heap;
    
    heap.insert(90);
    cout << endl;
    heap.insert(100);
    cout << endl;
    heap.insert(10);
    cout << endl;
    heap.insert(16);
    cout << endl;
    heap.insert(88);
    cout << endl;
    heap.insert(1);
    cout << endl;
    cout << "calling remove\n";
    heap.remove();
    cout << endl;
    heap.remove();
    cout << endl;
    heap.remove();
    cout << endl;
    heap.remove();
    cout << endl;
}
