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
 */
/* #include <iostream>
#include <fstream>
#include <vector>

using std::vector;
using std::ifstream;
using std::cout;
using std::endl;

void	beutify(unsigned int k, unsigned int s, char* str) {
	char					c;
	unsigned int			res = 0;
	vector<unsigned int>	current(26, 0);
	vector<unsigned int>	total(26, 0);
	vector<unsigned int>	delay(26, k);

	if (!k) {
		cout << 0 << endl;
		return ;
	}
	if (k >= s) {
		cout << s << endl;
		return ;
	}
	for (unsigned int i = 0; i < s; ++i) {
		c = str[i] - 'a';
		current[c]++;
		for (unsigned int j = 0; j < 26; ++j) {
			if (current[j]) {
				if (j == c && current[j] > 1 && !delay[j]) {
					total[j] = current[j] - 1 - k + delay[j];
					current[j] = 1;
					delay[j] = k;
				}
				else if (j != c && !delay[j]) {
					if (current[j] < total[j] + current[j])
						current[j] = total[j] + current[j];
					if (res < current[j])
						res = current[j];
					current[j] = 0;
					total[j] = 0;
					delay[j] = k;
				}
				else if (j != c) {
					delay[j]--;
					current[j]++;
				}
			}
		}
	}
	for (unsigned int j = 0; j < 26; ++j) {
		if (current[j] < total[j] + current[j])
			current[j] = total[j] + current[j];
		if (res < current[j] + delay[j])
			res = current[j] + delay[j];
	}
	cout << (res > s ? s : res) << endl;
}

int	main(void) {
	ifstream	file;
	int			k = 0;
	char		buffer[200000];

	file.open("input.txt", ifstream::in);
	if (file) {
		file.read(buffer, 200000);
		int i = 0;
		while (buffer[i] != '\n')
			++i;
		for (int j = 0; j < i; ++j) {
			k *= 10;
			k += (buffer[j] - '0');
		}
		beutify(k, file.gcount() - i, buffer + (i + 1));
		file.close();
	}
} */
#include <fstream>
#include <iostream>

void	print(char* array) {
	int	max = 0;
	for (int i = 0; i < 71; ++i) {
		if (max < array[i])
			max = array[i];
	}
	
	std::cout << max << std::endl;
	std::cout << max << std::endl;
	std::cout << max << std::endl;
	
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
			else if (i >= 6 && i <= 16)
				std::cout << (char)(i + 42);
			else if (i == 17)
				std::cout << ':';
			else if (i == 18)
				std::cout << ';';
			else if (i == 19)
				std::cout << '?';
			else if (i >= 20 && i <= 45)
				std::cout << (char)(i + 45);
			else if (i >= 46 && i <= 70)
				std::cout << (char)(i + 51);
		}
			
	}
}

int	main(void) {
	std::ifstream	file;
	char			result[71];
	char			buffer[10000];

	memset(result, 0, 71);
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
				result[buffer[i] - 42]++;
			else if (buffer[i] == ':')
				result[17]++;
			else if (buffer[i] == ';')
				result[18]++;
			else if (buffer[i] == '?')
				result[19]++;
			else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
				result[buffer[i] - 45]++;
			else if (buffer[i] >= 'a' && buffer[i] <= 'z')
				result[buffer[i] - 51]++;
			}
		file.close();
	}
	print(result);
}