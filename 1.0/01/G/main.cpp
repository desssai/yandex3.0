#include <iostream>
#include <fstream>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	short			n, k, m, x, res = 0;
	
	file >> n >> k >> m;
	file.close();

	if (n < k || k < m) {
		std::cout << 0 << std::endl;
		return 0;
	}

	while (true) {
		x = n / k;
		n = n % k;
		if (!x) {
			std::cout << res << std::endl;
			break ;
		}
		res += (k / m) * x;
		n += (k % m) * x;
	}
}