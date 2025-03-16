#ifndef Task_Functions_H
#define Task_Functions_H

void InputSize(int32_t&);
bool CheckSize(int32_t);
void ChoseTypeOfElement(int32_t);
int32_t SumOfSimpleNums(int32_t*, int32_t);
bool IsSimple(int32_t);
void RemoveNegativesToZeros(int32_t*, int32_t);
double CalculateAverage(int32_t*, int16_t);
double CalculateAverage(char*, int16_t) = delete;


template <class type>
int16_t MaxElement(type* array, int16_t arraySize) {
	int16_t maxElementIndex{};
	int32_t maxElement{ array[0] };
	int16_t index{};
	while (index < arraySize) {
		if (array[++index] > maxElement) {
			maxElement = array[index];
			maxElementIndex = index;
		}
	}
	return maxElementIndex;
}


template <class type>
int16_t MinElement(type* array, int16_t arraySize) {
	int16_t minElementIndex{};
	int32_t minElement{ array[0] };
	int16_t index{};
	while (index < arraySize) {
		if (array[++index] < minElement) {
			minElement = array[index];
			minElementIndex = index;
		}
	}
	return minElementIndex;
}

// Шаблон для создания массива
template <typename T>
void MakeArray(T* array, size_t size) {
    std::cout << "Введите элементы массива:\n";
    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

// Шаблон для поиска элемента в массиве
template <typename T>
int FindElement(T* array, size_t size) {
    T value{};
    std::cout << "Введите необходимый элемент для поиска:\n";
    std::cin >> value;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}
#endif