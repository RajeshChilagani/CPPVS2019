#pragma once
#include <iostream>
#include <unordered_map>
int GetNthFibNumber(int n, std::unordered_map<int, int> MemoryMap)
{
	if (n == 1 || n == 2)
		return 1;
	if (MemoryMap.find(n) != MemoryMap.end())
	{
		return MemoryMap[n];
	}
	else
	{
		int val = GetNthFibNumber(n - 1, MemoryMap) + GetNthFibNumber(n - 2, MemoryMap);
		MemoryMap.emplace(n, val);
		return val;
	}
}