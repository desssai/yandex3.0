/* 
 * 33 == '!'
 * 40 == '('
 * 41 == ')'
 * 44 == ','
 * 45 == '-'
 * 46 == '.'
 * 49 == '0' :: 57 == '9'
 * 58 == ':'
 * 59 == ';'
 * 63 == '?'
 * 65 == 'A' :: 90 == 'Z'
 * 97 == 'a' :: 122 == 'z'
 
 This primitive brute-force solution is, despite being &!*&^&^!, is much faster than working with maps. And more memory-efficient I think.
 
 */

#include <fstream>
#include <iostream>
#include <cstring>

void	print(short* array) {
	int	max = 0;
	for (int i = 0; i < 71; ++i) {
		if (max < array[i])
			max = array[i];
	}

	for (int i = 0; i < max; ++i) {
		for (int j = 0; j < 71; ++j) {
			if (array[j] && array[j] - max + i >= 0)
				std::cout << "#";
			else if (array[j])
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 71; ++i) {
		if (array[i]) {
			if (i == 0)
				std::cout << '!';
			else if (i == 1)
				std::cout << '(';
			else if (i == 2)
				std::cout << ')';
			else if (i == 3)
				std::cout << ',';
			else if (i == 4)
				std::cout << '-';
			else if (i == 5)
				std::cout << '.';
			else if (i >= 6 && i <= 15)
				std::cout << (char)(i - 6 + 48);
			else if (i == 16)
				std::cout << ':';
			else if (i == 17)
				std::cout << ';';
			else if (i == 18)
				std::cout << '?';
			else if (i >= 19 && i <= 44)
				std::cout << (char)(i - 19 + 65);
			else if (i >= 45 && i <= 70)
				std::cout << (char)(i - 45 + 97);
		}
	}
}

int	main(void) {
	std::ifstream	file;
	short			result[71];
	char			buffer[10000];

	memset(result, 0, 71 * 2);
	file.open("input.txt", std::ifstream::in);

	if (file) {
		file.read(buffer, 10000);

		int chars = file.gcount();
		for (int i = 0; i < chars; ++i) {
			if (buffer[i] == '!')
				result[0]++;
			else if (buffer[i] == '(')
				result[1]++;
			else if (buffer[i] == ')')
				result[2]++;
			else if (buffer[i] == ',')
				result[3]++;
			else if (buffer[i] == '-')
				result[4]++;
			else if (buffer[i] == '.')
				result[5]++;
			else if (buffer[i] >= '0' && buffer[i] <= '9')
				result[buffer[i] - 48 + 6]++;
			else if (buffer[i] == ':')
				result[16]++;
			else if (buffer[i] == ';')
				result[17]++;
			else if (buffer[i] == '?')
				result[18]++;
			else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
				result[buffer[i] - 65 + 19]++;
			else if (buffer[i] >= 'a' && buffer[i] <= 'z')
				result[buffer[i] - 97 + 45]++;
		}
		file.close();
	}
	print(result);
}