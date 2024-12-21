// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>

const int Levels = 5;
const int ReportSize = 6;

enum class ReportState {
	Decreasing,
	Increasing,
	Neither
};

// Function to read a space-separated file into a vector of columns and rows
std::vector<std::vector<int>> readData(const std::string& filename) {
	std::vector<std::vector<int>> data;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Could not open the file!" << std::endl;
		return data;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		int value;

		while (ss >> value) {
			row.push_back(value);
		}

		data.push_back(row);
	}

	file.close();
	return data;
}

// Function to print the data
void printData(const std::vector<std::vector<int>>& data) {
	for (const auto& row : data) {
		for (const auto& value : row) {
			std::cout << value << " ";
		}
		std::cout << std::endl;
	}
}

static int distace(int a, int b) {
	return (a > b) ? a - b: b - a;
}

static std::string stateToString(ReportState state) {
	switch (state) {
	case ReportState::Decreasing:
		return "decreasing";
	case ReportState::Increasing:
		return "increasing";
	case ReportState::Neither:
		return "neither";
	}
	return "Unknown";
}

// Function to check if a number is in the vector
bool isNumberInVector(const std::vector<int>& vec, int number) {
	return std::find(vec.begin(), vec.end(), number) != vec.end();
}

static bool isSafe(const std::vector<int> report) {
	/*
	7 6 4 2 1: Safe because the levels are all decreasing by 1 or 2.
	1 2 7 8 9: Unsafe because 2 7 is an increase of 5.
	9 7 6 2 1: Unsafe because 6 2 is a decrease of 4.
	1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is decreasing.
	8 6 4 4 1: Unsafe because 4 4 is neither an increase or a decrease.
	1 3 6 7 9: Safe because the levels are all increasing by 1, 2, or 3.
	}*/
	ReportState state = ReportState::Neither;
	std::vector<int> distances;

	for (int i = 0; i < report.size() - 1; i++) {
		
		if (i == 0) {
			state = (report[i] > report[i + 1]) ? ReportState::Decreasing : (report[i] == report[i + 1]) ? ReportState::Neither : ReportState::Increasing;
			if (state == ReportState::Neither) {
				std::cout << "Unsafe because " << report[i] << " " << report[i + 1] << " is neither an increase or a decrease." << std::endl;
				return false;
			}
		}
		else 
		{
			if (report[i] > report[i + 1]) {
				if (state != ReportState::Decreasing) {
					//std::cout << "Not Decreasing" << " at index " << i << " value " << report[i] << " " << report[i + 1] << std::endl;
					std::cout << "Unsafe because " << report[0] << " " << report[1] << " is decreasing but " << report[i] << " " << report[i + 1] << " is increasing." << std::endl;
					return false;
				}
			}
			else if (report[i] < report[i + 1]) {
				if (state != ReportState::Increasing) {
					//std::cout << "Not Increasing" << " at index " << i << " value " << report[i] << " " << report[i + 1] << std::endl;
					std::cout << "Unsafe because " << report[0] << " " << report[1] << " is increasing but " << report[i] << " " << report[i + 1] << " is decreasing." << std::endl;
					return false;
				}
			}
			else {
				//std::cout << "Neither" << " at index " << i << " value " << report[i] << " " << report[i + 1] << std::endl;
				std::cout << "Unsafe because " << report[i] << " " << report[i + 1] << " is neither an increase or a decrease." << std::endl;
				return false;
			}
		}
		int dist = distace(report[i], report[i + 1]);
		if (dist == 0 || dist > 3) {
			std::cout << "Unsafe because "  << report[i] << " " << report[i + 1] << " is " << ((state == ReportState::Decreasing) ? " a " : " an ") << stateToString(state) << " of " << dist << "." << std::endl;
			return false;
		}
		if (!isNumberInVector(distances, dist)) {
			distances.push_back(dist);
		}
	}

	std::string distancesStr = "";
	//std::cout << "distances size = " << distances.size() << std::endl;
	std::qsort(&distances[0], distances.size(), sizeof(int), [](const void* a, const void* b) -> int {
		return (*(int*)a - *(int*)b);
	});
	switch (distances.size())
	{
		case 1:
			distancesStr = std::to_string(distances[0]);
			break;
		case 2:
			distancesStr = std::to_string(distances[0]) + " or " + std::to_string(distances[1]);
			break;
		default:
			for(int i = 0; i < distances.size(); i++)
			{
				if (i == distances.size() - 1)
					distancesStr += "or " + std::to_string(distances[i]);
				else if (i == distances.size() - 2)
					distancesStr += std::to_string(distances[i]) + " ";
				else
					distancesStr += std::to_string(distances[i]) + ", ";
			}
			break;
	}

	std::cout << "Safe because the levels are all " << stateToString(state) << " by " << distancesStr << "." << std::endl;
	
	return true;
}

int main()
{
	try {
		// Get the current working directory
		std::filesystem::path currentPath = std::filesystem::current_path();

		// Print the current working directory
		std::cout << "Current working directory: " << currentPath << std::endl;

		std::string filename = "day02.txt";
		std::filesystem::path filePath = currentPath / filename;
		std::cout << "File path: " << filePath << std::endl;
		//std::vector<std::vector<int>> data = readData(filePath.string());

		//std::cout << "Data:" << std::endl;
		//printData(data);
		//std::vector<std::vector<int>> reports = readData(filePath.string());
		std::vector<std::vector<int>> reports = {
		{ 7, 6, 4, 2, 1 },
		{ 1, 2, 7, 8, 9 },
		{ 9, 7, 6, 2, 1 },
		{ 1, 3, 2, 4, 5 },
		{ 8, 6, 4, 4, 1 },
		{ 1, 3, 6, 7, 9 }
		};
		int numOfSafe = 0;
		int numOfUnsafe = 0;
		for (int i = 0; i < reports.size(); i++) {
			if (isSafe(reports[i])) {
				numOfSafe++;
			}
			else {
				numOfUnsafe++;
			}
		}
		std::cout << numOfSafe << ((numOfSafe > 1) ? " reports are safe." : " report is safe.") << std::endl;
		std::cout << numOfUnsafe << ((numOfUnsafe > 1) ? " reports are unsafe" : " report is safe.") << std::endl;

	}
	catch (const std::filesystem::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
