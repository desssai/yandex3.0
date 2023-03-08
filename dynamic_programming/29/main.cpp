#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream					file("input.txt", std::ifstream::in);
	int								res = 2147483647, used = 0, total = 0;
	int								n = 0, c = 1;
	std::vector<int>				array;
	std::vector<int>				days;
	std::vector<std::vector<int> >	dp;
	
	if (!file.is_open())
		return 1;

	file >> n;
	array.resize(n + 2, 0);
	for (int i = 1; i <= n; ++i) {
		file >> array[i];
		if (array[i] > 100)
			c++;
	}

	dp.resize(n + 1, std::vector<int>(c + 2, 40000));
	dp[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (array[i] > 100)
				dp[i][j] = std::min(dp[i - 1][j - 1] + array[i], dp[i - 1][j + 1]);
			else
				dp[i][j] = std::min(dp[i - 1][j] + array[i], dp[i - 1][j + 1]);
		}
	}

	for (int i = 1; i <= c; ++i) {
		if (res >= dp.back()[i]) {
			res = dp.back()[i];
			used = i;
		}
	}

	c = used;
	used = 0;
	days.reserve(n);
	while (n) {		
		if (dp[n][c] == dp[n - 1][c] + array[n])
			n--;
		else if (dp[n][c] == dp[n - 1][c + 1]) {
			days.push_back(n);
			used++;
			n--;
			c++;
		}
		else if (dp[n][c] == dp[n - 1][c - 1] + array[n] ) {
			n--;
			c--;
			total++;
		}
	}
	
	n = days.size();
	std::cout << res << std::endl;
	std::cout << total - used << " " << used << std::endl;
	while (n)
		std::cout << days[--n] << std::endl;
	file.close();
	return 0;
}