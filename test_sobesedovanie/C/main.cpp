#include <iostream>

int main(void) {
	long	n, num, prev;

	std::cin >> n;
	if (!n)
		return 0;
	std::cin >> prev;
	std::cout << prev << std::endl;
	for (int i = 1; i < n; ++i) {
		std::cin >> num;
		if (num != prev) {
			std::cout << num << std::endl;
			prev = num;
		}
	}
}