#include <iostream>
#include <algorithm>
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
	Expression& operator*() const { return *ptr_; };
	Expression* operator->() const { return ptr_; };


private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};

struct SharedPtr
{
	// реализуйте следующие методы
	explicit SharedPtr(Expression* ptr = 0) : ptr_(ptr), cnt_(0) {
		if (ptr_ != 0) cnt_ = new size_t(1);
	};
	~SharedPtr() {
		
		if (cnt_ && (-- * cnt_ == 0)) {
			delete ptr_;
			delete cnt_;
		}
		};

	SharedPtr(const SharedPtr & ptr) : ptr_(ptr.ptr_), cnt_(ptr.cnt_) {
		if (cnt_ != 0)++ * cnt_;
	};
	void swap(SharedPtr & ptr) {
		std::swap(ptr_, ptr.ptr_);
		std::swap(cnt_, ptr.cnt_);
	};
	SharedPtr& operator=(const SharedPtr & ptr) {
		if (this == &ptr) return *this;
		if (cnt_ && (-- * cnt_ == 0)) delete ptr_, delete cnt_;
		if (ptr.cnt_ != 0) { ++* ptr.cnt_; SharedPtr(ptr).swap(*this); }
		return *this;
	};

	Expression* get() const { return ptr_; };

	void reset(Expression* ptr = 0) {

		if (cnt_ && (-- * cnt_ == 0)) delete ptr_, delete cnt_;
		if (ptr != 0) { ++* cnt_; ptr_ = ptr; }
	};

	Expression & operator*() const { return *ptr_; };
	Expression* operator->() const { return ptr_; };
private:
	Expression* ptr_;
	size_t* cnt_;
};



int main() 
{
	Expression * expr = new BinaryOperation(new Number(5), '*', new Number(5));
	Expression* expr1 = new BinaryOperation(new Number(1), '+', new Number(1));

	SharedPtr sh = SharedPtr(expr);
	SharedPtr sh1 = SharedPtr(expr1);

	sh = sh1;

	sh1.reset(expr);
	if (sh.get() == sh1.get()) { int a = 0; }
	
	

	
	return 0;
}