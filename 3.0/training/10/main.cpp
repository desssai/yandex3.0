#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void) {
	std::string				word;
	std::ifstream			file;
	long long				size = 0;
	std::vector<long long>	array(26, 0);

	file.open("input9.txt", std::ifstream::in);
	if (file) {
		file >> word;
		size = word.size();
		
		for (long long i = 0; i < size; ++i)
			array[word[i] - 97] += (size - i) * (i + 1);
		
		for (int i = 0; i < 26; ++i)
			if (array[i])
				std::cout << (char)(i + 97) << ": " << array[i] << std::endl;
		file.close();
	}
}