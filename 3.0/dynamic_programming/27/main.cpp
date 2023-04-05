#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream		file("input1.txt", std::ifstream::in);
	short				n = 0, m = 0;
	std::vector<int>	matrix;
	std::vector<int>	result;
	std::vector<char>	moves;

	if (!file)
		return 1;

	file >> n >> m;
	matrix.resize(n * m, 0);
	result.resize(n * m, 0);

	for (short i = 0; i < n; ++i) {
		for (short j = 0; j < m; ++j) {
			file >> matrix[i * m + j];
		}
	}

	for (short i = 0; i < n; ++i) {
		for (short j = 0; j < m; ++j) {
			if (!i && !j)
				result[0] = matrix[0];
			else if (!i)
				result[j] = result[j - 1] + matrix[j];
			else if (!j)
				result[i * m] = result[(i - 1) * m] + matrix[i * m];
			else
				result[i * m + j] = std::max(result[(i - 1 )* m + j], result[i * m + j - 1]) + matrix[i * m + j];
		}
	}

	for (int i = n * m - 1; i > 0;) {
		if (i > m - 1 && (result[i - m] > result[i - 1] || !(i % m))) {
			moves.push_back('D');
			i -= m;
		}
		else {
			moves.push_back('R');
			i -= 1;
		}
	}

	std::cout << result[n * m - 1] << std::endl;
	for (short i = moves.size() - 1; i >= 0; --i)
		std::cout <<  moves[i] << " ";
	std::cout << std::endl;
	file.close();
	return 0;
}
