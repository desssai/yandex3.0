#include <iostream>
#include <fstream>
#include <string>
#include <stack>

int main(void) {
	std::string		str;
	std::ifstream	file;
	std::stack<int>	stack;
	int				size = 0;
	int				num = 0;

	file.open("input1.txt", std::ifstream::in);
	if (file) {
		std::getline(file, str);
		size = str.size();
		for (int i = 0; i < size; ++i) {
			if (str[i] != ' ') {
				if (str[i] == '+') {
					num = stack.top();
					stack.pop();
					stack.top() += num;
				}
				else if (str[i] == '-') {
					num = stack.top();
					stack.pop();
					stack.top() -= num;
				}
				else if (str[i] == '*') {
					num = stack.top();
					stack.pop();
					stack.top() *= num;
				}
				else {
					num = 0;
					for (int j = i; str[j] != ' '; ++j) {
						num *= 10;
						num += str[j] - 48;
						i = j;
					}
					stack.push(num);
				}
			}
		}
		while (stack.size() > 1) {
			num = stack.top();
			stack.pop();
			stack.top() += num;
		}
		std::cout << stack.top() << std::endl;
		file.close();
	}
}