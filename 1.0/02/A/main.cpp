#include <iostream>
#include <fstream>
#include <string>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	std::string		num;
	int				number, prev, flag = 0;

	while (true) {
		file >> num;
		if (file.eof())
			break ;
		(!flag ? prev : number) = std::stoi(num);
		if (flag && number <= prev) {
			std::cout << "NO" << std::endl;
			file.close();
			return 0;
		}
		else if (flag)
			prev = number;
		else
			flag++;
	}
	std::cout << "YES" << std::endl;
	file.close();
}