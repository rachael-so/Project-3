//
//  main.cpp
//  p3
//
//  Created by Rachael So on 10/28/17.
//  Copyright © 2017 Rachael So. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "minHeap.h"

using namespace std;

int main(int argc, const char * argv[]) {
    minHeap heap;
    bool quit = false;
    
    while (quit == false) {
        string ans;
        cout << "add to heap (a key), remove from heap (r), quit (q): ";
        getline(cin, ans);
        if (ans == "q")
            quit = true;
        else if (ans == "r") {
            heap.remove();
        }
        else {
            istringstream info(ans);
            char letter;
            int key;
            while (info >> letter >> key) {
                if (letter == 'a') {
                    heap.insert(key);
                }
            }
        }
    }
}
