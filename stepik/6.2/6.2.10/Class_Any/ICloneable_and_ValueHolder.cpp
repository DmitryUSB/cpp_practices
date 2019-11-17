struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

// ������ ValueHolder � ������� ���������� T,
// ������ ��������� ���� �������� ���� data_
// ���� T.
//
// � ������� ValueHolder ������ ���� ���������
// ����������� �� ������ ��������� ���� T,
// ������� �������������� ���� data_.
//
// ������ ValueHolder ������ �������������
// ��������� ICloneable, � ���������� ���������
// �� ����� �������, ��������� � ����, �� ������
// clone.

template <typename T>
struct ValueHolder : ICloneable
{
	ValueHolder(const T& input)
		: data_(input) {}

	ValueHolder* clone() const {
		return new ValueHolder(*this);
	}
	~ValueHolder() {}

	T data_;
};