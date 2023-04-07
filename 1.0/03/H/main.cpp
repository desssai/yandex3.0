#include <iostream>
#include <set>

int main(void) {
	std::set<int>	pigs;
	int				n, a, b;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b;
		pigs.insert(a);
	}
	std::cout << pigs.size() << std::endl;
}