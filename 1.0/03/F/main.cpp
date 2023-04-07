#include <iostream>
#include <vector>
#include <string>

int main(void) {
	std::string							gen1, gen2;
	std::vector<std::vector<int> >		matrix1;
	int									n, res;

	std::getline(std::cin, gen1);
	n = gen1.size();
	matrix1.resize(26, std::vector<int>(26, 0));
	for (int i = 1; i < n; ++i)
		matrix1[gen1[i - 1] - 'A'][gen1[i] - 'A']++;

	std::getline(std::cin, gen2);
	res = 0;
	n = gen2.size();
	for (int i = 1; i < n; ++i) {
		res += matrix1[gen2[i - 1] - 'A'][gen2[i] - 'A'];
		matrix1[gen2[i - 1] - 'A'][gen2[i] - 'A'] = 0;
	}
	std::cout << res << std::endl;
}