#include <iostream>
#include <string>
#include <queue>
#include <map>

int main(void) {
	int													n, m, common = 0;
	std::map<std::string, int>							languages;
	std::string											language;
	std::priority_queue<std::pair<int, std::string> >	q;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> m;
		for (int j = 0; j < m; ++j) {
			std::cin >> language;
			languages[language]++;
		}
	}
	for (auto it = languages.begin(), ite = languages.end(); it != ite; ++it) {
		q.push(std::make_pair((*it).second, (*it).first));
		if ((*it).second == n)
			common++;
	}
	std::cout << common << std::endl;
	for (int i = 0; i < common; ++i) {
		std::cout << q.top().second << std::endl;
		q.push(std::make_pair(1, q.top().second));
		q.pop();
	}
	std::cout << languages.size() << std::endl;
	while (q.size()) {
		std::cout << q.top().second << std::endl;
		q.pop();
	}
}