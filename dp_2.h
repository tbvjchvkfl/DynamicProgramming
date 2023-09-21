// DynamicProgramming - memorization

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <list>

// ������ �迭  numbers���� ���ڵ��� �����Ͽ� sum�̶�� ���� ���� �� �ִ��� Ȯ���ϴ� �Լ��� ���� ��.

bool Combination(std::vector<int> numbers, int sum)
{
	for (auto& e : numbers)
	{
		for (auto& l : numbers)
		{
			if (numbers[e] + numbers[l] == sum)
			{
				return true;
			}
		}
	}
	return false;
}

// Brute Force
bool CanAccumulate(std::vector<int>& numbers, int sum)
{
	// base case
	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	// recursive
	for (auto e : numbers)
	{
		if (CanAccumulate(numbers, sum - e))
		{
			return true;
		}
	}
	return false;
}

// Memoization
bool CanAccumulate(const std::vector<int>& numbers, int sum, std::map<int, bool>& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}

	// base case
	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	// recursive
	for (auto e : numbers)
	{
		if (CanAccumulate(numbers, sum - e, memo))
		{
			memo[sum] = true;
			return true;
		}
	}
	memo[sum] = false;
	return false;
}


////////////////////////////////////////////

// ������ �迭  numbers���� ���ڵ��� �����Ͽ� sum�̶�� ���� ���� �� �ִ� ���ս��� ���غ� ��.


// brute force
using result = std::shared_ptr<std::vector<int>>;

result HowAccumulateb(const std::vector<int>& numbers, int sum, std::map<int, result>& memo)
{
	// base case
	if (sum == 0)
	{
		return std::make_shared<std::vector<int>>();
	}
	if (sum < 0)
	{
		return nullptr;
	}

	// recursive case
	for (const auto e : numbers)
	{
		auto r = HowAccumulateb(numbers, sum, memo);
		if (r != nullptr)
		{
			r->push_back(e);
			return r;
		}
	}
	return nullptr;
}

// Memoization

using result = std::shared_ptr<std::vector<int>>;
result HowAccumulatem(const std::vector<int>& numbers, int sum, std::map<int, result>& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}

	// base case
	if (sum == 0)
	{
		return std::make_shared<std::vector<int>>();
	}
	if (sum < 0)
	{
		return nullptr;
	}

	// recursive case
	for (const auto e : numbers)
	{
		auto r = HowAccumulatem(numbers, sum - e, memo);
		if (r != nullptr)
		{
			r->push_back(e);
			memo[sum] = r;
			return memo[sum];
		}
	}
	memo[sum] = nullptr;
	return memo[sum];
}

// ������ �迭  numbers���� ���ڵ��� �����Ͽ� sum�̶�� ���� ���� �� �ִ� ������ ���ս��� ���غ� ��.
result OptimizeAccumulate(const std::vector<int>& numbers, int sum, std::map<int, result>& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}

	// base case
	if (sum == 0)
	{
		return std::make_shared<std::vector<int>>();
	}
	if (sum < 0)
	{
		return nullptr;
	}

	// recursive case
	std::shared_ptr<std::vector<int>> optimized = nullptr;
	for (const auto e : numbers)
	{
		auto r = OptimizeAccumulate(numbers, sum - e, memo);
		if (r != nullptr)
		{
			std::shared_ptr<std::vector<int>> v = std::make_shared<std::vector<int>>();
			v->resize(r->size());
			std::copy(r->begin(), r->end(), v->begin());
			r->push_back(e);

			if (optimized == nullptr || v->size() < optimized->size())
			{
				optimized = v;
			}
		}
	}
	memo[sum] = optimized;
}

// õ���� ���� ������ 720�� �����ϰ� �ܵ����� �Ž��� �� �ּ� ����(���� ���� ������ ����)�� ������ ��ϱ��?

// �־��� ���ڿ��� �迭 stringList�� ���ҵ��� �����Ͽ� target���ڿ��� ���� �� �ִ��� ���غ���.
bool CanGenerate(std::vector<std::string>& strings, std::string target, std::map<std::string, bool>& memo)
{
	if (memo.count(target) == 1)
	{
		return memo[target];
	}
	// base case
	if (target.empty())
	{
		return true;
	}
	// recursive case
	for (auto e : strings)
	{
		if (target.find(e) == 0)
		{
			if (CanGenerate(strings, target.substr(e.size()), memo))
			{
				memo[target] = true;
				return memo[target];
			}
		}
	}
	memo[target] = false;
	return memo[target];
}

//Combination ver - brute force
int HowManyGenerate(const std::vector<std::string>& strings, std::string target)
{
	if (target == "")
	{
		return 1;
	}
	int count{};
	for (auto e : strings)
	{
		if (target.find(e) == 0)
		{
			std::string subs = target.substr(e.size());
			count += HowManyGenerate(strings, subs);
		}
	}
	return count;
}

//Combination ver - memoization
int HowManyGenerate(const std::vector<std::string>& strings, std::string target, std::map<std::string, int>& memo)
{
	if (memo.count(target) == 1)
	{
		return memo[target];
	}

	if (target == "")
	{
		return 1;
	}
	int count{};
	for (auto e : strings)
	{
		if (target.find(e) == 0)
		{
			std::string subs = target.substr(e.size());
			count += HowManyGenerate(strings, subs, memo);
		}
	}
	memo[target] = count;
	return memo[target];
}

using string2d = std::list<std::list<std::string>>;
string2d AllCombination(const std::vector<std::string>& strings, std::string target)
{
	if (target == "")
	{
		return string2d{ {} };
	}

	string2d v;

	for (auto word : strings)
	{
		if (target.find(word) == 0)
		{
			auto r = AllCombination(strings, target.substr(word.size()));
			for (auto s : r)
			{
				s.push_front(word);
				v.push_front(s);
			}
		}
	}
	return v;
}

std::ostream& operator<< (std::ostream& os, string2d& v)
{
	std::cout << "{";
	for (auto e1 : v)
	{
		std::cout << "    {";
		for (auto e2 : e1)
		{
			std::cout << e2 << ", ";
		}
		std::cout << "}" << std::endl;
	}
	std::cout << "}";
	return os;
}