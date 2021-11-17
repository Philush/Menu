#include <iostream>
#include "MyString.h"


int main()
{
	char sampleStr[20]{ "aaa" };
	char protStr[20]{"w"};

	//std::cout << R"(Length of string ")" << sampleStr << R"(" = )"
		//<< strLen(sampleStr) << std::endl;

	
	std::cout << "First String: " << strCmp(sampleStr, protStr);    //sampleStr << std::endl << "Second String: " << protStr << std::endl << "Result: " << res ;


	return 0;
}