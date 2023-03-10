#include <iostream>
#include <fstream>
#include <vector>

void	dfs(std::vector<std::vector<int> >& graph, std::vector<int>& visited, int i, int marker) {
	if (visited[i])
		return ;
	visited[i] = marker;
	for (int j = 0; j < graph[i].size(); ++j)
		dfs(graph, visited, graph[i][j], marker);
}

int main(void) {
	std::ifstream					file("input.txt", std::ifstream::in);
	int								n = 0, m = 0, v1, v2, index = 1;
	std::vector<int>				visited;
	std::vector<std::vector<int> >	graph;
	std::vector<std::vector<int> >	res;
	std::vector<int>				sum;

	if (!file.is_open())
		return 1;
	
	file >> n >> m;
	sum.resize(1, 0);
	graph.reserve(n + 1);
	visited.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		graph.push_back(std::vector<int>());
	for (int i = 0; i < m; ++i) {
		file >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (int i = 1; i <= n; ++i) {
		if (!visited[i])
			dfs(graph, visited, i, index++);
	}

	sum.resize(index, 0);
	res.resize(index, std::vector<int>());
	for (int i = 1; i <= n; ++i) {
		sum[visited[i]]++;
		res[visited[i]].push_back(i);
	}

	std::cout << index - 1 << std::endl;
	for (int i = 1; i < index; ++i) {
		std::cout << sum[i] << std::endl;
		for (int j = 0; j < res[i].size(); ++j)
			std::cout << res[i][j] << " ";
		std::cout << std::endl;
	}

	file.close();
	return 0;
}