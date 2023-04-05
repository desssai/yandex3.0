#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int main(void) {
	typedef std::pair<int, int>	pair;
	
	std::ifstream														file("input.txt", std::ifstream::in);
	int																	n = 0, k = 0, arrival = 0;
	std::priority_queue<pair, std::vector<pair>, std::greater<pair> >	terminal;
	std::vector<int>													result;
	std::priority_queue<int, std::vector<int>, std::greater<int> >		queue;

	if (!file.is_open())
		return 1;

	file >> k >> n;
	for (int i = 0; i < k; ++i)
		queue.push(i + 1);

	for (int i = 0; i < n; ++i) {
		file >> arrival;

		while (terminal.size() && terminal.top().first < arrival) {
			queue.push(terminal.top().second);
			terminal.pop();
		}

		if (terminal.size() >= k) {
			std::cout << 0 << " " << i + 1 << std::endl;
			file.close();
			return 0;
		}

		file >> arrival;
		terminal.push(std::pair<int, int>(arrival, queue.top()));
		result.push_back(queue.top());
		queue.pop();
	}

	for (int i = 0; i < result.size(); ++i)
		std::cout << result[i] << std::endl;

	file.close();
	return 0;
}