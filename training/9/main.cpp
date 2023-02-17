#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	int						k = 0, res = 0;
	int						n = 0, m = 0;
	std::pair<int, int>		xy1, xy2;
	std::vector<short>		matrix;
	std::vector<int>		pfSum;
	std::ifstream			file;

	file.open("input3.txt", std::ifstream::in);
	if (file) {
		file >> n >> m >> k;

		matrix.reserve(n * m);
		for (int i = 0, j = 0; i < n * m; ++i) {
			file >> j;
			matrix.push_back(j);
		}

		pfSum.reserve(n * m);
		pfSum.push_back(matrix[0]);
		for (int i = 1; i < n * m; ++i)
			pfSum.push_back(matrix[i] + pfSum[i - 1]);

		for (int i = 0; i < k; ++i) {
			file >> xy1.first >> xy1.second >> xy2.first >> xy2.second;
			xy1.first--; xy2.first--; xy1.second--; xy2.second--;

			res = pfSum[xy2.first * m + xy2.second];
			if (xy1.first || xy1.second)
				res -= pfSum[xy1.first * m + xy1.second] - matrix[xy1.first * m + xy1.second];
			for (short j = xy1.first + 1; j <= xy2.first; ++j)
				res -= pfSum[j * m + xy1.second - 1] - pfSum[(j - 1) * m + xy2.second];

			std::cout << res << std::endl;
		}
		file.close();
	}
}