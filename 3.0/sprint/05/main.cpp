#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

class position {

public:
	position() : x(0), y(0) { }
	position(const int& a, const int& b) : x(a), y(b) { }
	position(const position& other) : x(other.x), y(other.y) { }
	position& operator = (const position& other) {x = other.x; y = other.y; return *this;}
	~position() { }
	
	short 	x;
	short 	y;
};

int main(void) {
	std::ifstream										file("input.txt", std::ifstream::in);
	int													x_axis[] = {0, 0, 1, -1, 1, -1, -1, 1};
	int													y_axis[] = {1, -1, 0, 0, 1, -1, 1, -1};
	int													n, m, v1, v2, v3, v4, res, xbuf, ybuf;
	std::vector<std::vector<int> >						visited;
	std::queue<position>								queue;
	std::vector<std::vector<position> >					prev;
	std::string											line;

	file >> n >> m;
	visited.resize(n + 1, std::vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		file >> line;
		for (int j = 1; j <= m; ++j)
			visited[i][j] = line[j - 1] - 89;
	}

	file >> v1 >> v2 >> v3 >> v4;
	v2 = n - v2 + 1;
	v4 = n - v4 + 1;
	visited[v2][v1] = 0;
	visited[v4][v3] = -2;
	
	prev.resize(n + 1, std::vector<position>(m + 1, position(-1, -1)));
	queue.push(position(v2, v1));
	while (queue.size()) {
		for (int k = 0; k < 8; ++k) {
			if (queue.front().x + x_axis[k] > 0 && queue.front().x + x_axis[k] <= n
				&& queue.front().y + y_axis[k] > 0 && queue.front().y + y_axis[k] <= m
				&& visited[queue.front().x + x_axis[k]][queue.front().y + y_axis[k]] < -1) {
					visited[queue.front().x + x_axis[k]][queue.front().y + y_axis[k]] = visited[queue.front().x][queue.front().y] + 1;
					queue.push(position(queue.front().x + x_axis[k], queue.front().y + y_axis[k]));
					prev[queue.front().x + x_axis[k]][queue.front().y + y_axis[k]] = queue.front();
					if (visited[queue.front().x + x_axis[k]][queue.front().y + y_axis[k]] == -2) {
						while (queue.size())
							queue.pop();
					}
				}
		}
		if (queue.size())
			queue.pop();
	}

	res = 0;
	if (prev[v4][v2].x != -1 && prev[v4][v2].y != - 1) {
		while (v4 != v2 || v3 != v1) {
			res++;
			while (v4 - prev[v4][v3].x == prev[v4][v3].x - prev[prev[v4][v3].x][prev[v4][v3].y].x
				&& v3 - prev[v4][v3].y == prev[v4][v3].y - prev[prev[v4][v3].x][prev[v4][v3].y].y) {
				xbuf = v4;
				ybuf = v3;
				v4 = prev[xbuf][ybuf].x;
				v3 = prev[xbuf][ybuf].y;
			}
			xbuf = v4;
			ybuf = v3;
			v4 = prev[xbuf][ybuf].x;
			v3 = prev[xbuf][ybuf].y;
		}
	}
	else
		res = -1;
	std::cout << res << std::endl;
	file.close();
	return 0;
}