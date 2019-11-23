#pragma once
//#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}


template<typename T>
void quick_sort(T arr[], int right) {//Версия, при которой выбирается случайный элемент
	if (right > 0) {
		int rand_id = std::rand()%right;
		int k = 0;
		swap(arr[0], arr[rand_id]);
		for (int i = 1; i < right; ++i) {
			if (arr[i] < arr[0]) {
				swap(arr[i], arr[++k]);
			}
		}
		swap(arr[0], arr[k]);
		quick_sort(arr, k);
		quick_sort(arr + k + 1, right-k-1);
	}
}
/*
void quick_sort2(int arr[], int right) {//Версия, при которой выбирается самый левый элемент (копипаста из https://github.com/MADZEROPIE/Sort_things1)
	if (right > 0) {
		int k = 0;
		for (int i = 1; i < right; i++)
			if (arr[i] < arr[0]) {
				k++;
				swap(arr[i], arr[k]);
			}
		swap(arr[0], arr[k]);
		quick_sort(arr, k);
		quick_sort(arr + k + 1, right - k - 1);
	}
}
*/

int get_max(int a[], int n);

void count_sort(int a[], int n, int num);

void radix_sort(int a[], int n);