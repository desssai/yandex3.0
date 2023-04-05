#include <iostream>
#include <fstream>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	long long		a, b, c;

	file >> a >> b >> c;
	file.close();
	
	if (a < b)
		std::swap(a, b);
	if (a < c)
		std::swap(a, c);
	std::cout << ((a && b && c && a < b + c) ? "YES" : "NO") << std::endl;
}