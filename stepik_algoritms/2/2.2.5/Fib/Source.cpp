#include <cassert>
#include <cstdint>
#include <iostream>

class Fibonacci final {
public:
	static int get_remainder(int64_t n, int m) {
		assert(n >= 1);
		assert(m >= 2);
		//int pie;
		int* F = new int[6 * m + 2];
		F[0] = 0;
		//std::cout << "  F[0] = " << F[0] << std::endl;
		F[1] = 1;
		//std::cout << "  F[1] = " << F[1] << std::endl;
		int i = 2;
		while (i) {
			//F[i] = F[i - 1] + F[i - 2]; // for 1 to 40 fib numbers
			if (i > 3 && F[i - 1] == 1 && F[i - 2] == 0) break;
			if (i > 1) F[i] = (F[i - 1] + F[i - 2]) % m; // last digit of 1 to 10^7 fib numbers
			//std::cout << "  F[" << i << "] = " << F[i] << std::endl;
			++i;
		}
		//std::cout << "i = " << i << std::endl;
		//pie = i - 2;
		//std::cout << "pie = " << pie << std::endl;
		n = F[n % (i - 2)];
		delete[] F;
		return n /*% m*/;
	}
};

int main(void) {
	int64_t n;
	int m;
	std::cin >> n >> m;
	std::cout << Fibonacci::get_remainder(n, m) << std::endl;
	return 0;
}