#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream					file("input.txt", std::ifstream::in);
	int								n = 0, m = 0;
	std::vector<std::vector<int> >	matrix;

	if (!file)
		return 1;

	file >> n >> m;
	matrix.resize(n, std::vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!i && !j)
				matrix[i][j] = 1;
			else if (!i || !j || (i == 1 && j == 1))
				matrix[i][j] = 0;
			else {
				if (j > 1)
					matrix[i][j] += matrix[i - 1][j - 2];
				if (i > 1)
					matrix[i][j] += matrix[i - 2][j - 1];
			}
		}
	}
	std::cout << matrix[n - 1][m - 1] << std::endl;
	file.close();
	return 0;
}