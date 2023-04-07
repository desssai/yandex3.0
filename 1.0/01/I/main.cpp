#include <iostream>
#include <fstream>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	short			a, b, c, d, e;
	
	file >> a >> b >> c >> d >> e;
	file.close();

	if (d > e)
		std::swap(d, e);
	
	if (a > b && a <= e && b <= d || a <= b && b <= e && a <= d) {
		std::cout << "YES" << std::endl;
		return 0;
	}
	if (b > c && b <= e && c <= d || b <= c && c <= e && b <= d) {
		std::cout << "YES" << std::endl;
		return 0;
	}
	if (a > c && a <= e && c <= d || a <= c && c <= e && a <= d) {
		std::cout << "YES" << std::endl;
		return 0;
	}
	std::cout << "NO" << std::endl;
}