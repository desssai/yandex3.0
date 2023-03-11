#include <iostream>
#include <fstream>
#include <vector>

typedef std::vector<std::vector<int> >	t_graph;

void	dfs(t_graph& graff, std::vector<int>& visited, int i, std::vector<int>& tsort) {
	if (visited[i])
		return ;
	visited[i] = 1;
	for (int j = 0; j < graff[i].size(); ++j) {
		if (!visited[graff[i][j]])
			dfs(graff, visited, graff[i][j], tsort);
		if (visited[graff[i][j]] == 1)
			return ;
	}
	visited[i] = 2;
	tsort.push_back(i);
}

int main(void) {
	std::ifstream		file("input.txt", std::ifstream::in);
	int					n, m, v1, v2;
	std::vector<int>	visited;
	std::vector<int>	tsort;
	t_graph				graff;

	if (!file.is_open())
		return 1;

	file >> n >> m;
	graff.resize(n + 1);
	visited.resize(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		file >> v1 >> v2;
		graff[v1].push_back(v2);
	}

	for (int i = 1; i <= n; ++i)
		dfs(graff, visited, i, tsort);
	
	for (int i = 1; i <= n; ++i) {	
		if (visited[i] == 1) {
			std::cout << -1 << std::endl;
			file.close();
			return 0;
		}
	}
	for (int i = tsort.size() - 1; i >= 0; --i)
		std::cout << tsort[i] << " ";
	std::cout << std::endl;
	file.close();
	return 0;
}