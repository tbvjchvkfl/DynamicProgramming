#pragma once
#include <iostream>
#include <vector>
#include <list>
// �־��� ���ڿ��� �迭 strings���� target ���ڿ��� ���� �� �ִ°�?
// ������ ���Ҹ� ������ ����ص� �˴ϴ�.

bool CanGenerate(const std::vector<std::string>& strings, const std::string& target)
{
	std::vector<bool> table(target.size() + 1, false);

	// base case
	table[0] = true;

	for (int i = 0; i <= target.size(); ++i)
	{
		if (table[i] == false)
		{
			continue;
		}
		for (auto e : strings)
		{
			int size = static_cast<int>(e.size());
			if (target.substr(i, size) == e)
			{
				if (i + size <= target.size())
				{
					table[i + size] = true;
				}
			}
		}
	}
	return table[target.size()];
}

int HowMabyGenerate(const std::vector<std::string>& strings, const std::string target)
{
	
}

std::list<std::list<std::string>> AllGenerate(const std::vector<std::string>& strings, std::string target)
{
	std::vector<std::list<std::list<std::string>>> table(target.size() + 1);
	
	// base case { {} }
	//table[0] = std::list<std::list<std::string>>(1, std::list<std::string>());
	table[0] = { {} };


	// iterate
	for (int i = 0; i <= target.size(); i++)
	{
		for (auto e : strings)
		{
			if (target.substr(i, e.size()) == e)
			{
				if (i + e.size() <= target.size())
				{
					for (auto e2 : table[i])
					{
						e2.push_back(e);
						table[i + e.size()].push_back(e2);
					}
				}
			}
		}
	}
}