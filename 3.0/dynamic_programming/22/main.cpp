#include <iostream>
#include <fstream>

int main(void) {
	std::ifstream	file;
	int*			array = nullptr;
	short			n = 0, k = 0;

	file.open("input1.txt", std::ifstream::in);
	if (file) {
		file >> n >> k;
		array = new int[n];
		if (!array) {
			file.close();
			return 1;	
		}
		array[0] = 1;
		array[1] = 1;
		for (int i = 2; i < n; ++i) {
			array[i] = 0;
			for (int j = i - 1; j >= 0 && i - j <= k; --j)
				array[i] += array[j];
		}
		std::cout << array[n - 1] << std::endl;
		delete array;
		file.close();
	}


}