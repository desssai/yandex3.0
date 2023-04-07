#include <iostream>
#include <fstream>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	bool			constant = false, ascending = false, descending = false, flag = false;
	int				num, prev;

	while (true) {
		file >> num;
		if (num == -2000000000) {
			if (constant && !ascending && !descending)
				std::cout << "CONSTANT" << std::endl;
			else if (!constant && ascending && !descending)
				std::cout << "ASCENDING" << std::endl;
			else if (constant && ascending && !descending)
				std::cout << "WEAKLY ASCENDING" << std::endl;
			else if (!constant && !ascending && descending)
				std::cout << "DESCENDING" << std::endl;
			else if (constant && !ascending && descending)
				std::cout << "WEAKLY DESCENDING" << std::endl;
			else
				std::cout << "RANDOM" << std::endl;
			file.close();
			return 0;
		}
		if (!flag)
			flag = true;
		else {
			if (num == prev)
				constant = true;
			else if (num > prev)
				ascending = true;
			else if (num < prev)
				descending = true;
		}
		prev = num;
	}
}