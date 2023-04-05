#include <iostream>
#include <fstream>
#include <string>
#include <stack>

int main(void) {
	std::ifstream		file;
	std::string			line;
	std::stack<char>	stack;
	int					size = 0;

	file.open("input3.txt", std::ifstream::in);
	if (file) {
		file >> line;
		
		size = line.size();
		for (int i = 0; i < size; ++i) {
			if (line[i] == '(' || line[i] == '{' || line[i] == '[')
				stack.push(line[i]);
			else if (!stack.size() || (line[i] == ')' && stack.top() != '(') || (line[i] == ']' && stack.top() != '[') || (line[i] == '}' && stack.top() != '{')) {
				std::cout << "no" << std::endl;
				file.close();
				return 0;
			}
			else
				stack.pop();
		}
		if (!stack.size())
			std::cout << "yes" << std::endl;
		else
			std::cout << "no" << std::endl;
		file.close();
	}
}