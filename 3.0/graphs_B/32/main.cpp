#include <iostream>
#include <fstream>
#include <vector>

typedef std::vector<std::vector<int> >	t_graph;

void	dfs(t_graph& graph, std::vector<int>& visited, int i) {
	visited[i] = 1;
	for (int j = 0; j < graph[i].size(); ++j) {
		if (!visited[graph[i][j]])
			dfs(graph, visited, graph[i][j]);
	}
}

int main(void) {
	std::ifstream		file("input.txt", std::ifstream::in);
	int					n, m, v1, v2, index;
	std::vector<int>	visited;
	t_graph				graph;

	if (!file.is_open())
		return 1;

	file >> n >> m;
	visited.resize(n + 1, 0);
	graph.resize(n + 1, std::vector<int>());
	for (int i = 0; i < m; ++i) {
		file >> v1 >> v2;
		graph[v2].push_back(v1);
	}

	dfs(graph, visited, 1);
	for (int i = 1; i <= n; ++i)
		if (visited[i])
			std::cout << i << " ";
	std::cout << std::endl;
	file.close();
	return 0;
}