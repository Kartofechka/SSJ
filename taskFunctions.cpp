#include "taskFunctions.h"

// Ôóíêöèÿ ââîäà ðàçìåðà ìàññèâà
void InputSize(int32_t& size) {
    std::cout << "Input size of array: \n";
    std::cin >> size;
}

// Ôóíêöèÿ ïðîâåðêè ðàçìåðà ìàññèâà
bool CheckSize(int32_t size) {
    return size > 0 && size <= 100;
}

// Ôóíêöèÿ âûáîðà òèïà ýëåìåíòîâ
void ChoseTypeOfElement(int32_t size) {
    std::cout << "Âûáåðèòå íåîáõîäèìûé òèï ýëåìåíòîâ:\n";
    std::cout << "[1] - integer\n";
    std::cout << "[2] - double\n";
    std::cout << "[3] - char\n";
    std::string choosen_type{};
    std::cin >> choosen_type;
    if (choosen_type != "1" && choosen_type != "2" && choosen_type != "3") {
        std::cout << "Íåâåðíûé íîìåð îïöèè!\n";
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

// Ôóíêöèÿ íàõîæäåíèÿ ïðîñòûõ ÷èñåë
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


// Ôóíêöèÿ ñóììèðîâàíèÿ ïðîñòûõ ÷èñåë
int32_t SumOfSimpleNums(int32_t* arr, int32_t size) {
    int32_t sum_of_simple{};
    for (size_t i = 0; i < size; ++i) {
        if (IsSimple(arr[i])) {
            sum_of_simple += arr[i];
        }
    }
    return sum_of_simple;
}

// Ôóíêöèÿ çàìåíû îòðèöàòåëüíûõ íà íîëü
void RemoveNegativesToZeros(int32_t* array, int32_t size) {
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] >= 0) {
            array[index++] = array[i];
        }
    }
    while (index < size) {
        array[index++] = 0;
    }
}


double CalculateAverage(int32_t* array, int16_t arraySize) {
    return (array[MaxElement(array, arraySize)] + array[MinElement(array, arraySize)]) * 0.5;
}
