#include <iostream>

class A
{
public:
	A(){ std::cout << "A construction" << std::endl; }
	virtual ~A(){ std::cout << "A destruction" << std::endl; }
};

class B : public A
{
public:
	B() { std::cout << "B construction" << std::endl; }
	~B() { std::cout << "B destruction" << std::endl; }
};

class C : public B
{
public:
	C() { std::cout << "C construction" << std::endl; }
	~C() { std::cout << "C destruction" << std::endl; }
};


int main()
{
	A* a = new C();
	C a1;
	delete a;
	//delete a1;
	return 0;
}