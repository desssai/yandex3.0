#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main(void) {
	std::ofstream	file("input.txt", std::ifstream::out);
	
	std::srand(std::time(nullptr));
	file << '[';
	for (int i = 0; i < 499; ++i)
		file << std::rand() % 1001 << ',';
	file << std::rand() % 1001 << ']' << std::endl;
	file << std::rand() % 10001 << std::endl;
}