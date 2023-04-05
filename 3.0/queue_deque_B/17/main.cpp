#include <iostream>
#include <fstream>
#include <deque>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	char			oprator;
	int				number;
	int				n = 0;
	std::deque<int>	deck;

	if (!file.is_open())
		return 1;

	file >> n;

	for (int i = 0; i < n; ++i) {
		file >> oprator;
		if (oprator != '-') {
			file >> number;
			if (oprator == '+')
				deck.push_back(number);
			else
				deck.insert(deck.begin() + ((deck.size() >> 1) + deck.size() % 2), number);
		}
		else {
			std::cout << deck.front() << std::endl;
			deck.pop_front();
		}
	}
	file.close();
	return 0;
}