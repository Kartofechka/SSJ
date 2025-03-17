#include <iostream>
#ifndef TASKFUNCTIONS_H
#define TASKFUNCTIONS_H

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
int16_t FindElement(T* array, size_t size) {
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

template<typename T>
void PrintArray(T* array, size_t size) {
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
void BubbleSort(T& array, size_t size) {
	
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

// Шаблон для удаления отрицательных
template <typename T>
void RemoveNegativesToZeros(T* array , size_t size) {
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

// Шаблон суммирования простых чисел
template <typename T>
int64_t SumOfSimpleNums(T* arr, size_t size) {
	int32_t sum_of_simple{};
	for (size_t i = 0; i < size; ++i) {
		if (IsSimple(arr[i])) {
			sum_of_simple += arr[i];
		}
	}
	return sum_of_simple;
}


template <class type>
int32_t MaxElement(type* array, size_t arraySize) {
	int32_t maxElementIndex{};
	type maxElement{ array[0] };
	int32_t index{};
	while (index < arraySize) {
		if (array[++index] > maxElement) {
			maxElement = array[index];
			maxElementIndex = index;
		}
	}
	return maxElementIndex;
}

template <class type>
int32_t MinElement(type* array, size_t arraySize) {
	int32_t minElementIndex{};
	type minElement{ array[0] };
	int32_t index{};
	while (index < arraySize) {
		if (array[++index] < minElement) {
			minElement = array[index];
			minElementIndex = index;
		}
	}
	return minElementIndex;
}

template <class type>
void ArrayReverse(type* array, int16_t arraySize) {
	type tempArray[100]{};
	for (int16_t i{}; i < arraySize; ++i) {
		tempArray[i] = array[arraySize - i - 1];
	}
	for (int16_t j{}; j < arraySize; ++j) {
		array[j] = tempArray[j];
	}
}

template <class type>
double CalculateAverage(type* array, size_t arraySize) {
	return (array[MaxElement(array, arraySize)] + array[MinElement(array, arraySize)]) * 0.5;
}

// Шаблон для обработки операций с массивом
template <typename T>
void ActionsWithArrays(T* array, size_t size, int8_t code_type_array) {
		std::cout << "Введите необходимый номер функции:\n";
		std::cout << "[1] Вывести элементы массива на консоль \n";
		std::cout << "[2] Поиск элемента \n";
		std::cout << "[3] Поиска кол-ва элементов между первым и последним 0-ым элементами \n";
		std::cout << "[4] Вывод номера максимального и минимального элемента \n";
		std::cout << "[5] Среднее арифмитичемеого максимального и минимального элемента\n";
		std::cout << "[6] Сумма всех простых \n";
		std::cout << "[7] Сортировка пузырьком \n";
		std::cout << "[8] Поменять порядок элементов массива на обратный. \n";
		std::cout << "[9] Удалить из массива все отрицательные числа \n";
		uint8_t num_of_function = 0;
		std::cin >> num_of_function;
		switch (num_of_function) {
		case '1': PrintArray(array, size); break;
		case '2': std::cout << FindElement(array, size); break;
		case '3': std::cout << CountElements(array, size); break;
		case '4': if (code_type_array != 0) {
			std::cout << "Не поддерживаемый тип массива\n";
		}
				else {
			std::cout << MaxElement(array, size);
			std::cout << MinElement(array, size);
		}
				break;
		case '5': if (code_type_array != 0) {
			std::cout << "Не поддерживаемый тип массива\n";
		}
				else {
			std::cout << CalculateAverage(array, size);
		}
				break;
		case '6': if (code_type_array != 0) {
			std::cout << "Не поддерживаемый тип массива\n";
		}
				else {
			std::cout << SumOfSimpleNums(array, size);
		}
				break;
		case '7': BubbleSort(array, size);
				  std::cout << "Массив после сортировки:\n";
				  PrintArray(array, size);
				  break;
		case '8': ArrayReverse(array, size);
				  std::cout << "Массив после реверса:\n";
				  PrintArray(array, size);
				  break;
		case '9': if (code_type_array == 2) {
			std::cout << "Не поддерживаемый тип массива:\n";
		}
				else {
			RemoveNegativesToZeros(array, size);
			std::cout << "Массив после замена отрицательных:\n";
			PrintArray(array, size);
			break;
		}
		default:
			std::cout << "Неверно заданный параметр\n";
		}
}

#endif