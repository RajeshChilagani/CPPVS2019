#pragma once
#include <vector>

void MoveZeroes(std::vector<int>& Nums)
{
	for (int i = 0; i < Nums.size(); ++i)
	{
		if (Nums[i] == 0)
		{
			int j = i+1;
			while (j<Nums.size())
			{
				if (Nums[j] != 0)
				{
					std::swap(Nums[i], Nums[j]);
					break;
				}
				++j;
			}
		}
	}
}