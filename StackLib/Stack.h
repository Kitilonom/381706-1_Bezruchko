#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

#include <iomanip> // ��� setw

template <typename T>
class _Stack
{
private:
	T *stackPtr;                      // ��������� �� ����
	const int size;                   // ������������ ���������� ��������� � �����
	int top;                          // ����� �������� �������� �����
public:
	_Stack(int = 10);                  // �� ��������� ������ ����� ����� 10 ���������
	_Stack(const _Stack<T> &);          // ����������� �����������
	~_Stack();                         // ����������

	inline void push(const T &);     // ��������� ������� � ������� �����
	inline T pop();                   // ������� ������� �� ������� ����� � ������� ���
	inline void printStack();         // ����� ����� �� �����
	inline const T &Peek(int) const; // n-� ������� �� ������� �����
	inline int getStackSize() const;  // �������� ������ �����
	inline T *getPtr() const;         // �������� ��������� �� ����
	inline int getTop() const;        // �������� ����� �������� �������� � �����
};

// ���������� ������� ������� ������ STack

// ����������� �����
template <typename T>
_Stack<T>::_Stack(int maxSize) :
	size(maxSize) // ������������� ���������
{
	if (maxSize <= 0) throw - 1;
	stackPtr = new T[size]; // �������� ������ ��� ����
	top = 0; // �������������� ������� ������� �����;
}

// ����������� �����������
template <typename T>
_Stack<T>::_Stack(const _Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����� ����
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// ������� ����������� �����
template <typename T>
_Stack<T>::~_Stack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ���������� �������� � ����
template <typename T>
void _Stack<T>::push(const T &value)
{
	// ��������� ������ �����
	if (top >= size) throw - 1; // ����� �������� �������� ������ ���� ������ ������� �����

	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
T _Stack<T>::pop()
{
	// ��������� ������ �����
	if (top <= 0) throw - 1; // ����� �������� �������� ������ ���� ������ 0

	return stackPtr[--top]; // ������� ������� �� �����
}

// ������� ���������� n-� ������� �� ������� �����
template <class T>
const T &_Stack<T>::Peek(int nom) const
{
	//
	if (nom > top) throw - 1;

	return stackPtr[top - nom]; // ������� n-� ������� �����
}

// ����� ����� �� �����
template <typename T>
void _Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// ������� ������ �����
template <typename T>
int _Stack<T>::getStackSize() const
{
	return size;
}

// ������� ��������� �� ���� (��� ������������ �����������)
template <typename T>
T *_Stack<T>::getPtr() const
{
	return stackPtr;
}

// ������� ������ �����
template <typename T>
int _Stack<T>::getTop() const
{
	return top;
}