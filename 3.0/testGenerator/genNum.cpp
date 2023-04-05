#include <time.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv) {
	char	delimeter = 0;
	int		n = 0;
	int		k = 0;

	if (argc == 4) {
		n = std::atoi(argv[1]);
		k = std::atoi(argv[2]);
		delimeter = argv[3][0];

		std::ofstream	file;

		file.open("input.txt");
		if (file) {
			srand(time(NULL));
			for (int i = 0; i < n; ++i) {
				file << (rand() % k) << delimeter;
			}
		std::cout << "Generated " << n <<" numbers. |n| <= " << k << ". Delimeter is: '" << delimeter << "'." << std::endl;
		file.close();
		}
	}
	else {
		std::cout << "USAGE: ./a.out [amount of numbers] [limit for numbers] [delimeter]" << std::endl;
	}
}