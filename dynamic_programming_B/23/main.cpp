#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream			file("input.txt", std::ifstream::in);
	long long				n = 0, upwards, downwards;
	std::vector<long long>	dp;

	if (!file.is_open())
		return 1;

	file >> n;
	dp.resize(n + 1, 0);
	for (long long i = 1; i <= n; ++i) {
		upwards = ((n - i + 1) * (n - i + 2)) / 2;
		downwards = ((i << 1) <= n ? ((n - 2 * i + 1) * (n - 2 * i + 2)) / 2 : 0);
		dp[i] = dp[i - 1] + upwards + downwards;
	}
	std::cout << dp[n] << std::endl;
	file.close();
	return 0;
}