#include <iostream>
#include <vector>

int main(void) {
	short								n, m, k, x0, y0;
	short								abs[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	short								ord[8] = {1, 1, 1, 0, -1, -1, -1, 0};
	std::vector<std::vector<short> >	map;

	std::cin >> n >> m >> k;
	map.resize(n + 1, std::vector<short>(m + 1, 0));
	for (int i = 0; i < k; ++i) {
		std::cin >> x0 >> y0;
		map[x0][y0] = -1;
		for (int j = 0; j < 8; ++j)
			if (x0 + abs[j] >= 0 && x0 + abs[j] <= n
				&& y0 + ord[j] >= 0 && y0 + ord[j] <= m
				&& map[x0 + abs[j]][y0 + ord[j]] != -1)
				map[x0 + abs[j]][y0 + ord[j]]++;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (map[i][j] == -1)
				std::cout << "*";
			else
				std::cout << map[i][j];
			std::cout << (j == m ? '\n' : ' ');
		}
	}
}