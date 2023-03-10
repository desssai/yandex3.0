#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream		file("input.txt", std::ifstream::in);
	int					n = 0, buf = 0;
	std::vector<int>	result;
	std::vector<int>	array;
	std::vector<int>	dp;

	if (!file.is_open())
		return 1;

	file >> n;
	dp.resize(n, 0);
	array.resize(n, 0);
	
	for (int i = 0; i < n; ++i) {
		file >> array[i];
	}

	for (int i = 1; i < n; ++i) {
		buf = -1;
		for (int j = 0; j < i; ++j) {
			if (array[j] < array[i] && dp[j] > buf) {
				buf = dp[j];
			}
			dp[i] = buf + 1;
		}
	}

	buf = 0;
	for (int i = 0; i < n; ++i) {
		if (buf < dp[i])
			buf = dp[i];
	}
	
	for (int i = n - 1; i > -1; --i) {
		if (dp[i] == buf) {
			result.push_back(array[i]);
			buf--;
		}
	}

	while (result.size()) {
		std::cout << result.back() << " ";
		result.pop_back();
	}
	std::cout << std::endl;
	file.close();
	return 0;
}