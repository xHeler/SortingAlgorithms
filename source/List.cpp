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

void List::sort() {
    quickSort(&head);
}

void quickSort(Node** head) {
    (*head) = quickSortRecur(*head, getTail(*head));
}

Node* getTail(Node* current) {
    while (current != NULL && current->getNext() != NULL) {
        current = current->getNext();
    }
    return current;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;
    Node* newHead = NULL;
    Node* newEnd = NULL;
    Node* pivot = partition(head, end, &newHead, &newEnd);
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

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL;
    Node* cur = head;
    Node* tail = pivot;

    while (cur != pivot){
        if (cur->getMovie().getRating() < pivot->getMovie().getRating()) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->getNext();
        } else {
            if(prev)
                prev->setNext(cur->getNext());
            Node* tmp = cur->getNext();
            cur->setNext(NULL);
            tail->setNext(cur);
            tail = cur;
            cur = tmp;
        }
        if ((*newHead) == NULL)
            (*newHead) = pivot;
        (*newEnd) = tail;
        return pivot;
    }
}


