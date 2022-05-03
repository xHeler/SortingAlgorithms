#pragma once
#include "Movie.h"

class Node {
private:
    Movie movie;
    Node* next;
public:
    Node(Movie movie);

    const Movie getMovie() const;

    void setMovie(const Movie &movie);

    Node *getNext() const;

    void setNext(Node *next);
};