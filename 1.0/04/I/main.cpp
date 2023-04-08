#include <iostream>
#include <string>
#include <set>

bool	CheckForOnlyOneHyphon(std::string& word) {
	int	i = -1, n = word.size(), res = 0;

	while (++i < n) {
		if (word[i] < 'a')
			res++;
	}
	return res == 1 ? true : false;
}

std::string	returnWordInLower(std::string word) {
	int i = -1, n = word.size();

	while (++i < n)
		word[i] = std::tolower(word[i]);
	return word;
}

int main(void) {
	std::set<std::string>	dictionaryWithoutHyphons;
	std::set<std::string>	dictionary;
	long long				n, result;
	std::string				word;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> word;
		dictionary.insert(word);
		dictionaryWithoutHyphons.insert(returnWordInLower(word));
	}

	result = 0;
	while (true) {
		std::cin >> word;
		if (std::cin.eof())
			break ;
		if (dictionary.find(word) == dictionary.end()) {
			if (!CheckForOnlyOneHyphon(word) || dictionaryWithoutHyphons.find(returnWordInLower(word)) != dictionaryWithoutHyphons.end())
				result++;
		}
	}
	std::cout << result << std::endl;
}