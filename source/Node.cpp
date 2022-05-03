#include "Node.h"

Node::Node(Movie movie) {
    this->movie = movie;
    this->next = nullptr;
}

const Movie Node::getMovie() const {
    return movie;
}

void Node::setMovie(const Movie &movie) {
    Node::movie = movie;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}
