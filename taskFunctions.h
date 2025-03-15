#ifndef TASKFUNCTIONS_H
#define TASKFUNCTIONS_H

template<typename T>
void PrintArray(T* array, int32_t size) {
	for (size_t index = 0; index < size; ++index) {
		std::cout << array[index] << " ";
	}
	std::cout << std::endl;
}


#endif

