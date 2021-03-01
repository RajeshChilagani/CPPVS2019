#include "Inheritance.h"

int Base::s_CurrentId = 0;

void Inheritance_Main()
{
	Base* D = new Derived("asas");
	delete D;
}
