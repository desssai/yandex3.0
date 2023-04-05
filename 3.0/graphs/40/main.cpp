#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream									file("input.txt", std::ifstream::in);
	int												n, m, p, already_in, in, out;
	std::vector<int>								visited;
	std::vector<std::vector<int> >					graph;
	std::vector<std::vector<int> >					metro;
	std::vector<std::vector<int> >					vrtx;

	if (!file.is_open())
		return 1;

	file >> n >> m;
	metro.resize(m + 1);
	for (int i = 1; i <= m; ++i) {
		file >> p;
		metro[i].resize(p + 1);
		for (int j = 1; j <= p; ++j)
			file >> metro[i][j];
	}

	graph.resize(m + 1);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j < metro[i].size(); ++j) {

			for (int ii = 1; ii <= m; ++ii) {
				for (int jj = 1; jj < metro[ii].size(); ++jj) {

					if (ii != i && metro[i][j] == metro[ii][jj]) {
						already_in = 0;
						for (int k = 0; k < graph[i].size(); ++k) {
							if (graph[i][k] == ii)
								already_in = 1;
						}
						if (!already_in)
							graph[i].push_back(ii);
					} 
				}
			}
		}
	}

	file >> in >> out;

	vrtx.resize(1);
	visited.resize(m + 1, -1);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= metro[i].size(); ++j) {
			if (metro[i][j] == in) {
				visited[i] = 0;
				vrtx[0].push_back(i);
			}
		}
	}

	for (int i = 0; i < vrtx.size(); ++i) {
		if (vrtx[i].size())
			vrtx.push_back(std::vector<int>());
		for (int j = 0; j < vrtx[i].size(); ++j) {
			for (int k = 0; k < graph[vrtx[i][j]].size(); ++k) {
				if (visited[graph[vrtx[i][j]][k]] == -1) {
					visited[graph[vrtx[i][j]][k]] = i + 1;
					vrtx[i + 1].push_back(graph[vrtx[i][j]][k]);
				}
			}
		}
	}

	in = 10000;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= metro[i].size(); ++j) {
			if (metro[i][j] == out && in > visited[i])
				in = visited[i];
		}
	}

	std::cout << in << std::endl;
	file.close();
	return 0;
}