#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class number {
public:
	number() : a(0), b(0), c(0), d(0) { }
	number(int _a, int _b, int _c, int _d) : a(_a), b(_b), c(_c), d(_d) { }
	number(const number& other) : a(other.a), b(other.b), c(other.c), d(other.d) { }

	number&	operator = (const number& other);

	number	plus_one_first(void) const;
	number	minus_one_last(void) const;
	number	plus_one_last(void) const;
	number	minus_one_first(void) const;
	number	swipe_left(void) const;
	number	swipe_right(void) const;

	int a;
	int	b;
	int	c;
	int	d;
};

number&	number::operator = (const number& other) {
	a = other.a;
	b = other.b;
	c = other.c;
	d = other.d;
	return *this;
}

number number::plus_one_first(void) const {
	number	copy(*this);

	if (a < 9)
		copy.a++;
	return copy;
}

number number::minus_one_last(void) const {
	number	copy(*this);

	if (d > 1)
		copy.d--;
	return copy;
}

number number::plus_one_last(void) const {
	number	copy(*this);

	if (d < 9)
		copy.d++;
	return copy;
}

number number::minus_one_first(void) const {
	number	copy(*this);

	if (a > 1)
		copy.a--;
	return copy;
}

number number::swipe_left(void) const {
	number	copy(*this);

	copy.a = b;
	copy.b = c;
	copy.c = d;
	copy.d = a;
	return copy;
}

number number::swipe_right(void) const {
	number	copy(*this);

	copy.d = c;
	copy.c = b;
	copy.b = a;
	copy.a = d;
	return copy;
}

bool	operator == (const number& lhs, const number& rhs) {
	return (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d);
}

bool	operator != (const number& lhs, const number& rhs) {
	return !(lhs == rhs);
}

int main(void) {
	std::ifstream													file("input.txt", std::ifstream::in);
	std::vector<std::vector<number> >								vertexes;
	std::vector<std::vector<std::vector<std::vector<int> > > >		visited;
	number															num[6];
	std::string														n1, n2;
	std::vector<number>												result;
	std::vector<std::vector<std::vector<std::vector<number> > > >	prev;

	if (!file.is_open())
		return 1;

	file >> n1 >> n2;
	num[4] = number(n1[0] - '0', n1[1] - '0', n1[2] - '0', n1[3] - '0');
	num[5] = number(n2[0] - '0', n2[1] - '0', n2[2] - '0', n2[3] - '0');

	visited.resize(10, std::vector<std::vector<std::vector<int> > >());
	for (int i = 1; i <= 9; ++i) {
		visited[i].resize(10, std::vector<std::vector<int> >());
		for (int j = 1; j <= 9; ++j) {
			visited[i][j].resize(10, std::vector<int>());
			for (int k = 1; k <= 9; ++k) {
				visited[i][j][k].resize(10, -1);
			}
		}
	}
	prev.resize(10, std::vector<std::vector<std::vector<number> > >());
	for (int i = 1; i <= 9; ++i) {
		prev[i].resize(10, std::vector<std::vector<number> >());
		for (int j = 1; j <= 9; ++j) {
			prev[i][j].resize(10, std::vector<number>());
			for (int k = 1; k <= 9; ++k) {
				prev[i][j][k].resize(10, number(-1, -1, -1, -1));
			}
		}
	}
		
	vertexes.clear();
	visited[num[4].a][num[4].b][num[4].c][num[4].d] = 0;
	vertexes.push_back(std::vector<number>());
	vertexes[0].push_back(num[4]);
	for (int i = 0; i < vertexes.size(); ++i) {
		if (vertexes[i].size())
			vertexes.push_back(std::vector<number>());
		for (int j = 0; j < vertexes[i].size(); ++j) {
			num[0] = vertexes[i][j].plus_one_first();
			num[1] = vertexes[i][j].minus_one_last();
			num[2] = vertexes[i][j].swipe_left();
			num[3] = vertexes[i][j].swipe_right();
			for (int k = 0; k < 4; ++k) {
				if (visited[num[k].a][num[k].b][num[k].c][num[k].d] == -1) {
					prev[num[k].a][num[k].b][num[k].c][num[k].d] = vertexes[i][j];
					visited[num[k].a][num[k].b][num[k].c][num[k].d] = i + 1;
					vertexes[i + 1].push_back(num[k]);
				}
				if (num[k] == num[5]) {
					i = vertexes.size() + 1;
					break ;
				}
			}
			if (i > vertexes.size())
				break ;
		}
	}

	while (prev[num[5].a][num[5].b][num[5].c][num[5].d] != number(-1, -1, -1, -1)) {
		result.push_back(num[5]);
		num[5] = prev[num[5].a][num[5].b][num[5].c][num[5].d];
	}
	result.push_back(num[5]);

	for (int i = result.size() - 1; i >= 0 ; --i)
		std::cout << result[i].a << result[i].b << result[i].c << result[i].d << std::endl;

	file.close();
	return 0;
}