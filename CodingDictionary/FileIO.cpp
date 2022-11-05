#pragma once

#include "FileIO.h"

void FileIO::OperateFileModel()
{
    while (true)
    {
        cout << "Select One of the Options Below:\n";
        cout << "1: Create a file\n2: Read from a File\n3: Quit" << endl;
        int choice;
        cout << "Selection: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            CreateOutputFile(RequestString());
            break;
        case 2:
            ReadFile(RequestString());
            break;
        case 3:
            return;
        default:
            cout << "You have entered an invalid choice! Try again." << endl;
        }
    }
}



string FileIO::RequestString()
{
    cout << "Enter the name of the File: ";
    string Name;
    cin >> Name;
    return Name;
}



void FileIO::CreateOutputFile(string FileName)
{
    fstream File;
    File.open(FileName, ios::out);
    if (!File.is_open())
    {
        cout << "Could not write to the file";
        return;
    }
    cout << "Enter the size of the file you would like to generate in #Lines: ";
    int nLines;
    cin >> nLines;
    File << GenerateText(nLines);
    File.close();
}

vector<vector<string>> FileIO::ReadFile(string FileName)
{
    fstream File;
    File.open(FileName, ios::in);
    if (!File.is_open())
    {
        cout << "File could not be opened." << endl;
        exit(1);
    }
    stringstream ss; // StringStream allows you to treat a string object like a stream, so you can use
    string Line;     // all of the stream functions and operators on it
    int LineNumber = 0;
    vector<vector<string>> AllWords;
    while (getline(File, Line))
    {
        ss << Line; // Stream
        while (!ss.eof())
        {
            string* nextWord = new string;
            AllWords[LineNumber].push_back(*nextWord);
            delete nextWord;
        }
        LineNumber++;
    }
    return AllWords;
}

string FileIO::GenerateText(int NumberLines)
{
    string Text;
    int LineLength = 70;
    for (int i = 0; i < NumberLines; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            Text.push_back(GenerateRandomCharacter());
        }
        Text.push_back('\n');
    }
    return Text;
}

char FileIO::GenerateRandomCharacter()
{
    int randomNumber = (rand() % 92) + 34; // Generate a random number between 34 - 126
    return (char)randomNumber;
}