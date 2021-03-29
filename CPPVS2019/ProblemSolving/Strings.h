#pragma once
#include <string>
inline void ReverseString(const char* i_Char)
{
	int begin = 0, end = std::strlen(i_Char)-1;
	uint8_t* DataPtr = (uint8_t*)(i_Char);
	while (begin < end)
	{
		std::swap(DataPtr[begin++], DataPtr[end--]);
	}
}

bool Strcmp(const char* left, const char* right)
{
	while (*left == *right && *left++ | *right++);
	return *left - *right ? false : true;
}