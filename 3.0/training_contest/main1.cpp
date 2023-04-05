#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream			file("input.txt", std::ifstream::in);
	long long				n, delta = 0;
	std::vector<long long>	reservoirs;

	if (!file.is_open())
		return 1;

	file >> n;
	reservoirs.resize(n, 0);
	for (int i = 0; i < n; ++i)
		file >> reservoirs[i];
	file.close();
	
	for (int i = n - 2; i >= 0; --i) {
		if (reservoirs[i] + delta <= reservoirs[i + 1]) {
			delta += reservoirs[i + 1] - reservoirs[i] - delta;
			reservoirs[i] += delta;
		}
		else if (reservoirs[i] + delta > reservoirs[i + 1]) {
			delta = -1;			
			break ;
		}
	}
	std::cout << delta << std::endl;
	return 0;
}