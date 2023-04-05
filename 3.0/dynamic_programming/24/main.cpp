#include <iostream>
#include <fstream>
#include <climits>

typedef struct s_data {
	int	ai;
	int	bi;
	int	ci;
}	t_data;

int	getMin(int a, int b, int c) {
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	return c;
}

int main(void) {
	std::ifstream	file("input.txt", std::ifstream::in);
	int*			result = nullptr;
	t_data*			array = nullptr;
	int				n = 0;

	if (!file)
		return 1;

	file >> n;

	array = new t_data [n + 1];
	if (!array) {
		file.close();
		return 1;
	}

	for (int i = 1; i <= n; ++i)
		file >> array[i].ai >> array[i].bi >> array[i].ci;

	result = new int [n + 1];
	if (!result) {
		delete [] array;
		file.close();
		return 1;
	}
	
	result[0] = 0;
	for (int i = 1; i <= n; ++i) {
		array[0].ai = result[i - 1] + array[i].ai;
		array[0].bi = i < 2 ? INT_MAX : result[i - 2] + array[i - 1].bi;
		array[0].ci = i < 3 ? INT_MAX : result[i - 3] + array[i - 2].ci;
		result[i] = getMin(array[0].ai, array[0].bi, array[0].ci);
	}
	std::cout << result[n] << std::endl;
	delete [] result;
	delete [] array;
	file.close();
}