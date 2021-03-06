// ZaliczenieSemestr1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <ctime>
#include <cmath>
#include <functional>
#include <fstream>

std::vector<int> Range(int start, int end, int step);
std::vector<int> GenerateRandomNumbers(int size,int from, int to);
void sortNumbers(std::vector<int> &vec);

int main()
{
    std::cout << "Hello World!\n"; 
	//Christmas Tree
	int treeHeight;
	std::cout << "Tree height : ";
	std::cin >> treeHeight;
	int emptySpaces = treeHeight - 1;
	int hashSign = 1;
	int lastHash = emptySpaces;

	while (treeHeight != 0) {
		for (auto x : Range(1, emptySpaces, 1)) {
			std::cout << " ";
		}
		for (auto x : Range(1, hashSign, 1)) {
			std::cout<<"#";
		}
		std::cout<<std::endl;
		hashSign+=2;
		treeHeight -= 1;
		emptySpaces -= 1;
	}
	
	for (auto x : Range(1, lastHash, 1)) {
		std::cout << " ";
	}
	std::cout << "#\n";
	
	std::cout << std::endl;
	
	srand(time(NULL));

	std::vector<int> theNumbers = GenerateRandomNumbers(20,25,75);

	//Zapis
	std::ofstream WriteToFile;
	WriteToFile.open("numbers1.txt", std::ios_base::out | std::ios_base::trunc);
	for (auto x : theNumbers) {
		std::cout << x << " ";
		if (WriteToFile.is_open()) {
			WriteToFile << x << " ";
		}
	}
	WriteToFile.close();
	
	sortNumbers(theNumbers);
	std::cout << std::endl<<"Posortowane : \n";
	
	//Zapis posortowanych
	WriteToFile.open("numbers1.txt", std::ios_base::out | std::ios_base::app);
	if (WriteToFile.is_open()) {
		WriteToFile << "\nPosortowane :\n";
		for (auto x : theNumbers) {
			std::cout << x << " ";
			if (WriteToFile.is_open()) {
				WriteToFile << x << " ";
			}
		}
	}
	WriteToFile.close();

	system("notepad.exe numbers1.txt");

	return 0;
}

std::vector<int> Range(int start, int end, int step) {
	std::vector<int>rtnVec;
	int i = start;
	while (i <= end) {
		rtnVec.push_back(i);
		i += step;
	}
	return rtnVec;
}

std::vector<int> GenerateRandomNumbers(int size,int from, int to) {
	std::vector<int> rtnVec;
	int i = 0;
	int value = 0;
	while (i < size) {
		int value =from + rand() % ((to+1)-from);
		rtnVec.push_back(value);
		size--;
	}
	return rtnVec;
}

void sortNumbers(std::vector<int> &vec) {
	int i = vec.size() - 1;
	while (i >= 1) {
		int j = 0;
		while (j < i) {
			if (vec[j] > vec[j + 1]) {
				int temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
			else {

			}
			j += 1;
		}
		i -= 1;
	}
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
