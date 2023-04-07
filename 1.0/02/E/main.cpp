#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream		infile("input.txt", std::ifstream::in);
	int					n, max_distance, v_distance, max_index, tournament_place;
	std::vector<int>	array;

	infile >> n;
	array.reserve(n);
	for (int i = 0; i < n; ++i) {
		infile >> max_distance;
		array.push_back(max_distance);
	}
	infile.close();

	max_index = n;
	max_distance = 0;
	for (int i = 0; i < n; ++i) {
		if (array[i] > max_distance) {
			max_distance = array[i];
			max_index = i;
		}
	}

	v_distance = 0;
	for (int i = max_index + 1; i < n - 1; ++i) {
		if (array[i] % 10 == 5 && array[i + 1] < array[i] && array[i] > v_distance)
			v_distance = array[i];
	}

	max_index = 0;
	tournament_place = 0;
	if (v_distance) {
		for (int i = 0; i < n; ++i) {
			if (array[i] > v_distance)
				tournament_place++;
			else if (array[i] == v_distance && !max_index++)
				tournament_place++;
		}
	}
	std::cout << tournament_place << std::endl;
}