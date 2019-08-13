#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String;
struct SubString;
//-----------------------------ОСНОВНОЙ класс-----------------------------------------
struct String {

	String(const char* str = "")									// стандартный конструктор
	:size(strlen(str)), str(strcpy(new char[size + 1], str))	    // список инициализации
	{}	
	String(size_t n, char c);										// заполняющий конструктор
	String(const String& other)										// конструктор копирования
		: size(other.size), str(new char[size + 1]) {
		for (size_t i = 0; i != size + 1; ++i)
			str[i] = other.str[i];
	};
	~String();

	void append(String& other);										//склейка
	
	SubString operator[](size_t beg_pos) const;
	
	size_t size;
	char* str;
};
//--------------------------заполняющий конструктор----------------------------------
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
//----------------------------деструктор---------------------------------------------
String::~String()
{
	delete[] str;
	size = 0;
}
//--------------------------метод append---------------------------------------------
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
//-----------------------------Класс ПОСРЕДНИК-----------------------------------------
struct SubString {
	SubString(const String& other, size_t beg_pos)										// конструктор копирования
		: sub_size(other.size), sub_str(new char[sub_size + 1]), beg_pos(beg_pos) {
		for (size_t i = 0; i != sub_size + 1; ++i)
			sub_str[i] = other.str[i];
	};
	~SubString();

	String operator[](size_t beg_pos) const;

	size_t sub_size;
	char* sub_str;
	size_t beg_pos;
};
//----------------------------деструктор---------------------------------------------
SubString::~SubString()
{
	delete[] sub_str; //Степик решение пропустил, а вот Студия не хочет, валится здесь 
	sub_size = 0;
	beg_pos = 0;
}

//-----------------------------Перегрузка для класса посредника-----------------------------------------
String SubString::operator[](size_t end_pos) const {
	String temp_str(end_pos - beg_pos, '0');
	for (size_t i = beg_pos; i != end_pos; ++i)
		temp_str.str[i - beg_pos] = sub_str[i];
	return temp_str;
}
//-----------------------------------------------------------------------------------
//-------------------------Перегрузка для основного класса------------------------------------------
SubString String::operator[](size_t beg_pos) const {
	SubString temp_str(*this, beg_pos);
	return temp_str;
}
int main()
{
	String const hello("hello");
	String const hell = hello[1][4]; // теперь в hell хранится подстрока "hell"
//	String const ell = hello[1][4]; // теперь в ell хранится подстрока "ell"
	//String const h = hello[1][4];
	std::cout << hell.str << std::endl;

	return 0;
}