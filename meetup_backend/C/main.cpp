#include <iostream>
#include <vector>
#include <string>

int main(void) {
	std::vector<int>	sequence, prefixSumZeroes, prefixSumOnes, arrayOfLeftIndexes;
	std::string			sequenceInString;
	int					n, found, l, r;

	std::cin >> n >> sequenceInString;
	sequence.resize(n + 1, 0);
	prefixSumOnes.resize(n + 1, 0);
	prefixSumZeroes.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		sequence[i] = sequenceInString[i - 1] - '0';
		prefixSumOnes[i] = prefixSumOnes[i - 1] + (sequence[i] ? 1 : 0);
		prefixSumZeroes[i] = prefixSumZeroes[i - 1] + (sequence[i] ? 0 : 1);
	}

	arrayOfLeftIndexes.resize(n + 1, -1);

	/* Two pointers approach for just the zero-elemets of sequence: */
	l = 1; r = 2;
	while (r <= n) {
		while (!sequence[r] && l < r && prefixSumZeroes[r] - prefixSumZeroes[l - 1] <= prefixSumOnes[r] - prefixSumOnes[l - 1])
			l++;
		if (!sequence[r] && l != r)
			arrayOfLeftIndexes[r] = l;
		r++;
	}
	/* Two pointers approach for just the one-elemets of sequence: */
	l = 1; r = 2;
	while (r <= n) {
		while (sequence[r] && l < r && prefixSumZeroes[r] - prefixSumZeroes[l - 1] >= prefixSumOnes[r] - prefixSumOnes[l - 1])
			l++;
		if (sequence[r] && l != r)
			arrayOfLeftIndexes[r] = l;
		r++;
	}

	for (int i = 1; i <= n; ++i)
		std::cout << arrayOfLeftIndexes[i] << " ";
	std::cout << std::endl;
}