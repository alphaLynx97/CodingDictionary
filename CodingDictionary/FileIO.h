#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class FileIO
{
public:
	FileIO()
	{
	}

	string RequestString();
	void OperateFileModel();
	void CreateOutputFile(string FileName);
	vector<vector<string>> ReadFile(string FileName);
	string GenerateText(int NumberLines); // Generate random text of variable Lines of length 70
	char GenerateRandomCharacter();
};