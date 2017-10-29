# Project-3


class minHeap:
friend ostream& operator<<(ostream& os, const minHeap& rhs);
private-
    Node *a
    Node root
    int *numItems
    int *size
public-
    minHeap()
    ~minHeap()
    void add(Node *item)
    void remove()
    void resize()

class Node:
private-
    int key
