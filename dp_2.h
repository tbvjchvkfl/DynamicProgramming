// DynamicProgramming - memorization

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>

// 정수의 배열  numbers에서 숫자들을 조합하여 sum이라는 값을 만들어낼 수 있는지 확인하는 함수를 만들어볼 것.

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

// 정수의 배열  numbers에서 숫자들을 조합하여 sum이라는 값을 만들어낼 수 있는 조합식을 구해볼 것.


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

// 정수의 배열  numbers에서 숫자들을 조합하여 sum이라는 값을 만들어낼 수 있는 최적의 조합식을 구해볼 것.