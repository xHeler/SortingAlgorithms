#pragma once
#include <iostream>

class Movie {
private:
    int rating;
    std::string title;
public:
    Movie() = default;
    Movie(int rating, const std::string &title);

    Movie(std::string line);


    int getRating() const;

    void setRating(int rating);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    void show();
};