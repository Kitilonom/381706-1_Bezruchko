#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

#include <iomanip> // для setw

template <typename T>
class _Stack
{
private:
	T *stackPtr;                      // указатель на стек
	const int size;                   // максимальное количество элементов в стеке
	int top;                          // номер текущего элемента стека
public:
	_Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
	_Stack(const _Stack<T> &);          // конструктор копирования
	~_Stack();                         // деструктор

	inline void push(const T &);     // поместить элемент в вершину стека
	inline T pop();                   // удалить элемент из вершины стека и вернуть его
	inline void printStack();         // вывод стека на экран
	inline const T &Peek(int) const; // n-й элемент от вершины стека
	inline int getStackSize() const;  // получить размер стека
	inline T *getPtr() const;         // получить указатель на стек
	inline int getTop() const;        // получить номер текущего элемента в стеке
};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
_Stack<T>::_Stack(int maxSize) :
	size(maxSize) // инициализация константы
{
	if (maxSize <= 0) throw - 1;
	stackPtr = new T[size]; // выделить память под стек
	top = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
_Stack<T>::_Stack(const _Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под новый стек
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// функция деструктора Стека
template <typename T>
_Stack<T>::~_Stack()
{
	delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
void _Stack<T>::push(const T &value)
{
	// проверяем размер стека
	if (top >= size) throw - 1; // номер текущего элемента должен быть меньше размера стека

	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
T _Stack<T>::pop()
{
	// проверяем размер стека
	if (top <= 0) throw - 1; // номер текущего элемента должен быть больше 0

	return stackPtr[--top]; // удаляем элемент из стека
}

// функция возвращает n-й элемент от вершины стека
template <class T>
const T &_Stack<T>::Peek(int nom) const
{
	//
	if (nom > top) throw - 1;

	return stackPtr[top - nom]; // вернуть n-й элемент стека
}

// вывод стека на экран
template <typename T>
void _Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// вернуть размер стека
template <typename T>
int _Stack<T>::getStackSize() const
{
	return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
T *_Stack<T>::getPtr() const
{
	return stackPtr;
}

// вернуть размер стека
template <typename T>
int _Stack<T>::getTop() const
{
	return top;
}