#include <iostream>
#include <fstream>
#include <vector>

void	findSmallestRectangle(std::vector<std::pair<int, int> >& array, int& size) {
	std::pair<int, int>	x1(array[0].first, array[0].second);
	std::pair<int, int>	x2(array[0].first, array[0].second);
	
	for (int i = 1; i < size; ++i) {
		x1.first = (x1.first < array[i].first ? x1.first : array[i].first);
		x1.second = (x1.second < array[i].second ? x1.second : array[i].second);
		x2.first = (x2.first > array[i].first ? x2.first : array[i].first);
		x2.second = (x2.second > array[i].second ? x2.second : array[i].second);
	}
	std::cout << x1.first << " " << x1.second << " " << x2.first << " " << x2.second << std::endl;
}

int main(void) {
	std::vector<std::pair<int, int> >	array;
	std::ifstream						file;
	int									k = 0;

	file.open("input1.txt", std::ifstream::in);
	if (file) {
		file >> k;
		
		array.reserve(k);
		for (int i = 0, j1 = 0, j2 = 0; i < k; ++i) {
			file >> j1 >> j2;
			array[i] = std::pair<int, int>(j1, j2);
		}
		findSmallestRectangle(array, k);
		file.close();
	}
}