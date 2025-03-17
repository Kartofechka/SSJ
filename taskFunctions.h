#ifndef TASKFUNCTIONS_H
#define TASKFUNCTIONS_H

template<typename T>
void PrintArray(T* array, int32_t size) {
	for (size_t index = 0; index < size; ++index) {
		std::cout << array[index] << " ";
	}
	std::cout << std::endl;
}


template<typename T>
void FindFirstZeroIndex(T* array, int32_t size, int32_t& firstZeroInd);

template<typename T>
void FindLastZeroIndex(T* array, int32_t size, int32_t& lastZeroInd);


template<typename T>
int32_t CountElements(T* array, int32_t size) {
	int32_t firstZeroInd{ -1 };
	int32_t lastZeroInd{ -1 };

	FindFirstZeroIndex(array, size, firstZeroInd);
	FindLastZeroIndex(array, size, lastZeroInd);

	if (firstZeroInd == lastZeroInd) {
		return -1;
	}
	else {
		return lastZeroInd - firstZeroInd - 1;
	}
}

template<typename T>
void FindFirstZeroIndex(T* array, int32_t size, int32_t& firstZeroInd) {
	for (size_t i = 0; i < size; ++i) {
		if (static_cast<int32_t>(array[i]) == 48 || array[i] == 0) {
			firstZeroInd = i;
			break;
		}
	}
}

template<typename T>
void FindLastZeroIndex(T* array, int32_t size, int32_t& lastZeroInd) {
	for (int32_t i = (size-1); i > -1; --i) {
		if (static_cast<int32_t>(array[i]) == 48 || array[i] == 0) {
			lastZeroInd = i;
			break;
		}
	}
}

template<typename T>
void BubbleSort(T& array, int32_t size) {
	
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t j = 0; j < size - 1 - i; ++j) {
			if (array[j] > array[j + 1]) {
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

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


int16_t const MAX_ARRAY_SIZE{ 20 };

template <class type>
void ArrayReverse(type* array, int16_t arraySize) {
	type tempArray[MAX_ARRAY_SIZE]{};
	for (int16_t i{}; i < arraySize; ++i) {
		tempArray[i] = array[arraySize - i - 1];
	}
	for (int16_t j{}; j < arraySize; ++j) {
		array[j] = tempArray[j];
	}
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