#include <iostream>
#include "Expres.h"

struct ScopedPtr
{
    // реализуйте следующие методы:
    //
    explicit ScopedPtr(Expression *ptr = 0): ptr_(ptr) {};
    ~ScopedPtr() { delete ptr_; };
    Expression* get() const { return ptr_; };
    Expression* release() {
        Expression* tmp = ptr_;
        ptr_ = 0;
        return tmp;
    };
    void reset(Expression *ptr = 0) {
       delete ptr_;
       ptr_ = ptr;
    };
    Expression& operator*() const { return *ptr_; }
    Expression* operator->() const { return ptr_; }


private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};

int main() 
{
	Expression const * sube = new BinaryOperation(new Number(5), '*', new Number(5));	
	Expression* expr = new BinaryOperation(new Number(3), '+', sube);
	ScopedPtr scoop(expr);
	
	std::cout << expr->evaluate() << std::endl;
	std::cout << "Scooped: " << scoop->evaluate() << std::endl;
	
	

	
	return 0;
}