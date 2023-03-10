#include <iostream>
#include <fstream>
#include <vector>

void	dfs(std::vector<std::vector<int> >& graph, std::vector<bool>& visited, int i, int& res) {
	if (visited[i])
		return ;
	visited[i] = true;
	res++;
	for (int j = 0; j < graph[i].size(); ++j)
		dfs(graph, visited, graph[i][j], res);
}

int main(void) {
	std::ifstream					file("input.txt", std::ifstream::in);
	int								n = 0, m = 0, v1, v2, res = 0;
	std::vector<std::vector<int> >	graph;
	std::vector<bool>				visited;

	if (!file.is_open())
		return 1;
	
	file >> n >> m;
	graph.reserve(n + 1);
	visited.resize(n + 1, false);
	for (int i = 1; i <= n; ++i)
		graph.push_back(std::vector<int>());
	for (int i = 0; i < m; ++i) {
		file >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	dfs(graph, visited, 1, res);
	std::cout << res << std::endl;
	for (int i = 1; i <= n; ++i) {
		if (visited[i])
			std::cout << i << " ";
	}
	std::cout << std::endl;
	file.close();
	return 0;
}