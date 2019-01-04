#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

template <class T>
class _Queue {
	_Elem* head, *end; // указатели на начало и конец очереди
	const unsigned max_size; // максимальный размер стека
	unsigned now_size; // размер стека в данный момент времени

public:
	_Queue(unsigned _max_size = 0);	// конструктор по умолчанию	
	~_Queue();
	void push(T elem);	// кладем новую переменную в конец
	T pull(); // достаем элемент с начала
	bool is_empty(); // пуст ==  true
	friend ofstream& operator<< (ofstream& ostr, _Queue& Qu); // перегрузка вывода

};
 

template <class T> // конструктор по умолчанию	
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
		tmp->head->next; // запись адреса след адреса
		delete head; // удаление ячейки
		head = tmp; // сдвиг на след адрес
	}
}

template <class T> // кладем новую переменную в конец
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
 
template <class T> // достаем элемент с начала
T _Queue<T>::pull()
{
	if (now_size == 0) throw 3;
	T t = head->data;
	_Elem em = head;
	head = head->next;
	delete em;
	return t;
}

template <class T> // пуст ==  true
bool _Queue<T>::is_empty()
{
	if (now_size == 0)
		return true;
	return false;
}

template <class T> // перегрузка вывода
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

