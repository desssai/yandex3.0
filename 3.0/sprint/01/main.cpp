#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

int main(void) {
	std::ifstream								file("input.txt", std::ifstream::in);
	std::string									command, name;
	int											n, delta;
	std::map<std::string, long>					total;
	std::vector<std::pair<std::string, long> >	train;

	if (!file.is_open())
		return 1;

	file >> n;
	for (int i = 0; i < n; ++i) {
		file >> command;
		if (command == "get") {
			file >> name;
			std::cout << total[name] << std::endl;
		}
		else if (command == "add" ){
			file >> delta >> name;
			train.push_back(std::make_pair(name, delta));
			total[name] += delta;
		}
		else {
			file >> delta;
			while (delta) {
				if (delta >= train.back().second) {
					total[train.back().first] -= train.back().second;
					delta -= train.back().second;
					train.pop_back();
				}
				else {
					total[train.back().first] -= delta;
					train.back().second -= delta;
					delta = 0;
				}
			}
		}
	}
	file.close();
	return 0;
}