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

};