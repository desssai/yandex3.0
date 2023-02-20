#include <iostream>
#include <fstream>
#include <stack>

int main(void) {
	std::stack<short>	stop;
	std::stack<short>	rail;
	std::ifstream		file;
	short				n = 0;

	file.open("input5.txt", std::ifstream::in);
	if (file) {

		file >> n;
		for (short i = 0, j = 0; i < n; ++i) {
			file >> j;
			while (stop.size() && stop.top() < j) {
				rail.push(stop.top());
				stop.pop();
			}
			if (!stop.size() || stop.top() > j)
				stop.push(j);
			else {
				std::cout << "NO" << std::endl;
				file.close();
				return 0;
			}
		}
		while (stop.size()) {
			rail.push(stop.top());
			stop.pop();
		}
		while (rail.size() > 1) {
			n = rail.top();
			rail.pop();
			if (n < rail.top()) {
				std::cout << "NO" << std::endl;
				file.close();
				return 0;
			}
		}
		std::cout << "YES" << std::endl;
		file.close();
	}
}