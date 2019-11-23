#include "sorts.h"
//#include <iostream>
//#include <cstdlib>
//#include <ctime>

int get_max(int a[], int n)
{
	int m = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > m)
			m = a[i];
	return m;
}

void count_sort(int a[], int n, unsigned long long int num)
{
	int* temp_arr = (int*)malloc(n * sizeof(a[0]));
	int count[16] = { 0 };
	for (int i = 0; i < n; ++i)
		++count[(a[i] / num) % 16];
	for (int i = 1; i < 16; ++i)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; --i) {
		temp_arr[count[(a[i] / num) % 16] - 1] = a[i];
		--count[(a[i] / num) % 16];
	}
	for (int i = 0; i < n; ++i)
		a[i] = temp_arr[i];
	free(temp_arr);
}

void radix_sort(int a[], int n)
{
	int m = get_max(a, n);
	for (unsigned long long int num = 1; m / num > 0; num = num<<4)
		count_sort(a, n, num);
}
