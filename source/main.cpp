#include "Driver.h"

int main()
{
    List list;
    list.add(Movie(1, "Yrsdf"));
    list.add(Movie(10, "dfdfg"));
    list.add(Movie(2, "qasdasdasd"));
    list.add(Movie(11, "qasdasdasd"));
    //list.qsort();
    //list.msort();
    list.ssort();
    list.printList();
}

