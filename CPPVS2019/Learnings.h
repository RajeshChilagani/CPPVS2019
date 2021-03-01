#pragma once
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