#include <iostream>
#include "taskFunctions.h"

int main() {
    setlocale(LC_ALL, ".1251");
    int32_t size{};
    InputSize(size);
    if (!CheckSize(size)) { 
        std::cerr << "Некорректный размер массива!\n";
        return 1;
    }
    ChoseTypeOfElement(size);
    
    return 0;
}

