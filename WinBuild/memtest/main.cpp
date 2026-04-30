#include <iostream>
#include <chrono>
using namespace std::chrono;

int main() {
	int* a{};

	auto start = high_resolution_clock::now();
	for (auto i = 0; i < 50000000; i++) {
		a = (int*)malloc(4);
		*a += i;
		free(a);
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << duration.count() / 1000 << " ms" << std::endl;

	a = (int*)malloc(4);
	*a = 10;
	std::cout << *a << std::endl;

	return 9;
}