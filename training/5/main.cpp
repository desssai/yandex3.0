#include <iostream>
#include <fstream>
#include <vector>

void	getGoodNumber(std::vector<int>& array, int& size) {
	long long res = 0;

	for (int i = 0; i < size - 1; ++i)
		res += (array[i] < array[i + 1] ? array[i] : array[i + 1]);
	std::cout << res << std::endl;
}

int main(void) {
	std::ifstream		file;
	std::vector<int>	array;
	int					n = 0;

	file.open("input.txt", std::ifstream::in);
	if (file) {
		file >> n;

		array.reserve(n);
		for (int i = 0, num = 0; i < n; ++i) {
			file >> num;
			array.push_back(num);
		}
		getGoodNumber(array, n);
		file.close();
	}
}