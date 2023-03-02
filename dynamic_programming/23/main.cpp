#include <iostream>
#include <fstream>
#include <stack>

void	findPath(int n) {
	std::stack<int>	s;
	int				dp[1000001];

	memset(dp, 0, 1000001 * sizeof(int));
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2, j = 0; i <= n; ++i) {
		j = dp[i - 1];
		if (!(i % 3) && dp[i / 3] < j)
			j = dp[i / 3];
		if (!(i % 2) && dp[i / 2] < j)
			j = dp[i / 2];
		dp[i] = j + 1;
	}
	std::cout << dp[n] << std::endl;

	while (n) {
		s.push(n);
		if (!(n % 3) && dp[n / 3] == dp[n] - 1)
			n /= 3;
		else if (!(n % 2) && dp[n / 2] == dp[n] - 1)
			n /= 2;
		else
			n--;
	}

	while (s.size()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;

}

int main(void) {
	int				num = 0;
	std::ifstream	file;

	file.open("input.txt", std::ifstream::in);
	if (file) {
		file >> num;
		findPath(num);
		file.close();
	}
	return 0;
}