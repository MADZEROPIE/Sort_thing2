#include <iostream>
#include "sorts.h"
#include <ctime>
#include <chrono>
#include <fstream>


#define SIZE 1000000
#define CASES 30000

//using namespace std;
std::pair<long long,long long> tests(int* arr, int size=SIZE+SIZE) {
	srand(time(0));

	for (int i = 0; i < SIZE+SIZE; ++i) arr[i] = std::rand();
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
//	srand(0);
	setlocale(LC_ALL, "Russian");
	std::ofstream fout; //Τΰιλ
	fout.open("output.csv");
	int* arr = new int[SIZE + SIZE];
	if (fout.is_open()) {
		fout << "sep=,\n";
		fout << "radix,quick\n";
		auto dur = tests(arr);
		fout << dur.first<<','<<dur.second;
		for (int i = 1; i < CASES; ++i) {
			auto dur = tests(arr);
			fout << ",\n" << dur.first << ',' << dur.second;
		}
	}
	delete[] arr;
	fout.close();
	return 0;
}

