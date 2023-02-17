#include <iostream>
#include <fstream>
#include <string>

int main(void) {
	std::string		A, B, C, D;
	int				AD = 0;
	int				BD = 0;
	int				CD = 0;
	double			DD = 0;
	std::ifstream	file;

	file.open("input9.txt", std::ifstream::in);
	if (file) {
		file >> A >> B >> C;

		AD = ((A[0] - 48) * 10 + (A[1] - 48)) * 60 * 60 + ((A[3] - 48) * 10 + (A[4] - 48)) * 60 + ((A[6] - 48) * 10 + (A[7] - 48));
		BD = ((B[0] - 48) * 10 + (B[1] - 48)) * 60 * 60 + ((B[3] - 48) * 10 + (B[4] - 48)) * 60 + ((B[6] - 48) * 10 + (B[7] - 48));
		CD = ((C[0] - 48) * 10 + (C[1] - 48)) * 60 * 60 + ((C[3] - 48) * 10 + (C[4] - 48)) * 60 + ((C[6] - 48) * 10 + (C[7] - 48));

		if (CD < AD)
			CD += 86400;
		DD = BD + (CD - AD) / 2.;
		if (DD - static_cast<int>(DD) >= 0.5)
			DD = static_cast<int>(DD) + 1;
		else
			DD = static_cast<int>(DD);

		AD = (DD / 60 / 60);
		DD -= AD * 60 * 60;
		BD = (DD / 60);
		DD -= BD * 60;

		if (DD > 59) {
			DD -= 60;
			BD += 1;
		}
		if (BD > 59) {
			BD -= 60;
			AD += 1;
		}
		if (AD > 23) {
			AD -= 24;
		}

		D.push_back(AD / 10 + 48);
		D.push_back(AD % 10 + 48);
		D.push_back(':');
		D.push_back(BD / 10 + 48);
		D.push_back(BD % 10 + 48);
		D.push_back(':');
		D.push_back(DD / 10 + 48);
		D.push_back(static_cast<int>(DD) % 10 + 48);

		std::cout << D << std::endl;

		file.close();
	}
}