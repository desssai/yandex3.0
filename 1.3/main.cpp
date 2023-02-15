#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>

void	findDesired(std::multimap<int, int>& mmap, std::set<int>& set) {
	std::multimap<int, int>::iterator mit = mmap.begin();
	std::multimap<int, int>::iterator mite = mmap.end();
	std::set<int>::const_iterator sit = set.begin();
	std::set<int>::const_iterator site = set.end();
	
	int res = 0;
	while (mit != mite) {
		while (sit != site && *sit < (*mit).first) {
			res++;
			sit++;
		}
		mit->second = res;
		mit++;
	}
}

int main(void) {
	std::ifstream							file;
	int										n = 0;
	std::set<int>							set;
	int										k = 0;
	std::multimap<int, int>					multimap;
	std::vector<int*>	array;


	file.open("input.txt", std::ifstream::in);
	if (file) {
		file >> n;
		for (int i = 0; i < n; ++i) {
			file >> k;
			set.insert(k);
		}
		
		file >> k;
		array.reserve(k);
		for (int i = 0; i < k; ++i) {
			file >> n;
			array[i] = &((*(multimap.insert(std::make_pair(n, 0)))).second);
		}

		findDesired(multimap, set);
		for (int i = 0; i < k; ++i) {
			std::cout << *(array[i]) << std::endl;
		}
		file.close();
	}
}