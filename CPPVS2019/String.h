#pragma once
#include <iostream>
class String
{
public:
	String():m_Name(nullptr)
	{
		
	}
	String(const char* i_Name)
	{
		size_t len = strlen(i_Name);
		char* name = new char[static_cast<size_t>(len + 1)];
		name[len] = 0;
		strcpy_s(name, len + 1, i_Name);
		m_Name = name;
	}
	String(const String& i_Other)
	{
		std::cout << "Copy" << std::endl;
		size_t len = strlen(i_Other.m_Name);
		char* name = new char[static_cast<size_t>(len + 1)];
		name[len] = 0;
		strcpy_s(name, len + 1, i_Other.m_Name);
		m_Name = name;
	}
	String(String&& i_Other) noexcept
	{
		std::cout << "Move" << std::endl;
		if (this != &i_Other)
		{
			m_Name = i_Other.m_Name;
			i_Other.m_Name = nullptr;
		}

	}

	String& operator=(const String& i_Other) noexcept
	{
		std::cout << "Copy Assih=gn" << std::endl;
		size_t len = strlen(i_Other.m_Name);
		char* name = new char[static_cast<size_t>(len + 1)];
		name[len] = 0;
		strcpy_s(name, len + 1, i_Other.m_Name);
		delete m_Name;
		m_Name = name;
		return *this;

	}

	String& operator=(String&& i_Other) noexcept
	{
		std::cout << "Move" << std::endl;
		if (this != &i_Other)
		{
			delete m_Name;
			m_Name = i_Other.m_Name;
			i_Other.m_Name = nullptr;
		}
		return *this;
	}
	~String()
	{
		std::cout << "String Destructor" << std::endl;
		if (m_Name)
		{
			delete m_Name;
		}
	}
	void Print()
	{
		std::cout << m_Name;
	}
	friend std::ostream& operator<<(std::ostream& os, const String& i_Test);
private:
	const char* m_Name;
};


inline std::ostream& operator<<(std::ostream& os, const String& i_Test)
{
	std::cout << i_Test.m_Name << std::endl;
	return os;
}