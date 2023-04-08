#include <iostream>
#include <climits>
#include <string>
#include <map>
#include <set>

std::string	returnWordInLower(std::string word) {
	int i = -1, n = word.size();

	while (++i < n)
		word[i] = std::tolower(word[i]);
	return word;
}

bool	checkValidity(std::string& line, long long start, long long& end) {
	std::string	symbolsWithoutNumbers = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_"};
	
	while (start < end)
		if (symbolsWithoutNumbers.find(line[start++]) != std::string::npos)
			return true;
	return false;
}

int main(void) {
	std::string												symbolsWithNumbers = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_"};
	
	std::string												justNumbers = {"0123456789"};
	std::string												line, identificator, max_identificator;
	long long												n, count, start, end, maxOrderOfAppearance;
	std::map<std::string, std::pair<long long, long long> >	identificators;
	bool													flag1, flag2;
	std::set<std::string>									key_symbols;

	std::cin >> n;
	std::cin >> line;
	flag1 = line[0] == 'y' ? true : false;
	std::cin >> line;
	flag2 = line[0] == 'y' ? true : false;

	for (int i = 0; i < n; ++i) {
		std::cin >> line;
		if (!flag1)
			line = returnWordInLower(line);
		key_symbols.insert(line);
	}

	count = 0;
	maxOrderOfAppearance = INT_MAX;
	while (true) {
		std::getline(std::cin, line);
		if (std::cin.eof())
			break ;
		line.push_back(' ');
		start = end = 0;
		while (line[end]) {
			if ((start = line.find_first_of(symbolsWithNumbers, end)) == std::string::npos)
				break ;
			end = line.find_first_not_of(symbolsWithNumbers, start);
			if (flag2 && checkValidity(line, start, end) || !flag2 && justNumbers.find(line[start]) == std::string::npos) {
				identificator = line.substr(start, end - start);
				if (!flag1)
					identificator = returnWordInLower(identificator);
				if (key_symbols.find(identificator) == key_symbols.end()) {
					identificators[identificator].second++;
					if (identificators[identificator].second == 1)
						identificators[identificator].first = identificators.size();
					if (count < identificators[identificator].second) {
						count = identificators[identificator].second;
						maxOrderOfAppearance = identificators[identificator].first;
						max_identificator = identificator;
					}
					else if (count == identificators[identificator].second && maxOrderOfAppearance > identificators[identificator].first) {
						count = identificators[identificator].second;
						maxOrderOfAppearance = identificators[identificator].first;
						max_identificator = identificator;
					}
				}
			}
		}
	}
	if (count)
		std::cout << max_identificator << std::endl;
}