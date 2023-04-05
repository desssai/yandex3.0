#include <algorithm>
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>

int main(void) {
	std::ifstream		file("input.txt", std::ifstream::in);
	std::vector<int>	result;
	int					n = 0;
	std::vector<int>	array;

	if (!file)
		return 1;

	file >> n;
	result.resize(n, 0);
	array.resize(n, 0);
	for (int i = 0; i <= n; ++i)
		file >> array[i];
	std::sort(array.begin(), array.end());

	for (int i = 1; i < n; ++i) {
		if (i == 1)
			result[i] = array[i] - array[i - 1];
		else if (i == 2)
			result[i] = array[i] - array[i - 2];
		else
			result[i] = std::min(result[i - 2], result[i - 1]) + array[i] - array[i - 1];
	}

	std::cout << result[n - 1] << std::endl;
	file.close();
	return 0;
}