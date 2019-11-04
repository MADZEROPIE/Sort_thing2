#include "sorts.h"
#include <ctime>
#include <gtest.h>
#include <algorithm>

TEST(Quick_sort, sort_test_1) {
	srand(time(0));
	const int size = 30;
	int arr[size], exp_arr[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = exp_arr[i] = rand();
	}
	quick_sort(arr, size);
	std::sort(exp_arr, exp_arr + size);
	for (int i = 0; i < size; ++i) {
		ASSERT_EQ(exp_arr[i], arr[i]);
	}
}


TEST(Quick_sort, sort_test_2) {
	srand(time(0));
	const int size = 30;
	int arr[size], exp_arr[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = exp_arr[i] = i;
	}
	quick_sort(arr, size);
	std::sort(exp_arr, exp_arr + size);
	for (int i = 0; i < size; ++i) {
		ASSERT_EQ(exp_arr[i], arr[i]);
	}
}

TEST(Quick_sort, sort_test_3) {
	srand(time(0));
	const int size = 30;
	int arr[size], exp_arr[size];
	for (int i = size-1; i>=0; --i) {
		arr[i] = exp_arr[i] = i;
	}
	quick_sort(arr, size);
	std::sort(exp_arr, exp_arr + size);
	for (int i = 0; i < size; ++i) {
		ASSERT_EQ(exp_arr[i], arr[i]);
	}
}

TEST(Quick_sort, sort_test_4) {
	srand(time(0));
	const int size = 1;
	int arr[size], exp_arr[size];
	for (int i = size - 1; i >= 0; --i) {
		arr[i] = exp_arr[i] = i;
	}
	quick_sort(arr, size);
	std::sort(exp_arr, exp_arr + size);
	for (int i = 0; i < size; ++i) {
		ASSERT_EQ(exp_arr[i], arr[i]);
	}
}