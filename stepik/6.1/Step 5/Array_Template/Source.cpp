#include <cstddef>
#include <algorithm>
#include <iostream>

template <typename T>
class Array
{
public:	
public:
	explicit Array(size_t size = 0, const T& value = T())
		: data_(new T[size]), size_(size)
	{
		for (size_t i = 0; i != size_; ++i)
			data_[i] = value;
	}

	Array(const Array & a)
		: data_(new T[a.size_]), size_(a.size_)
	{
		for (size_t i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
	}


	~Array() {
		delete[] data_;
		size_ = 0;
	}

	Array& operator=(const Array & a)
	{
		if (this != &a)
			Array(a).swap(*this);
		return *this;
	}

	size_t size() const { return size_; }

	T& operator[](size_t i)
	{
		return data_[i];
	}

	const T& operator[](size_t i) const
	{
		return data_[i];
	}

private:
	void swap(Array & a)
	{
		std::swap(size_, a.size_);
		std::swap(data_, a.data_);
	}

	T* data_;
	size_t	size_;
};

int main()
{
	Array<int> int_arr(10, 1);
	Array<int> int_arr2(20, 0);
	int_arr = int_arr2;
	std::cout << int_arr[5] << std::endl;
	std::cout << int_arr2[5] << std::endl;
	return 0;
}