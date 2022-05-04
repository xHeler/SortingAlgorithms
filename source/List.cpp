#include "List.h"

void List::pop() {
    Node* temp = head;
    head = head->getNext();
    delete temp;
}

List::List() {
    size = 0;
}

void List::add(Movie movie) {
    Node* tmp = new Node(movie);
    if (head == nullptr) {
        head = tmp;
        tail = tmp;
    } else {
        tail->setNext(tmp);
        tail = tail->getNext();
    }
    size++;
}

void List::printList() {
    Node* temp = head;
    while (temp != nullptr) {
        Movie m = temp->getMovie();
        m.show();
        temp = temp->getNext();
    }
}

int List::getSize() const {
    return size;
}

Movie List::operator[](int index) {
    int i = 0;
    Node* tmp = head;
    while (tmp != nullptr && i != index) {
        tmp = tmp->getNext();
        i++;
    }
    return tmp->getMovie();
}

void List::qsort() {
    quickSort(&head);
}

void List::msort() {
    MergeSort(&head);
}

Node* getTail(Node* cur)
{
    while (cur != NULL && cur->getNext() != NULL)
        cur = cur->getNext();
    return cur;
}


Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd)
{
    Node* pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->getMovie().getRating() < pivot->getMovie().getRating()) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->getNext();
        }
        else
        {
            if (prev)
                prev->setNext(cur->getNext());
            Node* tmp = cur->getNext();
            cur->setNext(NULL);
            tail->setNext(cur);
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end)
{
    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;
    Node* pivot
            = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->getNext() != pivot)
            tmp = tmp->getNext();
        tmp->setNext(NULL);
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->setNext(pivot);
    }

    pivot->setNext(quickSortRecur(pivot->getNext(), newEnd));
    return newHead;
}

void quickSort(Node** headRef)
{
    (*headRef)
            = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;
    if ((head == NULL) || (head->getNext() == NULL)) {
        return;
    }

    FrontBackSplit(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->getMovie().getRating() <= b->getMovie().getRating()) {
        result = a;
        result->setNext(SortedMerge(a->getNext(), b));
    }
    else {
        result = b;
        result->setNext(SortedMerge(a, b->getNext()));
    }
    return (result);
}

void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->getNext();

    while (fast != NULL) {
        fast = fast->getNext();
        if (fast != NULL) {
            slow = slow->getNext();
            fast = fast->getNext();
        }
    }

    *frontRef = source;
    *backRef = slow->getNext();
    slow->setNext(NULL);
}
