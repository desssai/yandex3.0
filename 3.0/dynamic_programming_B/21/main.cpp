#include <iostream>
#include <fstream>
#include <climits>
#include <vector>

int main(void) {
	std::ifstream		file("input.txt", std::ifstream::in);
	int					n = 0;
	std::vector<int>	dp;

	if (!file.is_open())
		return 1;

	file >> n;
	dp.resize(n + 1, 0);
	for (int i = 1, j = 1, t = 1; i <= n; ++i) {
		dp[i] = INT_MAX;
		while (j <= i) {
			if (j == i)
				dp[i] = 1;
			else if (dp[i] > dp[i - j])
				dp[i] = dp[i - j] + 1;
			t++;
			j = t * t * t;
		}
		j = 1;
		t = 1;
	}
	std::cout << dp[n] << std::endl;
	file.close();
	return 0;
}