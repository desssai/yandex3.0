#include <unordered_map>
#include <iostream>
#include <string>

int main(void) {
	std::string										s1, s2;
	std::unordered_map<std::string, std::string>	dict1, dict2;
	int												n;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> s1 >> s2;
		dict1[s1] = s2;
		dict2[s2] = s1;
	}
	
	std::cin >> s1;
	std::cout << (dict1[s1].size() ? dict1[s1] : dict2[s1]) << std::endl;
}
