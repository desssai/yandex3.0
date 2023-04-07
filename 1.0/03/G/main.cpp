#include <iostream>
#include <unordered_set>

int main(void) {
	std::unordered_set<int>	TurtlesThatSayTheTruth;
	int	n, a, b, res = 0;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b;
		if (a > -1 && b > -1 && a + b + 1 == n && TurtlesThatSayTheTruth.find(a * 100000 + b) == TurtlesThatSayTheTruth.end()) {
			TurtlesThatSayTheTruth.insert(a * 100000 + b);
			res++;
		}
	}
	std::cout << res << std::endl;
}