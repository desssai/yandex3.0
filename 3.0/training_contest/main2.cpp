#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string>	getSeats(std::vector<std::vector<int> >& plane, int count, std::string& seat, std::string& preference) {
	std::vector<std::string>	res;
	int	lb, rb, empty;

	if (seat[0] == 'l' && preference[0] == 'w') {
		lb = 0;
		rb = lb + count - 1;
	} else if (seat[0] == 'l') {
		rb = 2;
		lb = rb - count + 1;
	} else if (seat[0] == 'r' && preference[0] == 'w') {
		rb = 5;
		lb = rb - count + 1;
	} else {
		lb = 3;
		rb = lb + count - 1;
	}
	for (int i = 0; i < plane.size(); ++i) {
		empty = 0;
		for (int j = lb; j <= rb; ++j) {
			if (plane[i][j] == 0) {
				empty++;
			}
		}
		if (empty == count) {
			for (int j = lb; j <= rb; ++j) {
				plane[i][j] = 2;
				res.push_back(" ");
				res.back() += std::to_string(i + 1);
				res.back().push_back(j + 65);
			}
			return res;
		}
	}
	return res;
}

void	printPlane(std::vector<std::vector<int> >& plane, std::vector<std::string>& passenger_seats, std::ofstream& outfile) {
	if (!passenger_seats.size())
		outfile << "Cannot fulfill passengers requirements" << std::endl;
	else {
		outfile << "Passengers can take seats:";
		for (int i = 0; i < passenger_seats.size(); ++i)
			outfile << passenger_seats[i];
		outfile << std::endl;

		for (int i = 0; i < plane.size(); ++i) {
			for (int j = 0; j < 6; ++j) {
				if (plane[i][j] == 0)
					outfile << '.';
				else if (plane[i][j] == 1)
					outfile << '#';
				else if (plane[i][j] == 2) {
					outfile << 'X';
					plane[i][j] = 1;
				}
				if (j == 2)
					outfile << '_';
				else if (j == 5)
					outfile << '\n';
			}
		}
	}
}

int main(void) {
	std::ifstream					infile("input.txt", std::ifstream::in);
	std::ofstream					outfile("output.txt", std::ofstream::out);
	std::string						seat, preference;
	std::vector<std::string>		passenger_seats;
	int								n, m, k;
	std::vector<std::vector<int> >	plane;


	if (!infile.is_open() || !outfile.is_open())
		return 1;

	infile >> n;
	plane.resize(n, std::vector(6, 0));
	for (int i = 0; i < n; ++i) {
		infile >> seat;
		for (int j = 0; j < 7; ++j) {
			if (j < 3 && seat[j] == '#')
				plane[i][j] = 1;
			else if (j > 3 && seat[j] == '#')
				plane[i][j - 1] = 1;
		}
	}

	infile >> m;
	for (int i = 0; i < m; ++i) {
		infile >> k >> seat >> preference;
		passenger_seats = getSeats(plane, k, seat, preference);
		printPlane(plane, passenger_seats, outfile);
	}
	infile.close();
	outfile.close();
	return 0;
}