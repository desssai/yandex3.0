#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream					file("input.txt", std::ifstream::in);
	int								n = 0, m = 0, buf = 0;
	std::vector<std::vector<int> >	dp;

	if (!file.is_open())
		return 1;

	file >> n >> m;
	dp.resize(n, std::vector<int>(m, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i && j < m; ++j) {
			if (i > 1 && j)
				dp[i][j] += dp[i - 2][j - 1];
			if (i > 1 && j < m - 1)
				dp[i][j] += dp[i - 2][j + 1];
			if (j > 1 && i)
				dp[i][j] += dp[i - 1][j - 2];
			if (j > 1 && i < n - 1)
				dp[i][j] += dp[i + 1][j - 2];
			if (dp[i][j])
				dp[i][j]++;
		}
		for (int j = i; j >= 0; --j) {
			if (j > 1 && i)
				dp[j][i] += dp[j - 2][i - 1];
			if (j > 1 && i < m - 1)
				dp[j][i] += dp[j - 2][i + 1];
			if (i > 1 && j)
				dp[j][i] += dp[j - 1][i - 2];
			if (i > 1 && j < n - 1)
				dp[j][i] += dp[j + 1][i - 2];
			if (dp[j][i])
				dp[j][i]++;
		}
	}
	if (m > n) {
		for (int i = n; i < m; ++i) {
			for (int j = n - 1; j >= 0; --j) {
				if (j > 1 && i)
					dp[j][i] += dp[j - 2][i - 1];
				if (j > 1 && i < m - 1)
					dp[j][i] += dp[j - 2][i + 1];
				if (i > 1 && j)
					dp[j][i] += dp[j - 1][i - 2];
				if (i > 1 && j < n - 1)
					dp[j][i] += dp[j + 1][i - 2];
				if (dp[j][i])
					dp[j][i]++;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << dp[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << dp[n - 1][m - 1] << std::endl;
	file.close();
	return 0;
}