#include <iostream>
#ifndef TASKFUNCTIONS_H
#define TASKFUNCTIONS_H

// Øàáëîí äëÿ ñîçäàíèÿ ìàññèâà
template <typename T>
void MakeArray(T* array, size_t size) {
	std::cout << "Ââåäèòå ýëåìåíòû ìàññèâà:\n";
	for (size_t i = 0; i < size; ++i) {
		std::cin >> array[i];
	}
}

template <typename T>
void InputElementForSearch(T& element) {
	std::cout << "Ââåäèòå ýëåìåíò äëÿ ïîèñêà\n";
	std::cin >> element;
}

// Øàáëîí äëÿ ïîèñêà ýëåìåíòà â ìàññèâå
template <typename T>
int16_t FindElement(T* array, size_t size, T element) {
	for (size_t i = 0; i < size; ++i) {
		if (array[i] == element) {
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


//template<typename T>
//void FindFirstZeroIndex(T* array, int32_t size, int32_t& firstZeroInd);
//
//template<typename T>
//void FindLastZeroIndex(T* array, int32_t size, int32_t& lastZeroInd);

template<typename T>
void FindFirstZeroIndex(T* array, int32_t size ) {
	int32_t firstZeroInd{ -1 };
	for (size_t i = 0; i < size; ++i) {
		if (static_cast<int32_t>(array[i]) == 48 || array[i] == 0) {
			firstZeroInd = i;
			break;
		}
	}
}

template<typename T>
void FindLastZeroIndex(T* array, int32_t size, int32_t& lastZeroInd) {
	for (int32_t i = (size - 1); i > -1; --i) {
		if (static_cast<int32_t>(array[i]) == 48 || array[i] == 0) {
			lastZeroInd = i;
			break;
		}
	}
}

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
void RemoveNegativesToZeros(int32_t*, int32_t);
double CalculateAverage(int32_t*, int16_t);
double CalculateAverage(char*, int16_t) = delete;


// Øàáëîí äëÿ óäàëåíèÿ îòðèöàòåëüíûõ
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

// Øàáëîí ñóììèðîâàíèÿ ïðîñòûõ ÷èñåë
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


// Øàáëîí äëÿ îáðàáîòêè îïåðàöèé ñ ìàññèâîì
template <typename T>

void ActionsWithArrays(T* array, size_t size, int8_t code_type_array) {
		std::cout << "Ââåäèòå íåîáõîäèìûé íîìåð ôóíêöèè:\n";
		std::cout << "[1] Âûâåñòè ýëåìåíòû ìàññèâà íà êîíñîëü \n";
		std::cout << "[2] Ïîèñê ýëåìåíòà \n";
		std::cout << "[3] Ïîèñêà êîë-âà ýëåìåíòîâ ìåæäó ïåðâûì è ïîñëåäíèì 0-ûì ýëåìåíòàìè \n";
		std::cout << "[4] Âûâîä íîìåðà ìàêñèìàëüíîãî è ìèíèìàëüíîãî ýëåìåíòà \n";
		std::cout << "[5] Ñðåäíåå àðèôìèòè÷åìåîãî ìàêñèìàëüíîãî è ìèíèìàëüíîãî ýëåìåíòà\n";
		std::cout << "[6] Ñóììà âñåõ ïðîñòûõ \n";
		std::cout << "[7] Ñîðòèðîâêà ïóçûðüêîì \n";
		std::cout << "[8] Ïîìåíÿòü ïîðÿäîê ýëåìåíòîâ ìàññèâà íà îáðàòíûé. \n";
		std::cout << "[9] Óäàëèòü èç ìàññèâà âñå îòðèöàòåëüíûå ÷èñëà \n";
		uint8_t num_of_function = 0;
		std::cin >> num_of_function;
		switch (num_of_function) {
		case '1': PrintArray(array, size); break;
		case '2': 
		T element{};
		InputElementForSearch(element);
		std::cout << FindElement(array, size, element); break;
		case '3': std::cout << CountElements(array, size); break;
		case '4': if (code_type_array != 0) {
			std::cout << "Íå ïîääåðæèâàåìûé òèï ìàññèâà\n";
		}
				else {
			std::cout << MaxElement(array, size);
			std::cout << MinElement(array, size);
		}
				break;
		case '5': if (code_type_array != 0) {
			std::cout << "Íå ïîääåðæèâàåìûé òèï ìàññèâà\n";
		}
				else {
			std::cout << CalculateAverage(array, size);
		}
				break;
		case '6': if (code_type_array != 0) {
			std::cout << "Íå ïîääåðæèâàåìûé òèï ìàññèâà\n";
		}
				else {
			std::cout << SumOfSimpleNums(array, size);
		}
				break;
		case '7': BubbleSort(array, size);
				  std::cout << "Ìàññèâ ïîñëå ñîðòèðîâêè:\n";
				  PrintArray(array, size);
				  break;
		case '8': ArrayReverse(array, size);
				  std::cout << "Ìàññèâ ïîñëå ðåâåðñà:\n";
				  PrintArray(array, size);
				  break;
		case '9': if (code_type_array == 2) {
			std::cout << "Íå ïîääåðæèâàåìûé òèï ìàññèâà:\n";
		}
				else {
			RemoveNegativesToZeros(array, size);
			std::cout << "Ìàññèâ ïîñëå çàìåíà îòðèöàòåëüíûõ:\n";
			PrintArray(array, size);
			break;
		}
		default:
			std::cout << "Íåâåðíî çàäàííûé ïàðàìåòð\n";
		}
}


#endif