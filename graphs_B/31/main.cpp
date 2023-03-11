#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void	dfs(std::vector<std::vector<int> >& graph, std::vector<int>& visited, int i, int& res) {
	if (visited[i])
		return ;
	visited[i] = 1;
	res++;
	for (int j = 0; j < graph[i].size(); ++j)
		dfs(graph, visited, graph[i][j], res);
}

int main(void) {
	std::ifstream					file("input.txt", std::ifstream::in);
	int								x_axis[] = {1, -1, 0, 0};
	int								y_axis[] = {0, 0, -1, 1};
	int								n, p1, p2, res = 0;
	std::vector<int>				visited;
	std::vector<std::vector<int> >	graph;
	std::vector<std::string>		lines;

	if (!file.is_open())
		return 1;
	
	file >> n;
	lines.resize(n + 1, std::string(""));
	for (int i = 1; i <= n; ++i) 
		file >> lines[i];

	visited.resize((n + 1) * n, 0);
	graph.resize((n + 1) * n, std::vector<int>());
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (lines[i][j] == '.') {
				for (int k = 0; k < 4; ++k) {
					graph[i * n + j].push_back((i + y_axis[k]) * n + (j + x_axis[k]));
					graph[(i + y_axis[k]) * n + (j + x_axis[k])].push_back(i * n + j);
				}
			}
			else
				visited[i * n + j] = 1;
		}
	}
	file >> p1 >> p2;
	dfs(graph, visited, p1 * n + p2 - 1, res);
	std::cout << res << std::endl;
	file.close();
	return 0;
}