#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class QueueWithMax {
	//реализация очереди с поддержкой текущего минимума с помощью двух стеков
	public:
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
		stack<int> left; 
		stack<int> left_max;
		stack <int> right;
		stack <int> right_max;
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
	QueueWithMax queueWithMax;
	int N, n, m;

	std::cin >> N;
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