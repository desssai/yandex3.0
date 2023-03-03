#include <iostream>
#include <fstream>

int main(void) {
	std::ifstream					file("input1.txt", std::ifstream::in);
	int*							matrix = nullptr;
	int*							result = nullptr;
	int								n = 0, m = 0;

	if (!file)
		return 1;

	file >> n >> m;

	matrix = new int [n * m];
	if (!matrix) {
		file.close();
		return 1;
	}

	result = new int [n * m];
	if (!result) {
		delete [] matrix;
		file.close();
		return 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0, num = 0; j < m; ++j)
			file >> matrix[i * m + j];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!i && !j)
				result[0] = matrix[0];
			else if (!i)
				result[j] = result[j - 1] + matrix[j];
			else if (!j)
				result[i * m] = result[(i - 1) * m] + matrix[i * m];
			else
				result[i * m + j] = std::min(result[(i - 1) * m + j], result[i * m + j - 1]) + matrix[i * m + j];
		}
	}

	std::cout << result[n * m - 1] << std::endl;
	delete [] matrix;
	delete [] result;
	file.close();
	return 0;
}