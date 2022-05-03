#include "Driver.h"
#include <fstream>

void readData(List & list, std::string fileName, int size) {
    while (list.getSize() != size) {
        std::fstream newfile;
        newfile.open(fileName,std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            while(getline(newfile, tp)){
                if (tp[0] == ','){
                    continue;
                }
                Movie m(tp);
                list.add(m);
                if (list.getSize() == size){
                    newfile.close();
                    return;
                }
            }
            newfile.close();
        }
    }
}

Driver::Driver(std::string fileName, int size) {
    readData(list, fileName, size);
    std::cout << "Loading list of size: " << size << std::endl;
}
