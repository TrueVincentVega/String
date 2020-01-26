#pragma once
#include<iostream>
//#define CONSTRUCTORS_CHECK
//	Class declaration //Объявление класса
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	unsigned int size;	//Размер строки в Байтах.
	char* str;			//Указатель на строку в динамической памяти.
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//Constructors:
	explicit String(unsigned int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << "DefaultConstruct:" << this << std::endl;
	}
	String(const char* str)
	{
		this->size = Strlen(str) + 1;
		this->str = new char[size] {};
		//for (int i = 0; str[i]; i++)this->str[i] = str[i];
		for (int i = 0; str[i]; i++)*(this->str + i) = *(str + i);
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		std::cout << "CopyConstructor:" << this << std::endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		std::cout << "MoveConstructor:" << this << std::endl;
	}
	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		std::cout << "MoveAssignment:" << this << std::endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	const char& operator[](int index)const
	{
		return str[index];
	}
	char& operator[](int index)
	{
		return str[index];
	}

	//			Methods:
	void print()const
	{
		std::cout << "size:\t" << size << std::endl;
		std::cout << "str:\t" << str << std::endl;
	}

	int Strlen(const char* str)
	{
		int i = 0;
		for (; str[i]; i++);
		return i;
	}
};
////////////////////////////////////////////////////////////////
