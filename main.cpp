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
    heap.print(heap.root);
}
