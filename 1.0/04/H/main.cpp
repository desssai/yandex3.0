#include <iostream>
#include <string>
#include <vector>

int main(void) {
	int					g, s, start, end, result;
	std::vector<int>	wordSymbols(52, 0);
	std::vector<int>	SequenceSymbols(52, 0);
	std::string			gstring, sstring;

	std::cin >> g >> s >> gstring >> sstring;
	for (int i = 0; i < g; ++i) {
		if (gstring[i] > 'Z')
			wordSymbols[gstring[i] - 'a' + 26]++;
		else
			wordSymbols[gstring[i] - 'A']++;
	}

	end = 0;
	start = 0;
	result = 0;
	while (end < g) {
		if (sstring[end] > 'Z')
			SequenceSymbols[sstring[end] - 'a' + 26]++;
		else
			SequenceSymbols[sstring[end] - 'A']++;
		end++;
	}
	end--;
	
	while (end < s) {
		if (wordSymbols == SequenceSymbols)
			result++;

		if (sstring[start] > 'Z')
			SequenceSymbols[sstring[start] - 'a' + 26]--;
		else
			SequenceSymbols[sstring[start] - 'A']--;
		start++;

		end++;
		if (sstring[end] > 'Z')
			SequenceSymbols[sstring[end] - 'a' + 26]++;
		else
			SequenceSymbols[sstring[end] - 'A']++;
	}
	std::cout << result << std::endl;
}