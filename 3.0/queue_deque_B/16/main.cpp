#include <iostream>
#include <fstream>
#include <queue>

#define MIN_HEAP	std::priority_queue<std::pair<int, int>, \
					std::vector<std::pair<int, int> >, \
					std::greater<std::pair<int, int> > >

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	int				n = 0, k = 0, buf;
	MIN_HEAP		q;

	if (!file.is_open())
		return 1;

	file >> n >> k;
	for (int i = 0; i < k; ++i) {
		file >> buf;
		q.push(std::make_pair(buf, i));
	}

	for (int i = k; i < n; ++i) {
		std::cout << q.top().first << std::endl;
		while (q.size() && q.top().second <= i - k)
			q.pop();
		file >> buf;
		q.push(std::make_pair(buf, i));
	}
	std::cout << q.top().first << std::endl;
	file.close();
	return 0;
}