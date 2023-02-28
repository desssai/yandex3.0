#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream			file;
	std::vector<long long>*	vect;
	short					n = 0;

	file.open("input1.txt", std::ifstream::in);
	if (file) {
		file >> n;
		vect = new std::vector<long long>(n, 0);
		if (vect->size() < 3) {
			std::cout << (1 << vect->size()) << std::endl;			
			delete vect;
			file.close();
			return 0;
		}
		(*vect)[2] = 1;
		for (short i = 3; i < n; ++i)
			(*vect)[i] = (*vect)[i - 1] + (*vect)[i - 2] + (*vect)[i - 3];
		for (short i = 3; i < n; ++i)
			(*vect)[i] += (*vect)[i - 1] * 2;
		std::cout << ((static_cast<long long>(1) << n) - (*vect)[n - 1]) << std::endl;
		delete vect;
		file.close();
	}
}