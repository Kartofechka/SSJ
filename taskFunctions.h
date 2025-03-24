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
size_t MaxElement(type* array, int16_t arraySize) {
	size_t maxElementIndex{};
	for (size_t index{ 1 }; index < arraySize; ++index) {
		if (array[index] > array[maxElementIndex]) {
			maxElementIndex = index;
		}
	}
	return maxElementIndex;
}


template <class type>
size_t MinElement(type* array, int16_t arraySize) {
	size_t minElementIndex{};
	for (size_t index{ 1 }; index < arraySize; ++index) {
		if (array[index] < array[minElementIndex]) {
			minElementIndex = index;
		}
	}
	return minElementIndex;
}



template <class type>
void ArrayReverse(type* array, int16_t arraySize) {
	size_t swapArraySize{};
	swapArraySize = arraySize * 0.5;
	for (size_t index{}; index < swapArraySize; ++index) {
		std::swap(array[index], array[arraySize - index - 1]);
	}
}


template <class type>
double CalculateAverage(type* array, size_t arraySize) {
	return (array[MaxElement(array, arraySize)] + array[MinElement(array, arraySize)]) * 0.5;
}

// Шаблон для обработки операций с массивом
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