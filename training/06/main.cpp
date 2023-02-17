#include <iostream>
#include <fstream>
#include <vector>

void	getSystemCount(std::vector<std::pair<int, int> >& array, int& ar_size) {
	int									res = 0;

	for (int i = ar_size - 1; i >= 0; --i) {
		bool isPlaced = true;
		for (int j = i + 1; j < ar_size; ++j) {
			if (!(array[i].first > array[j].second || array[i].second < array[j].first))
				isPlaced = false;
		}
		if (isPlaced)
			res++;
	}
	std::cout << res << std::endl;
}

int main(void) {
	int									m = 0;
	int									n = 0;
	std::vector<std::pair<int, int> >	array;
	std::ifstream						file;
	

	file.open("input.txt", std::ifstream::in);
	if (file) {
		file >> m;
		file >> n;
		
		array.reserve(n);
		for (int i = 0, j = 0, k = 0; i < n; ++i) {
			file >> j;
			file >> k;
			array[i] = std::pair<int, int>(j, k);
		}
		getSystemCount(array, n);
		file.close();
	}
}