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
