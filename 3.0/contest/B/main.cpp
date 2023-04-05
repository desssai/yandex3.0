#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

typedef std::pair<int, int>	t_value;
typedef std::priority_queue<t_value, std::vector<t_value>, std::greater<t_value> >	t_min_heap;

int main(void) {
	std::ifstream						file("input.txt", std::ifstream::in);
	t_min_heap							array;
	std::vector<int>					result;
	int									n, x;
	long long							total;

	file >> n >> x >> total;
	for (int i = 0, j; i < n; ++i) {
		file >> j;
		array.push(std::make_pair(std::abs(j - x), i + 1));
	}

	result.reserve(n);
	while (array.size()) {
		total -= array.top().first;
		if (total < 0)
			break ;
		result.push_back(array.top().second);
		array.pop();
	}

	std::cout << result.size() << std::endl;
	if (result.size()) {
		for (int i = 0, j = result.size(); i < j; ++i)
			std::cout << result[i] << " ";
		std::cout << std::endl;
	}
	file.close();
}