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
    void msort();
    void ssort();
    int getSize() const;
    Movie operator[](const int index);
    void setMovieAtIndex(Movie m, int index);
};

void quickSort(Node** headRef);
Node* quickSortRecur(Node* head, Node* end);
Node* getTail(Node* cur);

Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,Node** frontRef, Node** backRef);
void MergeSort(Node** headRef);

