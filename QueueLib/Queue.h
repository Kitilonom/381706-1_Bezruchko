#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

template <class T>
class _Queue {
	_Elem* head, *end; // ��������� �� ������ � ����� �������
	const unsigned max_size; // ������������ ������ �����
	unsigned now_size; // ������ ����� � ������ ������ �������

public:
	_Queue(unsigned _max_size = 0);	// ����������� �� ���������	
	~_Queue();
	void push(T elem);	// ������ ����� ���������� � �����
	T pull(); // ������� ������� � ������
	bool is_empty(); // ���� ==  true
	friend ofstream& operator<< (ofstream& ostr, _Queue& Qu); // ���������� ������

};
 

template <class T> // ����������� �� ���������	
_Queue<T>::_Queue(unsigned _max_size = 0)
{
	if (_max_size == 0) throw 1;
	head = NULL;
	end = NULL;
	max_size = _max_size;
	now_size = 0;
}

template <class T>
_Queue<T>::~_Queue()
{
	_Elem* tmp = head;
	while (tmp != NULL)
	{
		tmp->head->next; // ������ ������ ���� ������
		delete head; // �������� ������
		head = tmp; // ����� �� ���� �����
	}
}

template <class T> // ������ ����� ���������� � �����
void _Queue<T>::push(T elem)
{
	if (++now_size >= max_size) throw 2;
	_Elem* em = new _Elem;
	em->data = elem;
	em->next = NULL;
	if (head == NULL)
	{
		head = end = em;
	}
	else
	{
		end->next = em;
		end = em;
	}
}
 
template <class T> // ������� ������� � ������
T _Queue<T>::pull()
{
	if (now_size == 0) throw 3;
	T t = head->data;
	_Elem em = head;
	head = head->next;
	delete em;
	return t;
}

template <class T> // ���� ==  true
bool _Queue<T>::is_empty()
{
	if (now_size == 0)
		return true;
	return false;
}

template <class T> // ���������� ������
ofstream& operator<< (ofstream& ostr, _Queue<T>& Qu)
{
	_Elem* em = head;
	while (em != NULL)
	{
		ostr << em->data;
		em = em->next;
	}
	return ostr;
}

