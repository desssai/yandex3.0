#include <iostream>
#include <fstream>
#include <queue>

int main(void) {
	std::ifstream	file;
	std::queue<int>	first;
	std::queue<int>	second;

	file.open("input3.txt", std::ifstream::in);
	if (file) {
		for (int i = 0, j = 0; i < 5; ++i) {
			file >> j;
			first.push(j);
		}
		for (int i = 0, j = 0; i < 5; ++i) {
			file >> j;
			second.push(j);
		}
		for (int i = 0, j = 0; i < 1000000; ++i) {
			if (!first.size()) {
				std::cout << "second " << i << std::endl;
				file.close();
				return 0;
			}
			else if (!second.size()) {
				std::cout << "first " << i << std::endl;
				file.close();
				return 0;
			}
			else
				j = first.front() - second.front();
			if (j == -9 || (j > 0 && j < 9)) {
				first.push(first.front());
				first.pop();
				first.push(second.front());
				second.pop();
			}
			else {
				second.push(first.front());
				first.pop();
				second.push(second.front());
				second.pop();
			}
		}
		std::cout << "botva" << std::endl;
		file.close();
	}
}