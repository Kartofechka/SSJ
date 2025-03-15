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