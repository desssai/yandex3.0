#include <iostream>
#include <vector>

int main(void) {
	long long											n, k, start, finish;
	std::vector<std::vector<std::vector<long long> > >	vertexes;
	std::vector<long long>								visited;
	std::vector<std::vector<long long> >				cities;

	std::cin >> n;
	visited.resize(n + 1, -1);
	cities.resize(n + 1, std::vector<long long>(2, 0));
	for (long long i = 1; i <= n; ++i)
		std::cin >> cities[i][0] >> cities[i][1];
	std::cin >> k >> start >> finish;
	visited[start] = 0;
	vertexes.push_back(std::vector<std::vector<long long> >(1, {cities[start][0], cities[start][1]}));
	for (long long distance = 0; distance < vertexes.size(); ++distance) {
		if (vertexes[distance].size())
			vertexes.push_back(std::vector<std::vector<long long> >());
		for (long long j = 0; j < vertexes[distance].size(); ++j) {
			for (long long l = 1; l <= n; ++l) {
				if (visited[l] == -1 && (std::abs(vertexes[distance][j][0] - cities[l][0]) + std::abs(vertexes[distance][j][1] - cities[l][1])) <= k) {
					visited[l] = distance + 1;
					vertexes[distance + 1].push_back(cities[l]);
				}
			}
		}
	}
	std::cout << visited[finish] << std::endl;
}