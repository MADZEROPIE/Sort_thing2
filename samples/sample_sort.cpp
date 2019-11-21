#include <iostream>
#include "sorts.h"
#include <ctime>
#include <chrono>
#include <fstream>

#define SIZE1 500000
#define SIZE2 1000000
#define SIZE 2000000

#define CASES 300

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
		fout << "sep=,\nradix,,,quick\n";
		fout << SIZE1 << ',' << SIZE2 << ',' << SIZE <<','<< SIZE1 << ',' << SIZE2 << ',' << SIZE<<'\n';
		
		auto dur = tests(arr, SIZE1 << 1);
		auto dur3 = tests(arr);
		auto dur2 = tests(arr,SIZE2<<1);
		
		fout << dur.first<<',' << dur2.first<< ',' << dur3.first << ',' << dur.second << ',' << dur2.second << ',' << dur3.second;

		for (int i = 1; i < CASES; ++i) {

			auto dur = tests(arr, SIZE1 << 1);
			auto dur2 = tests(arr, SIZE2 << 1);
			auto dur3 = tests(arr);

			fout << ",\n" << dur.first << ',' << dur2.first << ',' << dur3.first << ',' << dur.second << ',' << dur2.second << ',' << dur3.second;
		}
	}
	delete[] arr;
	fout.close();
	return 0;
}

