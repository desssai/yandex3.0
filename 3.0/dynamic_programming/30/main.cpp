#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream						file("input.txt", std::ifstream::in);
	int									n = 0, m = 0;
	std::vector<short>					result;
	std::vector<short>					num1;
	std::vector<short>					num2;
	std::vector<std::vector<short> >	dp;

	if (!file.is_open())
		return 1;

	file >> n;
	num1.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		file >> num1[i];
	}

	file >> m;
	num2.resize(m + 1, 0);
	for (int i = 1; i <= m; ++i)
		file >> num2[i];

	dp.resize(n + 1, std::vector<short>(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (num1[i] == num2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	while (n && m) {
		if (num1[n] == num2[m]) {
			result.push_back(num1[n]);
			n--;
			m--;
		}
		else if (dp[n][m] == dp[n - 1][m])
			n--;
		else
			m--;
	}

	while (result.size()) {
		std::cout << result.back() << " ";
		result.pop_back();
	}
	std::cout << std::endl;
	file.close();
	return 0;
}