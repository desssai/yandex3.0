#include <iostream>
#include <string>
#include <map>

int main(void) {
	int							count;
	std::string					word;
	std::map<std::string, int>	dict;

	while (true) {
		std::cin >> word;
		if (std::cin.eof())
			break ;
		dict[word]++;
	}

	count = 0;
	word = "";
	for (auto it = dict.begin(), ite = dict.end(); it != ite; ++it) {
		if ((*it).second == count && (!word.size() || std::lexicographical_compare((*it).first.begin(), (*it).first.end(), word.begin(), word.end())))
			word = (*it).first;
		else if ((*it).second > count) {
			word = (*it).first;
			count = (*it).second;
		}
	}
	std::cout << word << std::endl;
}
