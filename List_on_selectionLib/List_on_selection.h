#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

template <typename T> class list
{
private:
	class node //Класс node содержит данные списка
	{
		friend class list<T>;
	private:
		node *next; //Указатель на следующий элемент в списке
		T val; //Данные списка

		node() : next(NULL) {}
		~node() {}
	};

	node *head; //Указатель на начало списка
	int count; //Количество элементов в списке
public:
	list() : head(NULL), count(0) {}
	~list()
	{
		clear(); //Функция освобождает память, используемую для хранения списка
	}
	int getCount() const //Возвращает количество элементов в списке
	{
		return count;
	}

	int add(T data)//Добавление элемента в конец списка. Возвращает количество элементов в списке
	{
		node *to_add = new node;
		to_add->next = NULL;
		to_add->val = data;
		if (head == NULL) //Если в списке нет элементов
			head = to_add;
		else
		{
			node *current;
			for (current = head; current->next != 0; current = current->next);
			current->next = to_add;
		}
		count++;
		return count;
	}

	int del(int x) //Удаление элемента из списка. Возвращает количество элементов в списке. 
	{			   //Возвращает -1, если произошла ошибка
		if (x > count) return -1;
		node *to_del = head;
		if (x == 1) //Если нужно удалить первый элемент
		{
			head = head->next;
			delete to_del;
		}
		else
		{
			node *current = head;
			for (int i = 1; i < x - 1; i++)
				current = current->next;
			to_del = current->next;
			current->next = current->next->next;
			delete to_del;
		}
		count--;
		return count;
	}

	void clear() //Очистка списка
	{
		node *current = head;
		node *to_del = head;
		while (to_del != NULL)
		{
			current = current->next;
			delete to_del;
			to_del = current;
		}
		head = NULL;
		count = 0;
	}

	T getData(int x) const //Возвращает данные из списка.
	{
		node *current;
		for (current = head; x > 1; x--)
			current = current->next;
		return current->val;
	}
};