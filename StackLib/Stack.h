#pragma once
#include <iostream>

// стек представлен на односв€зном списке. простите :)
// структура —“≈  - LIFO (англ. last in Ч first out, Ђпоследним пришЄл Ч первым вышелї).

template <class T>
struct _Elem {
	T data; // значение €чейки
	_Elem* next; // указатель на следующую €чейку
};

template <class T>
class _Stack {
	_Elem* top;		// указатель на вершину
	const unsigned max_size; // максимальный размер стека
	unsigned now_size; // размер стека в данный момент времени

public:
	_Stack(unsigned _max_size = 0);	// конструктор по умолчанию	
	//_Stack(_Stack<T> &S); // конструктор копировани€
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

//template <class T> // конструктор копировани€
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
	_Elem *em = mew _Elem(); // создаем €чейку
	em->data = elem; // записываем переменную в €чейку
	if (now_size == 1) // если стек пуст был, то
		*top = em; // вершиной будет наша €чейка нова€
	else // иначе 
	{
		em->next = *top; // теперь следующий после нашего элемента будет бывша€ вершина
		*top = em; // а вершиной - наш элемент
	}
}

template <class T> // достаем элемент с вершиины
T _Stack<T>::pull()
{
	if (now_size == 0) throw 3;	// если пуст, то нельз€ что-то вз€ть
	_Elem* tmp = *top; // сохран€ем во временную адрес вершины
	*top = top->next; // ставим на вершину следующую
	delete tmp; // удал€ем бывшую вершину
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