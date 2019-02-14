#pragma once
#include <iostream>
#include "ost.h"
#include <queue>

using namespace std;

template <class T>
class List_on_array
{
	T* Elems; // массив данных
	int* nextElem; // массив индексов следующего элемента
	int* predElem; // на предыдущий
	queue<int> freeMesto; // очередь пустых ячеек
	int size_List; // размер
	int start; // начало  
	int end; // конец
	int count_Elem; // количество элементов
public:
	List_on_array(int _size_List = 0); // конструктор под размерчик
	List_on_array(List_on_array<T> &L); // конструктор копирования
	~List_on_array(); // деструктор

	void push(int n, T elem); // положить куда-то
	void pushStart(T elem); // положить в начало
	void pushEnd(T elem); // положить в конец
	T pull(int n); // взять произвольный
	T pullStart(int n); // взять первый
	T pullEnd(int n); // взять последний

	bool IsEmpty(); // если пустой, то true

	friend ostream& operator<< (ostream& os, List_on_array<T> L); // вывод
};

// конструктор
template<class T>
inline List_on_array<T>::List_on_array(int _size_List)
{
	if (_size_List <= 0) throw -1; // ошибка, если размер меньше или равен 0
	size_List = _size_List; // размер в размер
	count_Elem = 0; // сейчас оно пустое
	start = -1; // начала нет
	end = -1; // конца тоже

	// инициализация массивов
	Elems = new T[size_List]; 
	nextElem = new unsigned[size_List];
	predElem = new unsigned[size_List];

	// пробегаемся по массивам и говорим, что у нас вообще ничего нет!
	for (int i = 0; i < size_List; i++)
	{
		nextElem[i] = -2;
		predElem[i] = -2;
		freeMesto.push(i); // все ячейки в свободную стопку
	}
}

// конструктор копирования
template<class T>
inline List_on_array<T>::List_on_array(List_on_array<T>& L)
{
	// пересоздаем массивы
	Elems = new T[L.size_List];
	nextElem = new int[L.size_List];
	predElem = new int[L.size_List];
	for (int i = 0; i < L.size_List; i++)
		{
			Elems[i] = L.Elems[i]; // массив данных
			nextElem[i] = L.nextElem[i]; // массив индексов следующего элемента
			predElem[i] = L.predElem[i]; // на предыдущий
		}
	freeMesto = L.freeMesto; // очередь пустых ячеек
	size_List = L.size_List; // размер
	start = L.start; // начало  
	end = L.end; // конец
	cpunt_elem = L.count_Elem; // количество элементов
}

template<class T>
inline List_on_array<T>::~List_on_array()
{
	// просто все удаляем :)
	delete[]Elems;
	delete[]nextElem;
	delete[]predElem;
}

template<class T>
inline void List_on_array<T>::push(int n, T elem)
{
	if (count == size) throw - 1; // если он уже заполнен, то сорян, ничего не получится
	if (n <= 0 || n > count - 1) throw - 1; //  или если за диапазон выползает, то тоже не прокатит
	int tmp = freeMesto.front(); // вытаскиваем свободное место
	freeMesto.pop(); // и удаляем его из очереди
	Elems[tmp] = elem; // в это свободное место добавляем элемент
	count_Elem++; // теперь элементов стало больше

	int tmppred = start;
	int tmpnext = nextElem[tmpstart];
	// находим последний свободный
	for (int i = 0; i < n-1; i++)
	{
		tmppred = tmpnext;
		tmpnext = nextElem[i];
	}
	// перезаписываем следующие элементы
	nextInd[tmp] = tmpnext;
	nextInd[pred] = tmppred;
	// перезаписываем предыдущие элементы
	predElem[tmp] = tmppred;
	predElem[tmpnext] = tmp;
}

// положить в начало
template<class T>
inline void List_on_array<T>::pushStart(T elem)
{
	if (count == size) throw - 1; // если он уже заполнен, то сорян, ничего не получится
	int tmp = freeMesto.front(); // вытаскиваем свободное место
	freeMesto.pop(); // и удаляем его из очереди
	Elems[tmp] = elem; // втаскиваем нужный
	count++; // нас стало больше!
	// затираем следы 
	nextElem[tmp] = start;
	if (start != -1)
		predElem[start] = tmp;
	else
		end = tmp;
	start = tmp;	
}

// положить в конец
template<class T>
inline void List_on_array<T>::pushEnd(T elem)
{
	if (count == size) throw - 1; // если он уже заполнен, то сорян, ничего не получится
	int tmp = freeMesto.front(); // вытаскиваем свободное место
	freeMesto.pop(); // и удаляем его из очереди
	Elems[tmp] = elem;
	count++;
	if (end != -1)
		nextElem[end] = tmp;
	else
	{
		start = tmp;
		predElem[tmp] = -1;
	}
	predElem[tmp] = end;
	end = tmp;
}

// вытащить какой-то
template<class T>
inline T List_on_array<T>::pull(int n)
{
	if (count == 0) throw - 1; // если пуст, то косяк
	if (n <= 0 || n > count - 1) throw - 1; // если за границы - тоже косяк
	T tmp;
	int tmpindex = start;
	// доходим до n 
	for (int i = 0; i < n; i++)
	{
		tmpindex = nextElem[tmpindex];
	}
	tmp = Elems[tmpindex];
	freeMesto.push(tmpindex);
	count_Elem--; // нас стало меньше
	// затираем следы, что там что-то было
	nextElem[predElem[tmpindex]] = nextElem[tmpindex];
	predElem[nextElem[tmpindex]] = predElem[tmpindex];
	return tmp;
}

// вытащить с начала
template<class T>
inline T List_on_array<T>::pullStart(int n)
{
	if (count == 0) throw - 1;
	T tmp = Elems[start];
	count--;
	freeMesto.push(start);
	int tmpstart = nextElem[start];
	predElem[start] = -2;
	nextElem[start] = -2;
	if (tmpstart != -1)
		predElem[tmpstart] = -1;
	start = tmpstart;
	return tmp;
}

// вытащить с конца
template<class T>
inline T List_on_array<T>::pullEnd(int n)
{
	if (count == 0) throw - 1;
	T tmp = Elems[end];
	count--;
	freeMesto.push(end);
	int tmpindex = predElem[end];
	predElem[end] = -2;
	nextElem[end] = -2;
	end = tmpindex;
	if (tmpindex != -1)
		nextElem[tmpindex] = -1;
	else
		start = -1;
	return tmp;
}

// если пуст = true
template<class T>
inline bool List_on_array<T>::IsEmpty()
{
	if (count == 0)
		return true;
	return false;
}


template<class T>
ostream & operator<<(ostream & os, List_on_array<T> L)
{
	int tmp;
	for (int i = 0; i < count; i++)
	{
		os << Elems[tmp] << " ";
		tmp = nextElem[tmp];
	}
	return os;
}