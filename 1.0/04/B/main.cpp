#include <unordered_map>
#include <iostream>
#include <string>

int main(void) {
	std::string								s1;
	std::unordered_map<std::string, int>	dict1;

	while (true) {
		std::cin >> s1;
		if (std::cin.eof())
			break ;
		std::cout << dict1[s1]++ << " ";
	}
}
