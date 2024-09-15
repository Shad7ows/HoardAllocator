#include <iostream>
#include <chrono>
using namespace std::chrono;

int main() {
	int* a{};

	auto start = high_resolution_clock::now();
	for (auto i = 0; i < 50000000; i++) {
		a = new int();
		delete a;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << duration.count() / 1000 << " ms" << std::endl;

	a = new int();
	*a = 99999;
	std::cout << *a << std::endl;

	return 9;
}