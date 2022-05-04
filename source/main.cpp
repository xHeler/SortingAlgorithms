#include "Driver.h"

int main()
{
    //Driver driver("data.csv", SIZES[3]);
    List test;
    test.add(Movie(10, "Test3"));
    test.add(Movie(2, "Test1"));
    test.add(Movie(3, "Test2"));
    test.sort();
    test.printList();
}

