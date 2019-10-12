#include <iostream>
#include <vector>

int main(void) {
	int n = 0;
	std::vector<int> v;
	std::cin >> n;
	for (int i = 1; i <= n; n -= i, ++i)
		v.push_back(n - i > i ? i : n);

	std::cout << v.size() << std::endl;
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	return 0;
}