#pragma once
#include <functional>
#include "Inheritance.h"
void LearningsMain()
{
	/*East Const and the unique const alias */
	using MyFloatPtr = float*;
	const float cFloat = 2.0f;               //constant float
	const float* ptrCFloat = &cFloat;        //pointer to a const float 
	//*ptrCFloat = 3.0f; is illegal but
	float test = 1;
	const MyFloatPtr aliasFPtr = const_cast<float*>(&cFloat);  // here it is not a pointer const float it is const pointer to float
	*aliasFPtr = 25; //aliasFPtr = nullptr;-> exp must be an modifiable lvalue
	MyFloatPtr const constPtralias = const_cast<float*>(&cFloat);
	*constPtralias = 25; //constPtralias = nullptr;    //-> exp must be an modifiable lvalue 
	/**/
}

// Test is a friend of Base & Derived Classes and can access their Private data. If Test is only friends with Base it cannot access Derived's Private members
//Test also conatins example for binding member function
class Test
{
public:
	Test() :m_data(0) {}
	Test(int i_data) :m_data(i_data) {}
	auto Bind()
	{
		return std::bind(&Test::PrintBase, this, std::placeholders::_1);
	}
	void PrintBase(const Derived& i_Base)
	{
		std::cout << i_Base.m_Id << i_Base.m_Name;
		i_Base.Print();
		i_Base.PrintProt();
	}
private:
	int m_data;
	friend std::ostream& operator<<(std::ostream& os, const Test& obj);
};
std::ostream& operator<<(std::ostream& os, const Test& obj)
{
	os << obj.m_data << std::endl;
	return os;
}
template<typename F>
void BindExampleTest(const F& func)
{
	Derived D("BindExampleTest");
	func(D);
}
void FreeFunction(const Derived& D)
{
	std::cout << "FreeFunction" << std::endl;
	D.Print();
}
//Test Class

//class Entity
//{
//public:
//	Entity(String& i_Name) :m_Name(i_Name) {}
//	Entity(String&& i_Name) :m_Name(i_Name) {}
//	auto Binder()
//	{
//		return std::bind(&Entity::Print, this);
//	}
//	void Print()
//	{
//		std::cout << m_Name << std::endl;
//	}
//	String GetName() const {
//		return m_Name;
//	}
//private:
//	String m_Name;
//};