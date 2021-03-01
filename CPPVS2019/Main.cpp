#include "Main.h"

#include <assert.h>

#include <type_traits>
#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include <CPPVS2019/DataStructures.h>
#include "Helpers.h"
#include "Learnings.h"
#include "String.h"
#include "Templates.h"


String&& CreateString(const char* i_Name)
{
	static String&&  ref= String(i_Name);
	return std::move(ref);
}
// Test is a friend of Base & Derived Classes and can access their Private data. If Test is only friends with Base it cannot access Derived's Private members
//Test also conatins example for binding member function
class Test
{
public:
	Test() :m_data(0){}
	Test(int i_data) :m_data(i_data) {}
	auto Bind()
	{
		return std::bind(&Test::PrintBase, this, std::placeholders::_1);
	}
	void PrintBase(const Derived& i_Base) 
	{
		std::cout << i_Base.m_Id<<i_Base.m_Name;
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
class Entity
{
public:
	Entity(String& i_Name) :m_Name(i_Name) {}
	Entity(String&& i_Name) :m_Name(i_Name) {}
	auto Binder()
	{
		return std::bind(&Entity::Print, this);
	}
	void Print()
	{
		std::cout << m_Name << std::endl;
	}
	String GetName() const { 
		return m_Name; }
private:
	String m_Name;
};

/*Test Class for Implicit calls*/
class Float
{
	int m_Data;
	float m_Data1;
public:
	//Float() {}                                    //No initialization in vs 2019 compiler also notifies it - this might not be helpful 
	//Float() = default;
	Float(int a) :m_Data(a), m_Data1(1.0f){}
	//weird but a way to use initializer list
	Float(const std::initializer_list<int> l)
	{
		m_Data = *(l.begin());
		m_Data1 = *(l.begin()+1);
	}
	operator float() { return m_Data1; }
	//operator int*() { return &m_Data; }
	bool operator==(const Float& i_Rhs) const
	{
		std::cout << "Overload Equal" << std::endl;
		return m_Data == i_Rhs.m_Data && m_Data1 == i_Rhs.m_Data1;
	}
	void operator()()                                         //Overload  of () operator can be customized as you wish (any no of params/no params)
	{
		std::cout << "Overload () operator for Float" << std::endl;
	}
};

class BigFloat
{
public:
	//BigFloat() = default;
	BigFloat():m_Data(12)
	{
	
		std::cout << "Constructor" << std::endl;
	}                                   //Dirrect List Initialisation sets the values passed/ sets to default if nothing is passed
	//BigFloat(Float i_Data) :m_Data(i_Data) {}
	void Print()
	{
		std::cout << "Print IN BigFloat" << std::endl;
	}
	~BigFloat()
	{
		std::cout << "BigFloat Destructot" << std::endl;
	}
private:
	Float m_Data = Float(1);
};
/**/
template<typename T>
void ForTemp(T&& input)
{
	std::cout << input;
}
/*Forwarding & template argument deduction*/
void PrintAllIntF(BigFloat&& i1)
{
	i1.Print();
}
void PrintAllIntF(int i1)
{
	std::cout << i1;
}
template<typename... T>
void PrintAll(T&&... args)
{
	std::cout << std::is_lvalue_reference<T...>::value << std::endl;
	std::cout << std::is_rvalue_reference<T...>::value << std::endl;
	PrintAllIntF(std::forward<T>(args)...);
}

#define CreateFuncByName(name) void has##name(){std::cout<<"NewFunc From Macro";}
CreateFuncByName(Hurrah)

template<typename T>
void TestF(T value) {}
/**/
struct Vertex
{
	float x = 0.0f, y = 0.0f, z = 0.0f;
	Vertex() = default;
	~Vertex()
	{
		std::cout << "Destructor Vertex" << std::endl;
	}
	Vertex& operator++()
	{
		++x;
		++y;
		++z;
		return *this;
	}
	Vertex(float i_x, float i_y, float i_z)
	{}
};

struct TestSize
{
	//Vertex m_Vertex;
	BigFloat m_BigFloat;
};
std::ostream& operator<<(std::ostream& os, const Vertex& Vertex)
{
	os << Vertex.x << ',' << Vertex.y << ',' << Vertex.z;
	return os;
}
class Tests
{
public:
	struct Itr
	{
		int a;
	}itr;
	
};
namespace {
	extern float FMain;
}

constexpr float Result(float i_A, float i_B)
{
	return i_A * i_B;
}

class Comparator
{
public:
	static bool Compare(int a, int b)
	{
		return a == b;
	}

	static bool Compare(std::string a, std::string b)
	{
		return a == b;
	}

	static bool Compare(const std::vector<int>& a, const std::vector<int>& b)
	{
		if (a.size() != b.size())
			return false;
		return a == b;
	}
};

struct Ftest
{
	int a;
	float b;
	/*Ftest(int i_a):a(i_a)
	{
		b = i_a;
		this->a += i_a;
		std::cout << "Constructor" << std::endl;
	}*/
};

struct Point
{
	float x, y;
};

template<typename T>
void PrintTemplate(const T& value)
{
	std::cout << value<<std::endl;
}

template<typename... Args>
void Fin(const Args&... mArgs)
{
	int a[] = {0,(PrintTemplate(mArgs),0)... };
}
struct TagComponent
{
	std::string Name;
	TagComponent() = default;
	TagComponent(const std::string& i_Name)
		:Name(i_Name)
	{}
	TagComponent(const TagComponent& i_Other)
		:Name(i_Other.Name)
	{}
	TagComponent(TagComponent&& i_Other) noexcept
		:Name(std::move(i_Other.Name))
	{
		std::cout << "Move Constructor" << std::endl;
	}
};


bool IsStringNUmeric(const std::string& String)
{
	if (String[String.size() - 1] == '-')
		return false;
	bool isNegativeFound = false;
	for (auto c : String)
	{
		if (c == '-')
		{
			isNegativeFound = true;
			continue;
		}
		if (c >= 48 && c<=58)
		{
			if (isNegativeFound )
			{
				if (c == 48)
				{
					return false;
				}
				isNegativeFound = false;
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}
class Camera
{
public:
	float FOV;
	float GetFOV() const { return FOV; }
	void SetFOV(float i_FOV)
	{
		FOV = i_FOV;
	}
};
class tes
{
public:
	bool operator<(Camera* value)
	{
		return true;
	}
};
int main()
{
	void* Null = nullptr;
	Camera C1;
	if (Null < &C1)
	{
		std::cout << "Test";
	}
	std::cout << typeid(&C1).name() << std::endl;
	auto Fn = std::bind(&Camera::SetFOV,&C1,std::placeholders::_1);
	Fn(1.f,4,6,78);
	std::cout << IsStringNUmeric("012392-");
	std::vector<TagComponent> Tags;
	TagComponent TestTag;
	TestTag.Name = "TestTag";
	Tags.push_back(std::move(TestTag));
	Fin(1, "test");
	float f1 = 1; 
	int* ii1 = (int*)(&f1);
	std::cout << *ii1;
	Ftest AF{};
	std::cout << Result(2, 3);
	float Left, Right;
	std::cin >> Left >> Right;
	std::cout << Result(Left, Right);
	int data = 4;
	const auto tes = [data] { int MF = 35; return MF; }();
	//std::cout << FMain;
	BigFloat bf;
	Vertex V;
	{
		TestSize T;                 //Constructors of members are callled in the order of declaration and destructoers are called in reverse order of declaration
	}
	std::vector<Vertex> Vertices(2);
	std::vector<Vertex>::iterator it = Vertices.begin();
	Vertices.push_back(V);
	it = Vertices.begin();
	std::cout <<1<< ',';
	{
		Vector<String> vStrs;
		vStrs.PushBack(String("test1"));
		vStrs.Emplace_Back("test2");
	}
#if 1
	TestF(1);
	int i1 = 2;
	PrintAll(2);
	std::function<void()> fStd = [=]() {
		std::cout <<"This is a Lambda"<< i1;
	};
	Float&& fVarRef = {1};
	Float* ptr = &fVarRef;
	ForTemp(fVarRef);
	std::vector<int> IntVector{1,2,3};
	Derived* d1 = new Derived("d1");
	Base* b1=new Base();
	Derived* d2 = (Derived*)b1;
	d2->PrintDer();                            //illegal because base is not derived and might not contain func of derived
    //std::cout<<d2->m_Array[0];
	int row = 2, col = 2;
	int* rows = (int*)malloc(sizeof(int) * col);
	int** mat = (int**)malloc(sizeof(size_t) * row);
	for (int i = 0; i < row; ++i)
	{
		mat[i] = rows + i;
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			mat[i][j] = 2;
			std::cout << mat[i][j];
		}
		std::cout << std::endl;
	}
	free(mat);
	const int size = 2;
	int array[size];
	const Array<int, 5> Ints;
	Ints[3];
	Base* tB = new Derived("Tes");
	tB->callPrivate();
	Derived Dd("sdsd");
	Dd.callPrivate();
	DerivedDerived obj;
	obj.Print();
	Base* b = &obj;
	b->PrintInt(1);
	Derived* D = new Derived("Killua");
	Test test(23);
	std::function<void(const Derived&)> f = test.Bind();
	f(*D);
	BindExampleTest(test.Bind());
	String Test("etsts");
	Inheritance_Main();
	Templates_Main();
	Generic<int>A(1);
	A.PrintSize();
	Generic<float>B(1.0f);
	A += B;
	std::cout << A;
#endif
	_CrtDumpMemoryLeaks();
}