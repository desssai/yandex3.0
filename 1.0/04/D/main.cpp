#include <iostream>
#include <vector>

int main(void) {
	long long			n, k, p;
	std::vector<int>	keys;

	std::cin >> n;
	keys.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		std::cin >> keys[i];
	std::cin >> k;
	for (int i = 0; i < k; ++i) {
		std::cin >> p;
		keys[p]--;
	}
	for (int i = 1; i <= n; ++i)
		std::cout << (keys[i] < 0 ? "YES" : "NO") << std::endl;
}
