#include <iostream>
#include <fstream>
#include <string>
#include <stack>

int main(void) {
	std::ifstream			file("input.txt", std::ifstream::in);
	std::stack<char>		symbols;
	std::string				letters;
	std::stack<std::string>	xmls;
	short					n = 0;
	std::string				line;

	if (!file.is_open())
		return 1;
	
	file >> line;
	
	n = line.size();
	for (short i = 0; i < n; ++i) {

	}

	std::cout << line << std::endl;
	file.close();
	return 0;
}