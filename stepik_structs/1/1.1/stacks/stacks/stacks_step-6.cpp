#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class QueueWithMin {
	//реализация очереди с поддержкой текущего минимума с помощью двух стеков
public:
	//получить размер очереди
	int get_size() { return left.size(); }
	void push_b(int a) {
		left.push(a);
		if (!left_min.empty()) {
			if (a >= left_min.top()) left_min.push(a);
			else left_min.push(left_min.top());
		}
		else left_min.push(a);
	}
	//обработать первый элемент в очереди
	int pop_fr() {
		if (right.empty()) perekidat();
		int rez;
		rez = right.top();
		right.pop();
		right_min.pop();
		return rez;
	}
	//получить максимум
	int get_min() {
		if (left.empty()) return right_min.top();
		else if (right.empty()) return left_min.top();
		else {
			return right_min.top() > left_min.top() ? right_min.top() : left_min.top();
		}
	}

private:
	stack<int> left;
	stack<int> left_min;
	stack <int> right;
	stack <int> right_min;
	void perekidat() {
		while (!left.empty()) {
			right.push(left.top());
			if (!right_min.empty()) {
				if (left.top() >= right_min.top()) right_min.push(left.top());
				else right_min.push(right_min.top());
			}
			else right_min.push(left.top());
			left.pop();
			left_min.pop();
		}
	}
};

int main()
{
	vector<int> input_data;
	QueueWithMin queueWithMin;
	int N, n, m;

	cin >> N;
	while (cin >> n) {
		//if (n == endl) break;
		input_data.push_back(n);
	}
	cin >> m;

	for (int i = 0; i < m; ++i) { queueWithMin.push_b(input_data[i]); }
	cout << queueWithMin.get_min() << " ";
	for (int i = m; i < input_data.size(); ++i) {
		queueWithMin.pop_fr();
		queueWithMin.push_b(input_data[i]);
		cout << queueWithMin.get_min() << " ";
	}

	return 0;
}