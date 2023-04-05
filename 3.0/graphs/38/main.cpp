#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream													file("input.txt", std::ifstream::in);
	int																n, m, s, t, q, v1, v2, res;
	std::vector<std::vector<int> >									visited;
	std::vector<std::vector<std::vector<std::pair<int, int> > > >	graph;
	std::vector<std::vector<std::pair<int, int> > >					vrtx;

	if (!file.is_open())
		return 1;

	file >> n >> m >> s >> t >> q;

	visited.resize(n + 1, std::vector<int>(m + 1, -1));
	graph.resize(n + 1, std::vector<std::vector<std::pair<int, int> > >(m + 1, std::vector<std::pair<int, int> >()));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i - 1 > 0 && j - 2 > 0)
				graph[i][j].push_back(std::make_pair(i - 1, j - 2));
			if (i + 1 <= n && j - 2 > 0)
				graph[i][j].push_back(std::make_pair(i + 1, j - 2));
			if (i - 1 > 0 && j + 2 <= m)
				graph[i][j].push_back(std::make_pair(i - 1, j + 2));
			if (i + 1 <= n && j + 2 <= m)
				graph[i][j].push_back(std::make_pair(i + 1, j + 2));
			if (i - 2 > 0 && j - 1 > 0)
				graph[i][j].push_back(std::make_pair(i - 2, j - 1));
			if (i + 2 <= n && j - 1 > 0)
				graph[i][j].push_back(std::make_pair(i + 2, j - 1));
			if (i - 2 > 0 && j + 1 <= m)
				graph[i][j].push_back(std::make_pair(i - 2, j + 1));
			if (i + 2 <= n && j + 1 <= m)
				graph[i][j].push_back(std::make_pair(i + 2, j + 1));
		}
	}

	vrtx.resize(1, std::vector<std::pair<int, int> >());
	vrtx[0].push_back(std::make_pair(s, t));
	visited[s][t] = 0;
	for (int v = 0; v < vrtx.size(); ++v) {
		if (vrtx[v].size())
			vrtx.push_back(std::vector<std::pair<int, int> >());
		for (int i = 0; i < vrtx[v].size(); ++i) {
			for (int j = 0; j < graph[vrtx[v][i].first][vrtx[v][i].second].size(); ++j) {
				if (visited[graph[vrtx[v][i].first][vrtx[v][i].second][j].first][graph[vrtx[v][i].first][vrtx[v][i].second][j].second] == -1) {
					visited[graph[vrtx[v][i].first][vrtx[v][i].second][j].first][graph[vrtx[v][i].first][vrtx[v][i].second][j].second] = v + 1;
					vrtx[v + 1].push_back(std::make_pair(graph[vrtx[v][i].first][vrtx[v][i].second][j].first, graph[vrtx[v][i].first][vrtx[v][i].second][j].second));
				}
			}
		}
	}

	for (int b = 0; b < q; ++b) {
		file >> v1 >> v2;
		res += visited[v1][v2];
		if (visited[v1][v2] == -1) {
			std::cout << -1 << std::endl;
			file.close();
			return 0;
		}
	}

	std::cout << res << std::endl;
	file.close();
	return 0;
}