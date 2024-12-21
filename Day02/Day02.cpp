// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const int Levels = 5;
const int ReportSize = 6;

enum class ReportState {
	Decreasing,
	Increasing,
	Neither
};

static bool isSafe(int report[]) {
	ReportState state = (report[0] > report[1])? ReportState::Decreasing : (report[0] == report[1]) ? ReportState::Neither :ReportState::Increasing;
	if (state == ReportState::Neither) {
		std::cout << "Neither" << std::endl;
		return false;
	}
	else if (state == ReportState::Decreasing) {
		std::cout << "Decreasing" << std::endl;
	}
	else if (state == ReportState::Increasing) {
		std::cout << "Increasing" << std::endl;
	}

	for (int i = 0; i < Levels - 1; i++) {
		int diff = report[i] - report[i + 1];
		if (diff > 0 && diff <= 3) {
			if (state != ReportState::Decreasing) {
				std::cout << "Not Decreasing" << " at index " << i << " value " << report[i] << " " << report[i + 1] << std::endl;
				return false;
			}
		}
		else if (diff >= -3 && diff < 0) {
			if (state != ReportState::Increasing) {
				std::cout << "Not Increasing" << " at index " << i << " value " << report[i] << " " << report[i + 1] << std::endl;
				return false;
			}
		}
		else {
			std::cout << "Not within 3 " << " at index " << i << " value " << report[i] << " " << report[i + 1] << " diff = " << diff << std::endl;
			return false;
		}
	}

	
	return true;
}

int main()
{
    int reports[ReportSize][Levels] = {
		{ 7, 6, 4, 2, 1 },
		{ 1, 2, 7, 8, 9 },
		{ 9, 7, 6, 2, 1 },
		{ 1, 3, 2, 4, 5 },
		{ 8, 6, 4, 4, 1 },
		{ 1, 3, 6, 7, 9 }
	};
	int numOfSafe = 0;
	int numOfUnsafe = 0;
	for (int i = 0; i < ReportSize; i++) {
		if (isSafe(reports[i])) {
			numOfSafe++;
		}
		else {
			numOfUnsafe++;
		}
	}
	std::cout << "Safe: " << numOfSafe << std::endl;
	std::cout << "Unsafe: " << numOfUnsafe << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
