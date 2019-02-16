#pragma once
#include <iostream>
#include <stack>
#include "ost.h"

using namespace std;

template <class T>
class Multistack {
	stack<T>* st;
	int n;
	int maxsize;
	int count;
public:
	Multistack(int _n = 0, int _size = 0);
	
	int getsize();
	int getn();

	T pull(int _n);
	void push(T  elem, int _n);

	bool IsEmpty();
};

template<class T>
inline Multistack<T>::Multistack(int _n, int _size)
{
	if (_n <= 0) throw - 1;
	if (_size <= 0) throw - 1;
	n = _n;
	maxsize = _size;
	st = new stack<T>[n];
	count = 0;
}

template<class T>
inline int Multistack<T>::getsize()
{
	return maxsize;
}

template<class T>
inline int Multistack<T>::getn()
{
	return n;
}

template<class T>
inline T Multistack<T>::pull(int _n)
{
	return st[_n]->push();
}

template<class T>
inline void Multistack<T>::push(T elem, int _n)
{
	st[_n]->push(elem);
}