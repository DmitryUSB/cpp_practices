struct Number {};

struct BigInt : Number
{
	BigInt(int x) { int x1 = x; };
};

struct String
{
	explicit String(char const* s) { char const* ch = s; };
};

int main()
{
	int a = 3.5;
	double b = 7;
	BigInt c = 100500;
	//String d = "Stepik";
	Number* e = &c;
	BigInt* f = static_cast<BigInt*>(e);
	void* g = f;
	BigInt* h = g;

	return 0;
}