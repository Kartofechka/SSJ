#ifndef Task_Functions_H
#define Task_Functions_H

void InputSize(int32_t&);
bool CheckSize(int32_t);
void ChoseTypeOfElement(int32_t);
int32_t SumOfSimpleNums(int32_t*, int32_t);
bool IsSimple(int32_t);
void RemoveNegativesToZeros(int32_t*, int32_t);


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
#endif