#include <iostream>
#include <stdio.h>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> 

struct myTask {
	int index;
	std::string name;
	int priority;
	bool bDone;

};

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

	std::vector<std::pair<std::string, int>> pairs;
	 
	for (auto itr = taskMap.begin(); itr != taskMap.end(); itr++) {
		pairs.push_back(*itr);
	}

	std::sort(pairs.begin(), pairs.end(), [=](std::pair < std::string, int>& a, std::pair < std::string, int>& b) {
		return a.second > b.second;
	});


	std::vector<myTask> taskList;
	int count = 0;
	for (const auto& pair : pairs) {
		count++;
		myTask task;

		task.name = pair.first;
		task.priority = pair.second;
		task.index = count;
		task.bDone = false;

		taskList.push_back(task);
			
	}

	while (true) {
		system("cls");

		for (const auto& task : taskList) {
			
			std::cout << "[ " << task.index << " ] "
				<< "NAME: " << task.name
				<< " | "
				<< "PRIORITY: " << task.priority
				<< " | "
				<< "DONE: " << task.bDone
				<< std::endl;
		}

		std::cout << "Please select the task you did: ";
		int input;
		std::cin >> input;

		if (input > 0 && input <= taskList.size()) {
			taskList[input - 1].bDone = !taskList[input - 1].bDone;
		}
		else
		{
			std::cout << "\nWrong Input\n";
			system("pause");
		}
	}
	
}