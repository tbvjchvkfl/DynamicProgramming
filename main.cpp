#include "dp1.h"
#include "dp_2.h"

int f(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return f(n - 1);
}

std::ostream& operator<< (std::ostream& os, std::vector<int>* v)
{
	if (v == nullptr)
	{
		std::cout << "nullptr";
	}
	else
	{
		std::cout << "{";
		for (int i = 0; i < v->size(); i++)
		{
			std::cout << (*v)[i] << ", ";

			if (i < v->size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "}";
		return os;
	}	
}

int main()
{
	/*std::cout << Fibonacci(50) << std::endl;

	std::map<int, int64_t> memo;

	std::cout << Fibonacci_memo(50, memo) << std::endl;*/

	/*std::cout << MovingPath(2, 3) << std::endl;

	std::map<std::string, int> memo;
	std::cout << FindWay(25, 25, memo) << std::endl;*/

	/*std::map<int, bool>memo;

	std::vector<int> numbers1 = { 2,3,5 };
	int sum1 = 8;

	std::cout << std::boolalpha;
	std::cout << CanAccumulate(numbers1, sum1) << std::endl;

	std::vector<int> numbers2 = { 8,6 };
	int sum2 = 7;
	std::cout << CanAccumulate(numbers2, sum2) << std::endl;

	std::cout << CanAccumulate(numbers1, sum1, memo) << std::endl;

	memo.clear();
	std::cout << CanAccumulate(numbers2, sum2, memo) << std::endl;*/

	/*std::vector<int> numbers1 = { 2,3,5 };
	int sum1 = 8;

	std::vector<int> numbers2 = { 8,6 };
	int sum2 = 7;

	std::map<int, result> memo;

	std::cout << HowAccumulatem(numbers1, sum1, memo).get() << std::endl;
	
	memo.clear();
	std::cout << OptimizeAccumulate(numbers1, sum1, memo).get() << std::endl;*/

	std::map<std::string, bool> memo;
	std::vector<std::string> v = { "ab", "abc", "cd", "def", "abcd" };
	std::cout << std::boolalpha;
	std::cout << CanGenerate(v, "abcdef", memo) << std::endl;

	std::map<std::string, int> mamo;
	std::cout << HowManyGenerate(v, "abcdef", mamo) << std::endl;
}