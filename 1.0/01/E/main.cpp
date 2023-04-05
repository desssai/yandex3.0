#include <iostream>
#include <fstream>

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);

	file.close();	
}