#pragma once
#include <iostream>

using namespace std;

class CharArray
{
public:
	CharArray()
	{
		CurrentWord = new char[256];
	}
	char* CurrentWord;
	void OperateCharModel();
	void CapitalizeCharArray(const char* word);
	void LowerCaseWord(const char* word);
	char CapitalizeLetter(char Letter);
	char LowerCaseLetter(char Letter);
};