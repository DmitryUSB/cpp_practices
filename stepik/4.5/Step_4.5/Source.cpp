#include <iostream>;

struct Number;
struct BinaryOperation;

struct Visitor {
	virtual void visitNumber(Number const * number) = 0;
	virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
	virtual ~Visitor() { }
};

struct Expression
{
	virtual double evaluate() const = 0;
	virtual void visit(Visitor * vistitor) const = 0;
	virtual ~Expression() { }
};

struct Number : Expression
{
	Number(double value);
	double evaluate() const;

	double get_value() const { return value; }

	void visit(Visitor * visitor) const { visitor->visitNumber(this); }

private:
	double value;
};

struct BinaryOperation : Expression
{
	BinaryOperation(Expression const * left, char op, Expression const * right);
	~BinaryOperation();
	double evaluate() const;

	Expression const * get_left() const { return left; }
	Expression const * get_right() const { return right; }
	char get_op() const { return op; }

	void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
	Expression const * left;
	Expression const * right;
	char op;
};

Number::Number(double value) : value(value) {}
double Number::evaluate() const
{
	return value;
}
BinaryOperation::BinaryOperation(Expression const* left, char op, Expression const* right)
	: left(left), op(op), right(right)
{ }
BinaryOperation::~BinaryOperation()
{
	delete left;
	delete right;
}
double BinaryOperation::evaluate() const
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

/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor {
	void visitNumber(Number const* number)
	{
		std::cout << number->get_value();
	}

	void visitBinaryOperation(BinaryOperation const* bop)
	{
		std::cout << '(';
		bop->get_left()->visit(this);
		std::cout << bop->get_op() << " ";
		bop->get_right()->visit(this);
		std::cout << ')';
	}
};


int main()
{
	// 5 * 5
	Expression const* sube = new BinaryOperation(new Number(5), '*', new Number(5));
	//3 + 25
	Expression* expr = new BinaryOperation(new Number(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;   //28

	PrintVisitor visitor;
	expr->visit(&visitor);

	delete expr;
	return 0;
}

