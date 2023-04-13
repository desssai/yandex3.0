#include <iostream>
#include <string>
#include <stack>

bool	checkSequence(std::string& sequence, int& length) {
	std::stack<char>	chars;

	for (int i = 0; i < length; ++i) {
		if (sequence[i] == '(')
			chars.push('(');
		else if (sequence[i] == ')' && chars.size() && chars.top() == '(')
			chars.pop();
		else
			return false;
	}
	if (chars.empty())
		return true;
	return false;
}

void	recursiveSequenceModification(std::string& sequence, int index, int& length) {
	if (index == length && checkSequence(sequence, length))
		std::cout << sequence << std::endl;
	else if (index < length) {
		sequence[index] = '(';
		recursiveSequenceModification(sequence, index + 1, length);
		sequence[index] = ')';
		recursiveSequenceModification(sequence, index + 1, length);
	}
}

int main(void) {
	std::string	sequence;
	int			n;

	std::cin >> n;
	n *= 2;
	sequence.resize(n);
	sequence[0] = '(';
	recursiveSequenceModification(sequence, 1, n);
}