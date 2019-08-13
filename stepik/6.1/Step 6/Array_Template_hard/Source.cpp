#include <cstddef>
#include <algorithm>
#include <iostream>

template <typename T>
class Array
{
public:
	//   конструктор класса, который создает
	//   Array размера size, заполненный значениями
	//   value типа T. Если у класса нет конструктора
	//   по умолчанию, то второй аргумент этого конструктора
	//   обязателен.
	explicit Array(size_t size, const T& value = T())
		: size_(size) {
		data_ = (T*) new char[size_ * sizeof(T)];
		for (size_t i = 0; i != size_; ++i)
			new (data_ + i) T(value);
	}


	//   конструктор класса, который можно вызвать
	//   без параметров. Должен создавать пустой
	//   Array.
	Array() : data_(0), size_(0) {}

	//   конструктор копирования, который создает
	//   копию параметра. Для типа T оператор
	//   присваивания не определен.
	Array(const Array & a)
		: size_(a.size_) {
		data_ = (T*) new char[size_ * sizeof(T)];
		for (size_t i = 0; i != size_; ++i)
			new (data_ + i) T(a[i]);
	}

	//   деструктор, если он вам необходим.
	~Array() {
		for (size_t i = 0; i != size_; ++i)
			data_[i].~T();
		delete[](char*) data_;
	}

	//   оператор присваивания.
	Array& operator=(const Array & a) {
		if (this != &a) {
			Array(a).swap(*this);
		}
		return *this;
	}

	//   возвращает размер массива (количество 
	//                              элементов).
	size_t size() const { return size_; }

	//   две версии оператора доступа по индексу.
	T& operator[](size_t i) {
		return data_[i];
	}

	const T& operator[](size_t i) const {
		return data_[i];
	}

private:
	void swap(Array & a) {
		std::swap(size_, a.size_);
		std::swap(data_, a.data_);
	}

	void myfree() {
		for (size_t i = 0; i != size_; ++i)
			data_[i].~T();
		delete[](char*) data_;
	}

	Array* p_;
	T* data_;
	size_t	size_;
};

int main()
{
	Array<int> int_arr(10, 1);
	/*Array<int> int_arr2(20, 0);
	int_arr = int_arr2;
	std::cout << int_arr[5] << std::endl;
	std::cout << int_arr2[5] << std::endl;*/
	return 0;
}