#include "ICloneable_and_ValueHolder.cpp"

#include <iostream>
#include <algorithm>

/*
// ��� ������ ������������� ������ �� �����
struct ICloneable;

// ���� data_ ���� T � ������ ValueHolder
// �������, � ���� ����� ����������
template <typename T>
struct ValueHolder;
*/

// ��� �����, ������� ��� ����� �����������
class Any
{
	public:	
		// � ������ Any ������ ���� �����������,
		// ������� ����� ������� ��� ����������,
		// ����� ������� ��������� ���:
		//    Any empty; // empty ������ �� ������
		Any() : _ptr(0) { };

		// � ������ Any ������ ���� ���������
		// ����������� �� ������ ���������, �����
		// ����� ���� ��������� ������� ���� Any,
		// ��������, ��������� �������:
		//    Any i(10); // i ������ �������� 10
		template <typename T>
		Any(const T one_param) : _ptr(new ValueHolder<T>(one_param)) { }

		// �� �������� ��� ����������. ��� ����������
		// ������� ����� ����������.
		~Any() { delete _ptr; };
		
		// � ������ Any ����� ������ ���� �����������
		// ����������� (��� ������� ����� clone
		// ���������� ICloneable)
		Any(Any const& other) {
			if (other._ptr) _ptr = other._ptr->clone();
			else  _ptr = 0;
		}

		void swap(Any& other) {
			std::swap(_ptr, other._ptr);
		}
		// � ������ ������ ���� �������� ������������ �/���
		// ��������� �������� ������������, ����� �������
		// ��������� ���:
		//    Any copy(i); // copy ������ 10, ��� � i
		//    empty = copy; // empty ������ 10, ��� � copy
		//    empty = 0; // � ������ empty ������ 0
		//template <typename T>
		Any& operator = (Any const& other) {
			
			if (this != &other)
				Any(other).swap(*this);
				
			return *this;
		}

		// �� � �������, �� ����� ����� �������� ��������
		// ��������, ��� ����� ���������� � ������ Any
		// ��������� ����� cast, ������� ����������
		// ��������� �� �������� ��������, ��� �������
		// ��������� � ������ �������������� ����� ���
		// ���� ������ Any ������ �� ������:
		//    int *iptr = i.cast<int>(); // *iptr == 10
		//    char *cptr = i.cast<char>(); // cptr == 0,
		//        // ������ ��� i ������ int, � �� char
		//    Any empty2;
		//    int *p = empty2.cast<int>(); // p == 0
		// ��� ���������� ����������� �������� dynamic_cast.
		
		template <typename T>
		T* cast() {
			if (_ptr)
			{
				//ICloneable* base = _ptr->clone();
				ValueHolder<T>* holder_ptr = dynamic_cast<ValueHolder<T>*>(_ptr);
				if (holder_ptr) return &holder_ptr->data_;
				else return 0;
			}
			return 0;
		}

		// �������� � ��� ���� ��� ���������� ������ Base: Derived1 
		// � Derived2. ����� ���� � ��� ���� ������� baseptr
		// ���� Base*. ��� ��������� ��������� �� ���� ��������� ��
		// ����� ���� �� ������ ������ Derived1 ��� �� ������ 
		// ������ Derived2? ��� ����� ����� ��������������� dynamic_cast-��:
		//
		// Derived1 *derived1ptr = dynamic_cast<Derived1*>(baseptr);
		//
		// ���� derived1ptr �� ����� 0, ��  baseptr �� ����� ����
		// �������� �� ������ ������ Derived1, ���� �� derivedptr ����� 0,
		// �� baseptr �� ����� ���� �������� �� ����� ������-�� ������� 
		// ������ (��������, Derived2). ��� ����� ��������� ���:
		//
		// Derived2 *derived2ptr = dynamic_cast<Derived2*>(baseptr);
		//
		// dynamic_cast �������� ������, ���� � ������ ���� ���� ��
		// ���� ����������� �����, � � ������� ValueHolder �����
		// ��� ��� �������.
	private:
		ICloneable* _ptr;
};

using namespace std;
int main()
{
	Any empty;
	Any i(10);
	
	Any copy(i); // copy ������ 10, ��� � i
	empty = copy; // empty ������ 10, ��� � copy
	empty = 0; // � ������ empty ������ 0

	int* iptr = i.cast<int>(); // *iptr == 10
	char* cptr = i.cast<char>(); // cptr == 0,
		//        // ������ ��� i ������ int, � �� char
	Any empty2;
	int* p = empty2.cast<int>(); // p == 0

	return 0;
}