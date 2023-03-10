#include <iostream>
#include <fstream>
#include <queue>

int main(void) {
	std::ifstream													file("input.txt", std::ifstream::in);
	double															res = 0.;
	int																n = 0, buf = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int> >	q;

	if (!file.is_open())
		return 1;
	
	file >> n;

	for (int i = 0; i < n; ++i) {
		file >> buf;
		q.push(buf);
	}

	while (q.size() != 1) {
		buf = q.top(); q.pop();
		buf += q.top(); q.pop();
		res += buf * 0.05;
		q.push(buf);
	}

	std::cout.precision(2);
	std::cout << std::fixed << res << std::endl;
	file.close();
	return 0;
}