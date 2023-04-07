#include <iostream>
#include <set>

int main(void) {
	std::set<int>	set;
	int				num;

	while (true) {
		std::cin >> num;
		if (std::cin.eof())
			break ;
		set.insert(num);
	}
	std::cout << set.size() << std::endl;
}