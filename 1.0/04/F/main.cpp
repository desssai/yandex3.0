#include <iostream>
#include <string>
#include <map>

int main(void) {
	std::string													name, item;
	std::map<std::string, std::map<std::string, long long> >	data;
	long long													n;

	while (true) {
		std::cin >> name >> item >> n;
		if (std::cin.eof())
			break ;
		data[name][item] += n;
	}

	for (auto it = data.begin(), ite = data.end(); it != ite; ++it) {
		std::cout << (*it).first << ":" << std::endl;
		for (auto inner_it = (*it).second.begin(), inner_ite = (*it).second.end(); inner_it != inner_ite; ++inner_it) {
			std::cout << (*inner_it).first << " " << (*inner_it).second << std::endl;
		}
	}
}
