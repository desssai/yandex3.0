#include <iostream>
#include <fstream>
#include <string>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	short			troom, tcond;
	std::string		mode;

	file >> troom >> tcond >> mode;
	if (mode == "freeze" && troom > tcond)
		troom = tcond;
	else if (mode == "heat" && troom < tcond)
		troom = tcond;
	else if (mode == "auto")
		troom = tcond;
	std::cout << troom << std::endl;
}