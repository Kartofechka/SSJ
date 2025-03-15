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

#endif

