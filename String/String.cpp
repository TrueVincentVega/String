#include "String.h"

//		Class deffinition // Определение класса ////////////////////////////
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	/*for (int i = 0; i < left.get_size(); i++)result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)result.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
	for (int i = 0; i < left.get_size(); i++)result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)result[i + left.get_size() - 1] = right[i];
	//left.get_str()[3] = '@';
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
/////////////////////////////////////////////////////////////////////