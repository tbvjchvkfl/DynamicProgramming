#include "dp1.h"

int f(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return f(n - 1);
}

int main()
{
	/*std::cout << Fibonacci(50) << std::endl;

	std::map<int, int64_t> memo;

	std::cout << Fibonacci_memo(50, memo) << std::endl;*/

	std::cout << MovingPath(2, 3) << std::endl;
}