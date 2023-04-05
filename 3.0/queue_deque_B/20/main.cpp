#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define MIN_HEAP	std::priority_queue<std::pair<int, int>, \
					std::vector<std::pair<int, int> >, \
					std::greater<std::pair<int, int> > >

int main(void) {
	int					n = 0, k = 0, p = 0, flag = 0, res = 0;
	std::ifstream		file("input.txt", std::ifstream::in);
	MIN_HEAP			q;
	std::vector<int>	shelf;
	std::vector<int>	floor;

	if (!file.is_open())
		return 1;

	file >> n >> k >> p;
	shelf.resize(p, 0);
	for (int i = 0; i < p; ++i)
		file >> shelf[i];

	floor.resize(k, 0);
	for (int i = 0; i < k; ++i) {
		floor[i] = shelf[i];
		res++;
	}

	for (int i = k; i < p; ++i) {
		flag = 0;
		for (int j = 0; j < k; ++j) {
			for (int l = 0; l < k && i + l < p; ++l) {
				if (floor[j] == shelf[i + l]) {
					flag = 1;
					break ;
				}
			}
		}
		if (!flag) {
			for (int j = 0; j < k; ++j) {
				if (floor[j] != shelf[i]) {
					floor[j] = shelf[i];
					res++;
					break ;
				}
			}
		}
		for (int i = 0; i < k; ++i) {
			std::cout << floor[i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << res << std::endl;
	file.close();
	return 0;
}