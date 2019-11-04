#include <iostream>
#include "sorts.h"


int main(int argc, char** argv)
{
	srand(0);
	setlocale(LC_ALL, "Russian");
	int arr[6];
	for (int i = 1; i < 7; ++i) arr[i-1] = rand();
	for (int i = 0; i < 6; ++i) std::cout << arr[i] << " ";
	std::cout << std::endl;
	quick_sort(arr, 6);
	for (int i = 0; i < 6; ++i) std::cout << arr[i] << " ";
	std::cout << std::endl;
	return 0;
}

