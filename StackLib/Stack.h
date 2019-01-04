#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

// стек представлен на односвязном списке. простите :)
// структура СТЕК - LIFO (англ. last in — first out, «последним пришёл — первым вышел»).

template <class T>
class _Stack {
	_Elem* top;		// указатель на вершину
	const unsigned max_size; // максимальный размер стека
	unsigned now_size; // размер стека в данный момент времени

public:
	_Stack(unsigned _max_size = 0);	// конструктор по умолчанию	
	//_Stack(_Stack<T> &S); // конструктор копирования
	void push(T elem);	// кладем новую переменную в стек
	T pull(); // достаем элемент с вершиины
	bool is_empty(); // пуст ==  true
	friend ofstream& operator<< (ofstream& ostr, _Stack& St); // перегрузка вывода
};

template <class T> // конструктор по умолчанию	
_Stack<T>::_Stack(unsigned _max_size = 0)
{
	if (_max_size == 0) throw 1;
	top = NULL;
	max_size = _max_size;
	now_size = 0;
}

//template <class T> // конструктор копирования
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

template <class T> // кладем новую переменную в стек
void _Stack<T>::push(T elem)
{
	if (++now_size > max_size) throw 2;
	_Elem *em = mew _Elem(); // создаем ячейку
	em->data = elem; // записываем переменную в ячейку
	if (now_size == 1) // если стек пуст был, то
		*top = em; // вершиной будет наша ячейка новая
	else // иначе 
	{
		em->next = *top; // теперь следующий после нашего элемента будет бывшая вершина
		*top = em; // а вершиной - наш элемент
	}
}

template <class T> // достаем элемент с вершиины
T _Stack<T>::pull()
{
	if (now_size == 0) throw 3;	// если пуст, то нельзя что-то взять
	_Elem* tmp = *top; // сохраняем во временную адрес вершины
	*top = top->next; // ставим на вершину следующую
	delete tmp; // удаляем бывшую вершину
	now_size--; // уменьшаем размер на единицу
}

template <class T> // пуст ==  true
bool _Stack<T>::is_empty()
{
	if (now_size == 0) true;
	return false;
}

template <class T> // перегрузка вывода
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