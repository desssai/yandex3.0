#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class position {

public:
	position() : x(0), y(0) { };
	position(int a, int b) : x(a), y(b) { };
	
	position&	operator = (const position& other) { x = other.x; y = other.y; return *this; }

	int x;
	int	y;

};

int main(void) {
	int													x_move[] = {1, 1, -1, -1, 2, 2, -2, -2};
	int													y_move[] = {2, -2, 2, -2, 1, -1, 1, -1};
	std::ifstream										file("input.txt", std::ifstream::in);
	std::string											pos1, pos2;
	std::vector<std::vector<position> >					distance;
	std::vector<std::vector<int> >						visited1;
	std::vector<std::vector<int> >						visited2;
	std::vector<std::vector<std::vector<position> > >	graph;
	position											p[3];
	int													res;

	if (!file.is_open())
		return 1;

	graph.resize(9, std::vector<std::vector<position> >(9));
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			for (int k = 0; k < 8; ++k) {
				if (i + x_move[k] > 0 && i + x_move[k] < 9
					&& j + y_move[k] > 0 && j + y_move[k] < 9)
					graph[i][j].push_back(position(i + x_move[k], j + y_move[k]));
			}
		}
	}

	file >> pos1 >> pos2;
	p[1] = position(pos1[0] - 'a' + 1, pos1[1] - '0');
	p[2] = position(pos2[0] - 'a' + 1, pos2[1] - '0');

	
	visited1.resize(9, std::vector<int>(9, -1));
	visited2.resize(9, std::vector<int>(9, -1));
	for (int v = 1; v < 3; ++v) {
		(v == 2 ? visited2[p[v].x][p[v].y] : visited1[p[v].x][p[v].y]) = 0;
		distance.clear();
		distance.resize(1);
		distance[0].push_back(p[v]);
		for (int i = 0; i < distance.size(); ++i) {
			if (distance[i].size())
				distance.push_back(std::vector<position>());
			for (int j = 0; j < distance[i].size(); ++j) {
				for (int k = 0; k < graph[distance[i][j].x][distance[i][j].y].size(); ++k) {
					p[0] = graph[distance[i][j].x][distance[i][j].y][k];

					if (v == 2) {
						if (visited2[p[0].x][p[0].y] == -1) {
							visited2[p[0].x][p[0].y] = i + 1;
							distance[i + 1].push_back(p[0]);
						}
					}
					else {
						if (visited1[p[0].x][p[0].y] == -1) {
							visited1[p[0].x][p[0].y] = i + 1;
							distance[i + 1].push_back(p[0]);
						}
					}
				}
			}
		}
	}

	res = 1000000;
	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			if (visited1[i][j] == visited2[i][j] && res > visited1[i][j])
				res = visited1[i][j];
		}
	}
	
	std::cout << (res == 1000000 ? -1 : res) << std::endl;
	file.close();
	return 0;
}