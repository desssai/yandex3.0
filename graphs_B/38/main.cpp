#include <iostream>
#include <fstream>
#include <vector>

class position {

public:
	position() : x(0), y(0) { }
	position(const int& a, const int& b) : x(a), y(b) { }
	position(const position& other) : x(other.x), y(other.y) { }
	position& operator = (const position& other) {x = other.x; y = other.y; return *this;}
	~position() { }
	
	int x;
	int y;
};

int main(void) {
	std::ifstream										file("input.txt", std::ifstream::in);
	std::vector<std::vector<position> >					vertexes;
	std::vector<std::vector<int> >						visited;
	std::vector<std::vector<std::vector<position> > >	graph;
	int													n, m;
	
	file >> n >> m;
	visited.resize(n + 1, std::vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			file >> visited[i][j];
			visited[i][j] -= 3;
		}
	}

	graph.resize(n + 1, std::vector<std::vector<position> >(m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (visited[i][j] != -2) {
				for (int k = j - 1; k >= 1; --k) {
					if (visited[i][k] == -2) {
						graph[i][j].push_back(position(i, k + 1));
						break ;
					}
					else if (k == 1 || visited[i][k] == -1)
						graph[i][j].push_back(position(i, k));
				}
				for (int k = j + 1; k <= m; ++k) {
					if (visited[i][k] == -2) {
						graph[i][j].push_back(position(i, k - 1));
						break ;
					}
					else if (k == m || visited[i][k] == -1)
						graph[i][j].push_back(position(i, k));
				}
				for (int k = i - 1; k >= 1; --k) {
					if (visited[k][j] == -2) {
						graph[i][j].push_back(position(k + 1, j));
						break ;
					}
					else if (k == 1 || visited[k][j] == -1)
						graph[i][j].push_back(position(k, j));
				}
				for (int k = i + 1; k <= n; ++k) {
					if (visited[k][j] == -2) {
						graph[i][j].push_back(position(k - 1, j));
						break ;
					}
					else if (k == n || visited[k][j] == -1)
						graph[i][j].push_back(position(k, j));
				}
			}
		}
	}

	vertexes.push_back(std::vector<position>());
	vertexes[0].push_back(position(1, 1));
	visited[1][1] = 0;
	for (int i = 0; i < vertexes.size(); ++i) {
		if (vertexes[i].size())
			vertexes.push_back(std::vector<position>());
		for (int j = 0; j < vertexes[i].size(); ++j) {
			for (int k = 0; k < graph[vertexes[i][j].x][vertexes[i][j].y].size(); ++k) {
				if (visited[graph[vertexes[i][j].x][vertexes[i][j].y][k].x][graph[vertexes[i][j].x][vertexes[i][j].y][k].y] == -1) {
					std::cout << i + 1 << std::endl;
					file.close();
					return 0;
				}
				if (visited[graph[vertexes[i][j].x][vertexes[i][j].y][k].x][graph[vertexes[i][j].x][vertexes[i][j].y][k].y] == -3) {
					visited[graph[vertexes[i][j].x][vertexes[i][j].y][k].x][graph[vertexes[i][j].x][vertexes[i][j].y][k].y] = i + 1;
					vertexes[i + 1].push_back(graph[vertexes[i][j].x][vertexes[i][j].y][k]);
				}
			}
		}
	}
	file.close();
	return 0;
}