#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream		file("input.txt", std::ifstream::in);
	short				n, number, x, result;
	std::vector<short>	array;
	
	file >> n;
	array.reserve(n);
	for (short i = 0; i < n; ++i) {
		file >> number;
		array.push_back(number);
	}
	file >> x;
	file.close();

	result = n ? 10000 : 0;
	for (short i = 0; i < n; ++i) {
		if (std::abs(array[i] - x) < std::abs(result - x))
			result = array[i];
	}
	std::cout << result << std::endl;
}