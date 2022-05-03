#pragma once
#include "List.h"

const int SIZES[] = {10000, 100000, 500000, 1000000};

class Driver {
private:
    List list;
public:
    Driver(std::string fileName, int size);
};