#include <cstddef>
#include <algorithm>
#include <iostream>

template <typename T>
class Array
{
public:
	//   ����������� ������, ������� �������
	//   Array ������� size, ����������� ����������
	//   value ���� T. ���� � ������ ��� ������������
	//   �� ���������, �� ������ �������� ����� ������������
	//   ����������.
	explicit Array(size_t size, const T& value = T())
		: size_(size) {
		data_ = (T*) new char[size_ * sizeof(T)];
		for (size_t i = 0; i != size_; ++i)
			new (data_ + i) T(value);
	}


	//   ����������� ������, ������� ����� �������
	//   ��� ����������. ������ ��������� ������
	//   Array.
	Array() : data_(0), size_(0) {}

	//   ����������� �����������, ������� �������
	//   ����� ���������. ��� ���� T ��������
	//   ������������ �� ���������.
	Array(const Array & a)
		: size_(a.size_) {
		data_ = (T*) new char[size_ * sizeof(T)];
		for (size_t i = 0; i != size_; ++i)
			new (data_ + i) T(a[i]);
	}

	//   ����������, ���� �� ��� ���������.
	~Array() {
		for (size_t i = 0; i != size_; ++i)
			data_[i].~T();
		delete[](char*) data_;
	}

	//   �������� ������������.
	Array& operator=(const Array & a) {
		if (this != &a) {
			Array(a).swap(*this);
		}
		return *this;
	}

	//   ���������� ������ ������� (���������� 
	//                              ���������).
	size_t size() const { return size_; }

	//   ��� ������ ��������� ������� �� �������.
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