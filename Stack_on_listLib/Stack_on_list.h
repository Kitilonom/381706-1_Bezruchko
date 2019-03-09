#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

template <class T>
class Stack_on_list
{
private:
	T * arr;
	int size, len;
	void new_size(int s)
	{
		if (s <= 0) return;
		T * new_arr = new T[s];
		int min_s = s < len ? s : len;
		for (int i = 0; i < min_s; i++) new_arr[i] = arr[i];
		delete[] arr;
		size = s;
		arr = new_arr;
	}

public:
	Stack_on_list()
	{
		len = 0;
		arr = new T[size = 5];
	}

	Stack_on_list(Stack_on_list & st)
	{
		arr = new T[size = st.size];
		len = st.len;
		for (int i = 0; i < len; i++) arr[i] = st.arr[i];
	}

	~Stack_on_list()
	{
		delete[] arr;
	}

	int Size()
	{
		return len;
	}

	void Push(T & x)
	{
		if (len == size) new_size(size << 1);
		arr[len++] = x;
	}
	T Pop()
	{
		if (size > 10 && len < size >> 2) new_size(size >> 1);
		if (len == 0) return arr[len];
		return arr[--len];
	}
	T Top()
	{
		return arr[len];
	}
	void Clear()
	{
		delete arr;
		len = 0;
		arr = new T[size = 5];
	}

	bool IsEmpty()
	{
		return len == 0;
	}

	Stack_on_list<T> & operator = (Stack_on_list<T> st)
	{
		delete[] arr;
		arr = new T[size = st.size];
		len = st.len;
		for (int i = 0; i < len; i++) arr[i] = st.arr[i];
		return *this;
	}
	bool operator == (Stack_on_list<T> & st)
	{
		if (len != st.len) return false;
		for (int i = 0; i < len; i++) if (arr[i] != st.arr[i]) return false;
		return true;
	}
};
