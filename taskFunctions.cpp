#include "taskFunctions.h"

// Функция ввода размера массива
void InputSize(int32_t& size) {
    std::cout << "Input size of array: \n";
    std::cin >> size;
}

// Функция проверки размера массива
bool CheckSize(int32_t size) {
    return size > 0 && size <= 100;
}

// Функция выбора типа элементов
void ChoseTypeOfElement(int32_t size) {
    std::cout << "Выберите необходимый тип элементов:\n";
    std::cout << "[1] - integer\n";
    std::cout << "[2] - double\n";
    std::cout << "[3] - char\n";
    std::string choosen_type{};
    std::cin >> choosen_type;
    if (choosen_type != "1" && choosen_type != "2" && choosen_type != "3") {
        std::cout << "Неверный номер опции!\n";
        return;
    }

    if (choosen_type == "1") {
        int32_t arr[100]{};
        MakeArray(arr, size);
        ActionsWithArrays(arr, size, 0);
    }
    else if (choosen_type == "2") {
        double arr[100]{};
        MakeArray(arr, size);
        ActionsWithArrays(arr, size, 1);
    }
    else {
        char arr[100]{};
        MakeArray(arr, size);
        ActionsWithArrays(arr, size, 2);
    }
}

// Функция нахождения простых чисел
bool IsSimple(int32_t num) {
    if (num <= 1) {
        return false;
    }
    for (int32_t i{ 2 }; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
