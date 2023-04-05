#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int main(void) {
	std::ifstream					file("input.txt", std::ifstream::in);
	std::vector<int>				ci;
	std::vector<int>				ri;
	std::unordered_map<int, int>	hash;
	int								n, k, res;

	file >> n;
	ci.resize(n, 0);
	ri.resize(n, 0);
	for (int i = 0; i < n; ++i)
		file >> ci[i];
	for (int i = 0; i < n; ++i)
		file >> ri[i];
	for (int i = 0; i < n; ++i)
		hash[ci[i]] = ri[i];

	file >> k;
	ri.resize(k, 0);
	for (int i = 0; i < k; ++i)
		file >> ri[i];
	
	for (int i = 1; i < k; ++i) {
		if (hash[ri[i]] != hash[ri[i - 1]])
			res++;
	}
	std::cout << res << std::endl;
}