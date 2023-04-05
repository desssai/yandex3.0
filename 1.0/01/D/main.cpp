#include <iostream>
#include <fstream>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	long long		a, b, c;

	file >> a >> b >> c;
	file.close();

	if (c < 0) {
		std::cout << "NO SOLUTION" << std::endl;
		return 0;
	}
	if (!a) {
		if (c * c == b)
			std::cout << "MANY SOLUTIONS" << std::endl;
		else
			std::cout << "NO SOLUTION" << std::endl;
		return 0;
	}
	else if ((c * c - b) % a)
		std::cout << "NO SOLUTION" << std::endl;
	else
		std::cout << (c * c - b) / a << std::endl;
}