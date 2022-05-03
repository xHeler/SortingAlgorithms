#include "Movie.h"

Movie::Movie(int rating, const std::string &title) : rating(rating), title(title) {
    this->rating = rating;
    this->title = title;
}

int Movie::getRating() const {
    return rating;
}

void Movie::setRating(int rating) {
    Movie::rating = rating;
}

const std::string &Movie::getTitle() const {
    return title;
}

void Movie::setTitle(const std::string &title) {
    Movie::title = title;
}

void Movie::show() {
    std::cout << "Rating: " << rating << std::endl;
    std::cout << "Title: " << title << std::endl;
}

Movie::Movie(std::string line) {
    int rating = 0;
    std::string title = "";
    std::string delimiter = ",";

    int i = 0;
    size_t pos = 0;
    std::string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        if (i == 1) {
            title = token;
            int position = line.find(delimiter);
            if (position != -1) {
                token = line.substr(0, position);
                line.erase(0, position + delimiter.length());
                title += token;
                break;
            }
        }

        i++;
    }
    rating = atoi( line.c_str());
    this->rating = rating;
    this->title = title;
}
