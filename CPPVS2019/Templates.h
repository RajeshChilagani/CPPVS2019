#pragma once
#include <iostream>
#include <type_traits>
inline void Print2Ints(int i_a, int i_b)
{
	std::cout <<"Printing 2 ints "<< i_a << i_b << std::endl;
}
// above normal function shadows the templated versrion
template<typename T>
void Print2Ints(T i_a, T i_b)
{
	std::cout <<"Printing 2 ints from templated "<< i_a << i_b << std::endl;
}
template<>                                  //explicit(full) template specialization * remove inline and you get linker errors
inline void Print2Ints<int>(int i_a, int i_b)
{
	std::cout << "Printing 2 ints " << i_a << i_b << std::endl;
}
template<typename ... Args>
void Print(const Args& ... mArgs)
{
	if (sizeof...(mArgs) == 2)
	{
		Print2Ints(mArgs...);
	}
}
/*Genericeric Template Class*/
template<typename T>
class Generic
{
	template<typename U>
	friend class Generic;
	template<typename T>
	friend std::ostream& operator<<(std::ostream& os, const Generic<T>& IData);
public:
	Generic(T i_Data) :m_Data(i_Data) {}
	template<typename U>
	Generic& operator+=(const Generic<U>& i_Other)
	{
		m_Data += i_Other.m_Data;
		return *this;
	}
	void PrintSize()
	{
		std::cout <<"Size of Generic is: "<< sizeof(T) << std::endl;
	}
	
private:
	T m_Data;
};
template<typename T>
std::ostream& operator<<(std::ostream& os, const Generic<T>& IData)
{
	std::cout <<"Template Ostream Overload"<< IData.m_Data<<std::endl;
	return os;
}
/**/