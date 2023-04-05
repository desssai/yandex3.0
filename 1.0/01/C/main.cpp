#include <iostream>
#include <fstream>
#include <string>

void	removeSymbols(std::string& number) {
	int	n = number.size(), offset = 0, i = 0;

	if (n && number[0] == '+') {
		number[0] = '8';
		offset = 1;
		i = 2;
	}
	while (i < n) {
		if (number[i] == '(' || number[i] == ')' || number[i] == '-')
			offset++;
		else if (offset) {
			number[i - offset] = number[i];
			number[i] = 0;
		}
		i++;
	}
	number.erase(number.begin() + n - offset, number.end());
	n = number.size();
	if (n != 11)
		number = std::string("8495") + number;	
}

int main(void) {
	std::ifstream				file("input.txt", std::ifstream::in);	
	std::string					number_new;
	std::string					number_old;

	file >> number_new;
	removeSymbols(number_new);
	for (int i = 0; i < 3; ++i) {
		file >> number_old;
		removeSymbols(number_old);
		std::cout << (number_new == number_old ? "YES" : "NO") << std::endl;
	}
	file.close();
}