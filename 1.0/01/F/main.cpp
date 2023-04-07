#include <iostream>
#include <fstream>

void	getSmallestTableSize(int xbig, int ybig, int xsmall, int ysmall) {
	if (ysmall <= xbig)
		ybig += xsmall;
	else if (ysmall <= ybig)
		xbig += xsmall;
	else {
		ybig = ysmall;
		xbig += xsmall;
	}
	std::cout << xbig << " " << ybig << std::endl;
}

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	int				x1, y1, x2, y2, resx, resy, situation;

	file >> x1 >> y1 >> x2 >> y2;
	file.close();

	if (x1 > y1)
		std::swap(x1, y1);
	if (x2 > y2)
		std::swap(x2, y2);

	if (x1 * y1 > x2 * y2)
		getSmallestTableSize(x1, y1, x2, y2);
	else
		getSmallestTableSize(x2, y2, x1, y1);
}