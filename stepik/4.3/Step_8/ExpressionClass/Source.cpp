#include <iostream>

/* Visitor Class */
struct Visitor {
	virtual void visitNumber(Number const* number) = 0;
	virtual void visitBinaryOperation(BinaryOperation const* binary) = 0;
	virtual ~Visitor() { }
};

struct Expression
{
	virtual double evaluate() const = 0;
	//virtual double getValue() const = 0;
	virtual void visit(Visitor* visitor) const = 0;
	virtual ~Expression() {}
};

struct Number : Expression
{
	Number(double value)
		: value(value)
	{}
	double evaluate() const { return value; }
	void visit(Visitor* visitor) const { visitor->visitNumber(this); }
	double get_value() const { return value; }
private:
	double value;
};

struct BinaryOperation : Expression
{
	/*
	  «десь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операци€м,
	  которые вам нужно реализовать.
	 */
	BinaryOperation(Expression const* left, char op, Expression const* right)
		: left(left), op(op), right(right)
	{ }
	~BinaryOperation()
	{
		delete left;
		delete right;
	}
	
	double evaluate() const
	{
		if (op == '+') 
			return left->evaluate() + right->evaluate();
		if (op == '-')
			return left->evaluate() - right->evaluate();
		if (op == '*')
			return left->evaluate() * right->evaluate();
		if (op == '/')
			return left->evaluate() / right->evaluate();
	}

	void visit(Visitor* visitor) const { visitor->visitBinaryOperation(this); }
	Expression const* get_left()  const { return left; }
	Expression const* get_right() const { return right; }
	char get_op() const { return op; }

private:
	Expression const* left;
	Expression const* right;
	char op;
};

/*
Ф‘ункци check_equals, принимает на вход два указател€ на базовый класс Expression, 
и возвращает true, если оба указателя указывают на самом деле 
на объекты одного и того же класса, и false в противном случае
*/
bool check_equals(Expression const *left, Expression const *right)
{
    if (*((int**)left) == *((int**)right)) return true;
	else return false;
}


struct PrintBinaryOperationsVisitor : Visitor {
	void visitNumber(Number const* number)
	{ }

	void visitBinaryOperation(BinaryOperation const* bop)
	{
		bop->get_left()->visit(this);
		std::cout << bop->get_op() << " ";
		bop->get_right()->visit(this);
	}
};

int main()
{
	Expression const * sube = new BinaryOperation(new Number(5), '*', new Number(5));
	//Expression* expr = new BinaryOperation(new Number(3), '+', sube);
	//std::cout << expr->evaluate() << std::endl;
	PrintBinaryOperationsVisitor visitor;
	sube->visit(&visitor);

	delete sube;

	
	return 0;
}