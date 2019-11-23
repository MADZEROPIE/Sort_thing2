#include <iostream>
#include "sorts.h"
#include <ctime>
#include <chrono>
#include <fstream>

#define SIZE1 500000
#define SIZE 3000000
#define STEP 100000
#define CASES 7

//using namespace std;

std::pair<long long,long long> tests(int* arr, int size=SIZE+SIZE) {

	for (int i = 0; i < size; ++i) arr[i] = std::rand();
	auto t1 = std::chrono::high_resolution_clock::now();
	radix_sort(arr, size>>1);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	t1 = std::chrono::high_resolution_clock::now();
	quick_sort(arr+ (size >>1), size >>1);
	t2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	
	return std::make_pair(duration,duration2);
}


int main(int argc, char** argv)
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	std::ofstream fout; //Τΰιλ
	fout.open("output.csv");
	int* arr = new int[SIZE + SIZE];

	if (fout.is_open()) {
		fout << "sep=,\nN,radix,quick\n";
		int size = SIZE1;
		long long sum1 = 0, sum2 = 0;
		for (int i = 0; i < CASES; ++i) {
			auto dur = tests(arr, size << 1);
			sum1 += dur.first;
			sum2 += dur.second;
		}
		fout << size << ',' << sum1 / CASES << ',' << sum2 / CASES;
		for (size = SIZE1+STEP; size<SIZE; size+=STEP) {
			long long sum1 = 0, sum2 = 0;
			for (int i = 0; i < CASES; ++i) {
				auto dur = tests(arr, size << 1);
				sum1 += dur.first;
				sum2 += dur.second;
			}
			fout << '\n'<<size<<','<<sum1 / CASES << ',' << sum2 / CASES;
		}
	}

	delete[] arr;
	fout.close();
	return 0;
}

