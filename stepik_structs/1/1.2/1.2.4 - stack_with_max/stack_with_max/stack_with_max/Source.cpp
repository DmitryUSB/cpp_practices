/*#include <iostream>
#include <vector>
#include <string>
#include <bitset>

class MyStack {
	public:
		MyStack(int size) : _curr(0), _size(0), _data(new int[size]) { }
		~MyStack() { delete[] _data; }
		int top() { if (_size != 0) return _data[_curr - 1]; else throw std::range_error("ERROR: top() on empty stack!"); }
		void push(int a) { _data[_curr] = a; ++_curr; ++_size; }
		void pop() { if (_size != 0) { --_curr; --_size; } else throw std::range_error("ERROR: pop() on empty stack!"); }
		bool empty() { if (_size == 0) return true; else return false; }
		size_t size() { return _size; }
	private:
		int _curr;
		int* _data;
		size_t _size;
};

int main()
{
	
	std::vector<std::string> op_vec;
	int op_count, numb_to_push;
	std::string op;

	std::cin >> op_count;
	MyStack lib_stack(op_count);
	MyStack lib_stack_max(op_count);
	for (int i = 0; i < op_count+1; ++i) {
		std::getline(std::cin, op); 
		if (op == "") continue;
		op_vec.push_back(op); 
	}

	//std::string::npos - если не найдена подстрока
	try {
		for (auto a : op_vec)
		{
			if (a.find("push") != std::string::npos) {
				numb_to_push = atoi(a.erase(0, 4).c_str());
				lib_stack.push(numb_to_push);
				if (!lib_stack_max.empty()) {
					if (numb_to_push >= lib_stack_max.top()) lib_stack_max.push(numb_to_push);
					else lib_stack_max.push(lib_stack_max.top());
				}
				else lib_stack_max.push(numb_to_push);
			}
			else if (a.find("pop") != std::string::npos) {
				lib_stack.pop();
				lib_stack_max.pop();
			}
			else if (a.find("max") != std::string::npos) std::cout << lib_stack_max.top() << std::endl;
		}
	}
	catch (std::range_error& e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}

	return 0;
}*/

#include <iostream>
#include <vector>


using namespace std;

class MyStack {
public:
	MyStack(int size) : _curr(0), _size(0), _data(new int[size]) { }
	~MyStack() { delete[] _data; }
	int top() { if (_size != 0) return _data[_curr - 1]; else throw std::range_error("ERROR: top() on empty stack!"); }
	void push(int a) { _data[_curr] = a; ++_curr; ++_size; }
	void pop() { if (_size != 0) { --_curr; --_size; } else throw std::range_error("ERROR: pop() on empty stack!"); }
	bool empty() { if (_size == 0) return true; else return false; }
	size_t size() { return _size; }
private:
	int _curr;
	int* _data;
	size_t _size;
};

class QueueWithMax {
	//реализация очереди с поддержкой текущего минимума с помощью двух стеков
public:
	QueueWithMax(int N) : left(N),
						  left_max(N),
						  right(N),
						  right_max(N) {}
	//получить размер очереди
	int get_size() { return left.size(); }
	void push_b(int a) {
		left.push(a);
		if (!left_max.empty()) {
			if (a >= left_max.top()) left_max.push(a);
			else left_max.push(left_max.top());
		}
		else left_max.push(a);
	}
	//обработать первый элемент в очереди
	int pop_fr() {
		if (right.empty()) perekidat();
		int rez;
		rez = right.top();
		right.pop();
		right_max.pop();
		return rez;
	}
	//получить максимум
	int get_max() {
		if (left.empty()) return right_max.top();
		else if (right.empty()) return left_max.top();
		else {
			return right_max.top() > left_max.top() ? right_max.top() : left_max.top();
		}
	}

private:
	MyStack left;
	MyStack left_max;
	MyStack right;
	MyStack right_max;
	void perekidat() {
		while (!left.empty()) {
			right.push(left.top());
			if (!right_max.empty()) {
				if (left.top() >= right_max.top()) right_max.push(left.top());
				else right_max.push(right_max.top());
			}
			else right_max.push(left.top());
			left.pop();
			left_max.pop();
		}
	}
};

int main()
{
	vector<int> input_data;

	int N, n, m;

	std::cin >> N;
	QueueWithMax queueWithMax(N);
	for (int i = 0; i < N; ++i) { std::cin >> n; input_data.push_back(n); }
	/*while(std::cin >> n) {

		input_data.push_back(n);
	}*/
	std::cin >> m;

	for (int i = 0; i < m; ++i) { queueWithMax.push_b(input_data[i]); }
	cout << queueWithMax.get_max() << " ";
	for (int i = m; i < input_data.size(); ++i) {
		queueWithMax.pop_fr();
		queueWithMax.push_b(input_data[i]);
		cout << queueWithMax.get_max() << " ";
	}

	return 0;
}