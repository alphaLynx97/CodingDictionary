#include "CharArrays.h"
#include "Dictionary.h"
#include "String.h"

int main(int argc, char* argv[])
{
	Dictionary Dict;
	//Dict.CharMethods.OperateCharModel();
	//Dict.FileMethods.OperateFileModel();
	String name = "Daanish";
	String name2 = "George";
	String Concatenation = name + name2;
	cout << "The final string is " << Concatenation.stringArray << endl;
	return 0;
}