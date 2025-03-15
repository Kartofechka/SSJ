#include "taskFunctions.h"

// ������ ��� �������� �������
template <typename T>
void MakeArray(T* array, size_t size) {
    std::cout << "������� �������� �������:\n";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

// ������ ��� ������ �������� � �������
template <typename T>
int FindElement(T* array, size_t size) {
    T value{};
    std::cout << "������� ����������� ������� ��� ������:\n";
    std::cin >> value;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

// ������� ����� ������� �������
void InputSize(int32_t& size) {
    std::cout << "Input size of array: \n";
    std::cin >> size;
}

// ������� �������� ������� �������
bool CheckSize(int32_t size) {
    return size > 0 && size <= 100;
}

// ������� ������ ���� ���������
void ChoseTypeOfElement(int32_t size) {
    std::cout << "�������� ����������� ��� ���������:\n";
    std::cout << "[1] - integer\n";
    std::cout << "[2] - double\n";
    std::cout << "[3] - char\n";
    std::string choosen_type{};
    std::cin >> choosen_type;
    if (choosen_type != "1" && choosen_type != "2" && choosen_type != "3") {
        std::cout << "�������� ����� �����!\n";
        return;
    }

    if (choosen_type == "1") {
        int32_t arr[100]{};
        MakeArray(arr, size);
        std::cout << "����� ������� ����� = ";
        std::cout << SumOfSimpleNums(arr, size) << '\n';
        std::cout << "������ ���������� �������� = " << FindElement(arr, size) << '\n';
        RemoveNegativesToZeros(arr, size);
    }
    else if (choosen_type == "2") {
        double arr[100]{};
        MakeArray(arr, size);
        std::cout << "������ ���������� �������� = " << FindElement(arr, size) << '\n';
    }
    else {
        char arr[100]{};
        MakeArray(arr, size);
        std::cout << "������ ���������� �������� = " << FindElement(arr, size) << '\n';
    }
}

// ������� ���������� ������� �����
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

// ������� ������������ ������� �����
int32_t SumOfSimpleNums(int32_t* arr, int32_t size) {
    int32_t sum_of_simple{};
    for (size_t i = 0; i < size; ++i) {
        if (IsSimple(arr[i])) {
            sum_of_simple += arr[i];
        }
    }
    return sum_of_simple;
}

// ������� ������ ������������� �� ����
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