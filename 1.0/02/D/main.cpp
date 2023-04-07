#include <iostream>
#include <fstream>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	int				first, second, third, result = 0, count = 0;
	
	while (true) {
		if (!count) {
			file >> first;
			if (file.eof())
				break ;
			count = 1;
		}
		else if (count == 1) {
			file >> second;
			if (file.eof())
				break ;
			count = 2;
		}
		else {
			file >> third;
			if (file.eof())
				break ;
			if (second > first && second > third)
				result++;
			first = second;
			second = third;
		}
	}
	file.close();
	std::cout << result << std::endl;
}