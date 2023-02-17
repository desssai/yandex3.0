#include <fstream>
#include <iostream>

int main(void) {
	std::ifstream	file;
	int				n = 0;
	int				k = 0;
	int				m = 0;
	int				r = 0;

	file.open("input.txt", std::ifstream::in);
	if (file) {
		file >> n >> k >> m >> r;
		m--;
		r--;

		int i = m * 2 + r;
		int j1 = i + k;
		int j2 = i - k;

		if (j1 < n && j2 >= 0 && j1 / 2 - m <= m - j2 / 2)
			std::cout << (j1 / 2 + 1) << " " << (j1 % 2 + 1) << std::endl;
		else if (j2 >= 0)
			std::cout << (j2 / 2 + 1) << " " << (j2 % 2 + 1) << std::endl;
		else if (j1 < n)
			std::cout << (j1 / 2 + 1) << " " << (j1 % 2 + 1) << std::endl;
		else
			std::cout << -1 << std::endl;
	}
}