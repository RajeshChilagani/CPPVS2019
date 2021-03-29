#pragma once

#include <assert.h>
#include <type_traits>
#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
/*Array class*/
template<typename T, size_t size>
class Array
{
public:
	//Array(const Array& i_Other) :m_Data(i_Other.m_Data) {}
	constexpr int Size() const { return size; }
	T& Ptr()
	{
		return *m_Data;
	}
	const T& operator [] (size_t index) const
	{
		//assert(index < size, "Array Out of Bound");
		return m_Data[index];
	}
	T m_Data[size];
private:

};
/**/
template<typename T>
class Vector
{
public:
	Vector()
	{
		Reallocate(2);
	}
	void PushBack(const T& i_Obj)
	{
		if (m_Size >= m_Capacity)
			Reallocate(m_Capacity + m_Capacity / 2);
		m_Data[m_Size] = i_Obj;
		m_Size++;
	}
	void PushBack(T&& i_Obj)
	{
		/*if (m_Size >= m_Capacity)
			Reallocate(m_Capacity + m_Capacity / 2);
		m_Data[m_Size] = std::move(i_Obj);
		m_Size++;*/
		Emplace_Back(std::forward<T>(i_Obj));
	}
	template<typename... Args>
	T& Emplace_Back(Args&&... args)
	{
		if (m_Size >= m_Capacity)
			Reallocate(m_Capacity + m_Capacity / 2);
		new(m_Data + m_Size)T(std::forward<Args>(args)...);
		return m_Data[m_Size++];
	}
	void PopBack()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}
	~Vector()
	{
		Clear();
		::operator delete(m_Data, m_Capacity * sizeof(T));
	}

	void Clear()
	{
		for (int i = 0; i < m_Size; ++i)
			m_Data[i].~T();
		m_Size = 0;
	}
	const T& operator[](size_t index) const {
		if (index >= m_Size)
			assert("out of index excep");
		return m_Data[index];
	}

	T& operator[](size_t index) {
		if (index >= m_Size)
			assert("out of index excep");
		return m_Data[index];
	}

	size_t Size() const { return m_Size; }
private:
	void Reallocate(size_t newCapacity)
	{
		T* newBlock = (T*)::operator new (newCapacity * sizeof(T));

		if (m_Size > newCapacity)
			m_Size = newCapacity;
		for (int i = 0; i < m_Size; ++i)
		{
			newBlock[i] = std::move(m_Data[i]);
		}

		Clear();
		::operator delete(m_Data, m_Capacity*sizeof(T));
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}
	size_t m_Size=0;
	size_t m_Capacity=0;
	T* m_Data;
};