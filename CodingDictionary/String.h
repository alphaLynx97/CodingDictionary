#pragma once
#include <iostream>

using namespace std;

//Create a pseudo string object
//Rule of 3: If a class requires a user-defined destructor, a user-defined copy constructor, or a user-defined copy assignment operator,
//it almost certainly requires all three.

class String
{
public:
    //Members of the string class
    char* stringArray = nullptr;
    int stringLength = 0;
    //2 Methods of class initialization. 1 is Parenthesis, the other is assignment Operator, where the right side argument must
    //be equivalent to the first argument in the constructor, and if other arguments in the constructor, they must be default
    //Note: Initialization is not the same as assignmen
    //Default Constructor
    String()
    {
    }

    //Constructor for assigning String Literals
    String(const char* stringLiteral)
    {
        //First, we need to dynamically allocate memory for the stringArray
        int stringLength = (int)(strlen(stringLiteral) + 1); // Add 1, as strlen does not count the Nul character
        stringArray = new char[stringLength];
        memcpy(stringArray, stringLiteral, stringLength); // Time Complexity O(1), takes approximately 37.5ms
        this->stringLength = stringLength;
    }

    //Copy Constructor, called when returning from a function
    String(String& OriginalString)
    {
        this->stringArray = new char[OriginalString.stringLength]; //Give a pointer equal to the size of the copied stringArray
        memcpy(this->stringArray, OriginalString.stringArray, OriginalString.stringLength); //Copy value to new address
        this->stringLength = OriginalString.stringLength;
    }

    //Destructor, we grabbed memory from the heap. We need to give it back to the OS when this object goes out of scope
    ~String()
    {
        delete[] stringArray;
        stringLength = 0;
    }

    //Overloading Operators: We want to be able to do string assignment as well as concatenation
    void operator=(String& otherString)
    { //String assignment will affect 'this', thus we do not make this a const member function
        delete[] this->stringArray; //Deallocate the heap memor
        new char[otherString.stringLength]; //Rellocate the right size (including Nul character)
        memcpy(this->stringArray, otherString.stringArray, otherString.stringLength);
        this->stringLength = otherString.stringLength;
    }

    String operator+(String& otherString) const
    { //String Concatenation produces a return type string, but does not affect 'this', thus the const at the end
        int totalStringLength = (this->stringLength + otherString.stringLength) - 1; //Subtract 1 byte for extra '\0'
        String FinalString;
        FinalString.stringArray = new char[totalStringLength];
        int i = 0, j = 0;
        while (this->stringArray[i] != '\0')
        {
            FinalString.stringArray[i] = this->stringArray[i];
            i++;
        }
        while (otherString.stringArray[j] != '\0')
        {
            FinalString.stringArray[i] = otherString.stringArray[j];
            i++;
            j++;
        }

        FinalString.stringArray[i] = '\0';
        FinalString.stringLength = totalStringLength;
        return FinalString; //Note, when returning an object, the default constructor will run, copying the pointer
        //for stringArray, then the destructor will run wiping the same pointer in the local copy. We need to create
        //a copy constructor so that the contents of the values are copied, but new addresses are used
    }
};