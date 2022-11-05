#include "CharArrays.h"

void CharArray::CapitalizeCharArray(const char* word)
{
    int stringLength = strlen(word);
    char* Word = new char[stringLength + 1];
    for (int i = 0; i < stringLength; i++)
    {
        Word[i] = CapitalizeLetter(word[i]);
    }

    // Char * Arrays are not automatically null terminated unless we initialize the array with a string literal
    Word[stringLength] = '\0';
    cout << "The modified word is " << Word << endl;
    delete[] Word;
}

void CharArray::LowerCaseWord(const char* word)
{
    int stringLength = strlen(word);
    char* Word = new char[stringLength + 1];
    for (int i = 0; i < stringLength; i++)
    {
        Word[i] = LowerCaseLetter(word[i]);
    }

    // Char * Arrays are not automatically null terminated unless we initialize the array with a string literal
    Word[stringLength] = '\0';
    cout << "The modified word is " << Word << endl;
    delete[] Word;
}

char CharArray::CapitalizeLetter(char Letter)
{
    if (Letter >= 'a' && Letter <= 'z')
        return Letter - ('z' - 'Z');
    else
        return Letter;
}

char CharArray::LowerCaseLetter(char Letter)
{
    if (Letter >= 'A' && Letter <= 'Z')
        return Letter + ('a' - 'A');
    else
        return Letter;
}

void CharArray::OperateCharModel()
{
    cout << "Generate a String you would like to modify (Max 256 Chars): ";
    cin >> CurrentWord;
    while (true)
    {
        cout << "Now select what you want to do with the word: " << endl;
        cout << "1: Capitalize\n2: LowerCase\n3: Quit" << endl;
        int choice;
        cout << "Selection: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            CapitalizeCharArray(CurrentWord);
            break;
        case 2:
            LowerCaseWord(CurrentWord);
            break;
        case 3:
            return;
        default:
            cout << "You have entered an invalid choice! Try again." << endl;
        }
    }
}