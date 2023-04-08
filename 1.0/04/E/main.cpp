#include <iostream>
#include <map>

int main(void) {
	long long			total_height, width, height, n;
	std::map<int, int>	blocks;

	std::cin >> n;
	total_height = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> width >> height;
		if (blocks[width] < height) {
			total_height += height - blocks[width];
			blocks[width] = height;
		}
	}
	std::cout << total_height << std::endl;
}
