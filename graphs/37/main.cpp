#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int main(void) {
	std::ifstream					file("input.txt", std::ifstream::in);
	int								n, v1, v2;
	std::vector<std::vector<int> >	vertexes;
	std::vector<int>				visited;
	std::vector<int>				route;
	std::vector<std::vector<int> >	graph;

	if (!file.is_open())
		return 1;

	file >> n;

	vertexes.resize(1);
	graph.resize(n + 1);
	visited.resize(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			file >> v1;
			if (v1)
				graph[i].push_back(j);
		}
	}

	file >> v1 >> v2;

	vertexes.push_back(std::vector<int>());
	vertexes[0].push_back(v1);
	visited[v1] = 0;

	for (int i = 0; i < vertexes.size(); ++i) {
		if (vertexes[i].size())
			vertexes.push_back(std::vector<int>());
		for (int j = 0; j < vertexes[i].size(); ++j) {
			for (int k = 0; k < graph[vertexes[i][j]].size(); ++k) {
				if (visited[graph[vertexes[i][j]][k]] == -1) {
					visited[graph[vertexes[i][j]][k]] = i + 1;
					vertexes[i + 1].push_back(graph[vertexes[i][j]][k]);
				}
			}
		}
	}

	std::cout << visited[v2] << std::endl;
	if (visited[v2] > 0) {
		while (v2 != v1) {
			route.push_back(v2);
			for (int i = 0; i < graph[v2].size(); ++i) {
				if (visited[v2] == visited[graph[v2][i]] + 1) {
					v2 = graph[v2][i];
					break ;
				}
			}
		}
		route.push_back(v2);
	}
	for (int i = route.size() - 1; i >= 0; --i)
		std::cout << route[i] << " ";
	std::cout << std::endl;
	file.close();
	return 0;
}