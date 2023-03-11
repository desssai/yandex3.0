#include <iostream>
#include <fstream>
#include <vector>

void	dfs_with_color(std::vector<std::vector<int> >& graph, std::vector<int>& visited, std::vector<int>& color, int i, int paint) {
	if (visited[i])
		return ;
	visited[i] = 1;
	color[i] = paint;
	for (int j = 0; j < graph[i].size(); ++j) {
		dfs_with_color(graph, visited, color, graph[i][j], 3 - paint);
	}
}

int main(void) {
	std::ifstream					file("input.txt", std::ifstream::in);
	int								n, m, v1, v2, paint = 1;
	std::vector<int>				visited;
	std::vector<int>				color;
	std::vector<std::vector<int> >	graph;

	if (!file.is_open())
		return 1;

	file >> n >> m;
	color.resize(n + 1, 0);
	visited.resize(n + 1, 0);
	graph.resize(n + 1, std::vector<int>());
	for (int i = 0; i < m; ++i) {
		file >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (int i = 1; i <= n; ++i) {
		if (!visited[i])
			dfs_with_color(graph, visited, color, i, paint);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			if (color[i] == color[graph[i][j]]) {
				n = 0;
				break ;
			}
		}
	}
	std::cout << (n ? "YES" : "NO") << std::endl;
	file.close();
	return 0;
}