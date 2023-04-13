#include <iostream>

int main(void) {
	int	n, num, count = 0, maximum = 0;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> num;
		if (num)
			count++;
		else {
			maximum = std::max(count, maximum);
			count = 0;
		}
	}
	maximum = std::max(count, maximum);
	std::cout << maximum << std::endl;
}