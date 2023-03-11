#include <unordered_set>
#include <iostream>
#include <fstream>
#include <vector>

int		stop_index = 0;

typedef std::vector<std::vector<int> >	t_graph;
typedef std::vector<int>				t_visited;

void	dfs(t_graph& graph, t_visited& visited, int i, int prev, std::vector<int>& array) {
	visited[i] = 1;
	for (int j = 0; j < graph[i].size(); ++j) {
		if (!visited[graph[i][j]])
			dfs(graph, visited, graph[i][j], i, array);
		if (visited[graph[i][j]] == 1 && graph[i][j] != prev) {
			if (!stop_index)
				stop_index = graph[i][j];
			if (stop_index != -1)
				array.push_back(i);
			if (stop_index == i)
				stop_index = -1;
			return ;
		}
	}
	visited[i] = 2;
}

int main(void) {
	std::ifstream			file("input.txt", std::ifstream::in);
	t_visited				visited;
	std::vector<int>		array;
	t_graph					graph;
	int						n, v;

	if (!file.is_open())
		return 1;

	file >> n;
	graph.resize(n + 1);
	visited.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			file >> v;
			if (v)
				graph[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!visited[i])
			dfs(graph, visited, i, -1, array);
		if (visited[i] == 1)
			break ;
	}

	if (array.size()) {
		std::cout << "YES" << std::endl;
		std::cout << array.size() << std::endl;
		for (int i = 0; i < array.size(); ++i)
			std::cout << array[i] << " ";
		std::cout << std::endl;
		file.close();
		return 0;
	}
	std::cout << "NO" << std::endl;
	file.close();
	return 0;
}