#include <iostream>
#include <vector>
#include <string>

void	fillTheGlass(std::vector<std::string>& glass, short& start, short end, char& symbol, short& glassWidth) {
	while (start > end) {
		for (int i = 0; i < glassWidth; ++i) {
			if (glass[start][i] == ' ')
				glass[start][i] = symbol;
		}
		start--;
	}
}

int main(void) {
	short						n, m, k, count, CurrentRowIndex;
	char						symbol;
	std::vector<std::string>	glass;
	std::string					name;

	std::cin >> n >> m;
	std::getline(std::cin, name);
	glass.resize(n, "");
	for (short i = 0; i < n; ++i)
		std::getline(std::cin, glass[i]);
	
	std::cin >> k;
	CurrentRowIndex = n - 2;
	for (short i = 0; i < k; ++i) {
		std::cin >> name >> count >> symbol;
		fillTheGlass(glass, CurrentRowIndex, CurrentRowIndex - count, symbol, m);
	}
	
	for (short i = 0; i < n; ++i) {
		for (short j = 0; j < m; ++j)
			std::cout << glass[i][j];
		std::cout << std::endl;
	}
}