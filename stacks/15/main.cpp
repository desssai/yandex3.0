#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

int main(void) {
	std::ifstream						file;
	std::vector<std::pair<int, int> >	city;
	std::stack<std::pair<int, int>* >	stack;
	int									n = 0;

	file.open("input.txt", std::ifstream::in);
	if (file) {
		file >> n;

		for (int i = 0, j = 0; i < n; ++i) {
			file >> j;
			city.push_back(std::pair<int, int>(j, -1));
		}
		for (int i = 0; i < n; ++i) {
			while (stack.size() && stack.top()->first > city[i].first) {
				stack.top()->second = i;
				stack.pop();
			}
			stack.push(&(city[i]));
		}
		for (int i = 0; i < n - 1; ++i)
			std::cout << city[i].second << " ";
		std::cout << city[n - 1].second << std::endl;
		file.close();
	}
}