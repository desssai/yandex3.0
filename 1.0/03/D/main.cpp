#include <unordered_set>
#include <iostream>

int main(void) {
	std::unordered_set<std::string>	words;
	std::string						word;
	int								n = 0;

	while (true) {
		std::cin >> word;
		if (std::cin.eof())
			break ;
		if (words.find(word) == words.end()) {
			words.insert(word);
			n++;
		}
	}
	std::cout << n << std::endl;
}