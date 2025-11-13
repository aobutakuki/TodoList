#include <iostream>
#include <stdio.h>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

std::ifstream openFile() {


	std::ifstream file("taskList.txt");

	if (!file.is_open())
	{
		std::cout << "Creating File: Restart the Program\n";
		std::ofstream createFile("taskList.txt");

	}
	else {
		std::cout << "Filed Opened\n\n\n";
	}

	return file;

}

std::map <std::string, int> readTasks(std::ifstream file) {
	
	std::map<std::string, int>map;


	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);

		int num;
		std::string taskName, lName;

		iss >> taskName;
		std::getline(iss, lName, ',');
		iss >> num;

		map.insert({ taskName, num });

	}

	return map;

}

int main() {

	std::map<std::string, int> taskMap = readTasks(openFile());
	
	for (const auto& pair : taskMap) {
		std::cout << pair.first << std::endl;

	}
}