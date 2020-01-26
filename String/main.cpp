#include "String.h"


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();
	String str2 = "Hello";
	str2.print();

	String str3 = str2;	//Copy constructor
	str3.print();
	String str4;
	str4 = str2;		//Copy assignment
	str4.print();
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	str1 += str2;
	std::cout << str1 << std::endl;
	/*str1 = str1;
	str1.print();*/
	//String str3 = str1 + str2;	//Move constructor
	//String str3;
	//str3 = str1 + " " + str2;		//Move assignment
	//str3.print();
	//std::cout << str3 << std::endl;
}

//MoveConstructor/MoveAssignment