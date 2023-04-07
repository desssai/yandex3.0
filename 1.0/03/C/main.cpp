#include <set>
#include <iostream>

int main(void) {
	std::set<int>	BothCubes;
	std::set<int>	AnyasCubes;
	std::set<int>	BoriasCubes;
	int				n, m, color;

	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> color;
		AnyasCubes.insert(color);
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> color;
		if (AnyasCubes.find(color) == AnyasCubes.end())
			BoriasCubes.insert(color);
		else {
			BothCubes.insert(color);
			AnyasCubes.erase(color);
		}
	}

	std::cout << BothCubes.size() << std::endl;
	for (auto it = BothCubes.begin(), ite = BothCubes.end(); it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << AnyasCubes.size() << std::endl;
	for (auto it = AnyasCubes.begin(), ite = AnyasCubes.end(); it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << BoriasCubes.size() << std::endl;
	for (auto it = BoriasCubes.begin(), ite = BoriasCubes.end(); it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}