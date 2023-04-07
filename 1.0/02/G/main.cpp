#include <iostream>

using std::swap;
using std::cout;
using std::endl;
using std::cin;

int main(void) {
	long long max1, max2, min1, min2, num;

	cin >> max1 >> max2;
	if (max1 < max2)
		swap(max1, max2);

	min1 = max2;
	min2 = max1;

	while (!cin.eof()) {
		cin >> num;
		if (cin.eof())
			break ;
		if (num > max1) {
			max2 = max1;
			max1 = num;
		}
		else if (num > max2)
			max2 = num;
		else if (num < min1) {
			min2 = min1;
			min1 = num;
		}
		else if (num < min2)
			min2 = num;
	}

	if (min1 * min2 > max1 * max2)
		cout << min1 << " " << min2 << endl;
	else
		cout << max2 << " " << max1 << endl;
}