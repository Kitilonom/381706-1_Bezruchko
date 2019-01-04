#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

// ���� ����������� �� ����������� ������. �������� :)
// ��������� ���� - LIFO (����. last in � first out, ���������� ������ � ������ �����).

template <class T>
class _Stack {
	_Elem* top;		// ��������� �� �������
	const unsigned max_size; // ������������ ������ �����
	unsigned now_size; // ������ ����� � ������ ������ �������

public:
	_Stack(unsigned _max_size = 0);	// ����������� �� ���������	
	//_Stack(_Stack<T> &S); // ����������� �����������
	void push(T elem);	// ������ ����� ���������� � ����
	T pull(); // ������� ������� � ��������
	bool is_empty(); // ���� ==  true
	friend ofstream& operator<< (ofstream& ostr, _Stack& St); // ���������� ������
};

template <class T> // ����������� �� ���������	
_Stack<T>::_Stack(unsigned _max_size = 0)
{
	if (_max_size == 0) throw 1;
	top = NULL;
	max_size = _max_size;
	now_size = 0;
}

//template <class T> // ����������� �����������
//_Stack<T>::_Stack(_Stack<T>& St)
//{
//	max_size = St.max_size;
//	now_size = St.now_size;
//	if (now_size == 0)
//		top = NULL;
//	else 
//	{
//		_Elem* em = 
//		for (int i = 0; i < now_size; i++)
//		{
//
//		}
//	}
//}

template <class T> // ������ ����� ���������� � ����
void _Stack<T>::push(T elem)
{
	if (++now_size > max_size) throw 2;
	_Elem *em = mew _Elem(); // ������� ������
	em->data = elem; // ���������� ���������� � ������
	if (now_size == 1) // ���� ���� ���� ���, ��
		*top = em; // �������� ����� ���� ������ �����
	else // ����� 
	{
		em->next = *top; // ������ ��������� ����� ������ �������� ����� ������ �������
		*top = em; // � �������� - ��� �������
	}
}

template <class T> // ������� ������� � ��������
T _Stack<T>::pull()
{
	if (now_size == 0) throw 3;	// ���� ����, �� ������ ���-�� �����
	_Elem* tmp = *top; // ��������� �� ��������� ����� �������
	*top = top->next; // ������ �� ������� ���������
	delete tmp; // ������� ������ �������
	now_size--; // ��������� ������ �� �������
}

template <class T> // ���� ==  true
bool _Stack<T>::is_empty()
{
	if (now_size == 0) true;
	return false;
}

template <class T> // ���������� ������
ofstream& operator<< (ofstream& ostr, _Stack<T>& St)
{
	_Elem* em = St.top;
	while (em)
	{
		ostr << em->data;
		em = em->next;
	}
	return ostr;
}