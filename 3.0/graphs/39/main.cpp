#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class coordinates {
public:
	coordinates(int _x, int _y, int _z) : x(_x), y(_y), z(_z) { }
	int x;
	int y;
	int z;
};

typedef std::vector<std::vector<std::vector<coordinates> > >	t_matrix;

int main(void) {
	std::ifstream									file("input.txt", std::ifstream::in);
	int												n, v1, v2, v3;
	std::vector<t_matrix>							graph;
	std::vector<std::vector<coordinates> >			vrtx;
	std::string										line;
	std::vector<std::vector<std::vector<int> > >	map;
	int												x[] = {-1, 1, 0, 0, 0, 0};
	int												y[] = {0, 0, -1, 1, 0, 0};
	int												z[] = {0, 0, 0, 0, -1, 1};

	if (!file.is_open())
		return 1;

	file >> n;
	graph.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		graph[i].resize(n + 1);
		for (int j = 1; j <= n; ++j)
			graph[i][j].resize(n + 1);
	}

	map.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		map[i].resize(n + 1);
		for (int j = 1; j <= n; ++j)
			map[i][j].resize(n + 1);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			file >> line;
			for (int k = 1; k <= n; ++k) {
				if (line[k - 1] == 'S') {
					v1 = i; v2 = j; v3 = k;
					map[i][j][k] = 0;
				}
				else if (line[k - 1] == '#')
					map[i][j][k] = -2;
				else if (line[k - 1] == '.')
					map[i][j][k] = -1;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				for (int q = 0; q < 6; ++q) {
					if (i + x[q] > 0 && i + x[q] <= n 
						&& j + y[q] > 0 && j + y[q] <= n
						&& k + z[q] > 0 && k + z[q] <= n)
						graph[i][j][k].push_back(coordinates(i + x[q], j + y[q], k + z[q]));
				}
			}
		}
	}

	vrtx.resize(1);
	vrtx[0].push_back(coordinates(v1, v2, v3));
	for (int i = 0; i < vrtx.size(); ++i) {
		if (vrtx[i].size())
			vrtx.push_back(std::vector<coordinates>());
		for (int j = 0; j < vrtx[i].size(); ++j) {
			for (int k = 0; k < graph[vrtx[i][j].x][vrtx[i][j].y][vrtx[i][j].z].size(); ++k) {

				v1 = graph[vrtx[i][j].x][vrtx[i][j].y][vrtx[i][j].z][k].x;
				v2 = graph[vrtx[i][j].x][vrtx[i][j].y][vrtx[i][j].z][k].y;
				v3 = graph[vrtx[i][j].x][vrtx[i][j].y][vrtx[i][j].z][k].z;
				if (map[v1][v2][v3] == -1) {
					if (v1 == 1) {
						std::cout << i + 1 << std::endl;
						file.close();
						return 0;
					}
					map[v1][v2][v3] = i + 1;
					vrtx[i + 1].push_back(graph[vrtx[i][j].x][vrtx[i][j].y][vrtx[i][j].z][k]);
				}
			}
		}
	}
	file.close();
	return 0;
}