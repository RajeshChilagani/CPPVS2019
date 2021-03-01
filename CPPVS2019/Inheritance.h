#pragma once
#include <iostream>
class Derived;
class Base
{
	
public:
	friend class Test;
	Base() :m_Id(++s_CurrentId)
	{
		std::cout << "Base Constructor" << std::endl;
	}
	//Base(const Base& i_Other) = delete;
	virtual void Print() const 
	{
		std::cout << "Base Print" << std::endl;
	}
	virtual void PrintInt(int i) const
	{
		std::cout << "Printing from Base INTEGER :" << i << std::endl;
	}
	void callPrivate() 
	{
		PrintPrivate();
	}
	virtual ~Base()
	{
		std::cout << "Base Destructor" << std::endl;
	}
protected:
	void PrintProt() const
	{
		std::cout << "Pro" << std::endl;
	}
private:
	virtual void PrintPrivate()                   // a private pure virtual function
	{
		std::cout << "Virtual Private in Base" << std::endl;
	}
	static int s_CurrentId;
	int m_Id;
};
class Derived : public Base
{
	friend class Test;
public:
	Derived(const std::string& i_Name="Derived") :m_Name(i_Name)
	{
		std::cout << "Derived Constructor" << std::endl;
	}
	void Print() const override
	{
		std::cout << "Derived Print" << std::endl;
	}
	void PrintDer()
	{
		std::cout << "Name:" <<m_Name<< std::endl;
	}
	~Derived()
	{
		std::cout << "Derived Destructor" << std::endl;
	}
	int* m_Array;
private:
	void PrintPrivate() override                                      //overiding a private virtual function
	{
		std::cout << "Virtual Private in Derived" << std::endl;
	}
	std::string m_Name;
};
class DerivedDerived : public Derived
{
public:
	DerivedDerived(uint32_t i_Category=0):m_Cateogry(i_Category) 
	{
		std::cout << "Derived Derived Constructor" << std::endl;
	}
	void Print() const override
	{
		std::cout << "DerivedDerived Print" << std::endl;
	}
	/*void PrintInt(int i) override
	{
		std::cout << "Printing from Derived Derived INTEGER :" << i << std::endl;
	}*/
	~DerivedDerived()
	{
		std::cout << "Derived Derived Destructor" << std::endl;
	}
private:
	uint32_t m_Cateogry;
};