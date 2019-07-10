#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

	String(const char* str = "")									// ����������� �����������
	:size(strlen(str)), str(strcpy(new char[size + 1], str))	    // ������ �������������
	{}	
	String(size_t n, char c);										// ����������� �����������
	~String();

	void append(String& other);										//�������

	size_t size;
	char* str;
};
//-----------------������� ������� ������������ ������������-------------------------
/*String::String(const char* str)									
{
	this->size = strlen(str);
	char* tmp_str = new char[this->size + 1];
	strcpy(tmp_str, str);
	this->str = tmp_str;
}*/
//--------------------------����������� �����������----------------------------------
String::String(size_t n, char c):size(n)
{
	str = new char[size + 1];
	size_t i = 0;
	while (i < n) {
		str[i] = c;
		++i;
	}
	str[i] = '\0';
}
//----------------------------����������---------------------------------------------
String::~String()
{
	delete[] str;
	size = 0;
}
//--------------------------����� append---------------------------------------------
void String::append(String& other)
{
	size_t i = 0;
	char* tmp_str = new char[size + other.size + 1];
	while (i < size + other.size)
	{
		if (i < size) tmp_str[i] = str[i];	
		else tmp_str[i] = other.str[i - size];
		++i;
	}
	tmp_str[i] = '\0';
	delete[] str;
	str = tmp_str;
	size = size + other.size;
}
//-----------------------------------------------------------------------------------
int main()
{
	const char c_string[] = "Hello World!";
/*	String str1(c_string);
	String str2;
	String str3(5, 'a');

	std::cout << str1.str << std::endl;
	std::cout << str2.str << std::endl;
	std::cout << str3.str << std::endl; */

	String s1("abc");
	String s2("XYZQWE");
	s1.append(s2);
	std::cout << s1.str << std::endl;

	return 0;
}