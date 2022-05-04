#pragma once
#include "Node.h"

class List {
private:
    int size;
    Node* head = nullptr;
    Node* tail = nullptr;
    void pop();

public:
    List();
    void add(Movie movie);
    void printList();
    void qsort();
    int getSize() const;
    Movie operator[](int index);
};

void quickSort(Node** headRef);
Node* quickSortRecur(Node* head, Node* end);
Node* getTail(Node* cur);