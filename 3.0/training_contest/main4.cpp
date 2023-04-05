#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(void) {
	std::ifstream		file("input.txt", std::ifstream::in);
	std::ofstream		outfile("output.txt", std::ofstream::out);
	unsigned int		i = 0;
	std::string			line;


	i = 0;
	std::getline(file, line);
	while (line.find("href", i) != std::string::npos) {
		i = line.find("href", i) + 7;
		outfile << "https://www.joom.com/";
		for (int j = 0; j < 36; ++j)
			outfile << line[i + j];
		outfile << std::endl;
	}
	return 0;
}