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

    int getSize() const;
    Movie operator[](int index);
    void sort();
};

void quickSort(Node** head);
Node* getTail(Node* current);
Node* quickSortRecur(Node* head, Node* end);
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd);