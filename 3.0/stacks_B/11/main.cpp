#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

int main(void) {
	std::ifstream		file("input.txt", std::ifstream::in);
	std::stack<double>	warehouse;
	std::vector<double>	sourceA;
	std::vector<double>	sourceB;
	int					n, k, res;

	if (!file.is_open())
		return 1;
	
	file >> n;
	for (int i = 0; i < n; ++i) {

		file >> k;
		sourceB.clear();
		sourceA.clear();
		sourceA.resize(k);

		for (int j = k - 1; j >= 0; --j)
			file >> sourceA[j];
		
		while (sourceA.size()) {
			while (warehouse.size() && warehouse.top() < sourceA.back()) {
				sourceB.push_back(warehouse.top());
				warehouse.pop();
			}
			if (!warehouse.size() || warehouse.top() > sourceA.back()) {
				warehouse.push(sourceA.back());
				sourceA.pop_back();
			}
			else {
				break ;
			}
		}
		while (warehouse.size()) {
			sourceB.push_back(warehouse.top());
			warehouse.pop();
		}

		res = 1;
		for (int k = sourceB.size() - 1; k > 0; --k) {
			if (sourceB[k] < sourceB[k - 1]) {
				res = 0;
				break ;
			}
		}
		std::cout << res << std::endl;
	}
	
	file.close();
	return 0;
}