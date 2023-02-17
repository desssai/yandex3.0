#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void	beutify(int k, std::string s) {
	std::vector<int>	map(26, 0);
	int					maximum = 0;
	int					longest = 0;
	int					size = s.size();

	for (int end = 0, start = 0; end < size; ++end) {
		map[s[end] - 'a']++;
		maximum = std::max(maximum, map[s[end] - 'a']);
		if (end + 1 - start - maximum > k) {
			map[s[start] - 'a']--;
			start++;
		}
		longest = end + 1 - start;
	}
	std::cout << longest;
}

int	main(void) {
	std::string		s;
	std::ifstream	file;
	int				k = 0;

	file.open("input.txt", std::ifstream::in);
	if (file) {
		file >> k;
		file >> s;
		beutify(k, s);
		file.close();
	}
}