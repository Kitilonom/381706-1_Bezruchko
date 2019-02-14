#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

template <typename T> class list
{
private:
	class node //����� node �������� ������ ������
	{
		friend class list<T>;
	private:
		node *next; //��������� �� ��������� ������� � ������
		T val; //������ ������

		node() : next(NULL) {}
		~node() {}
	};

	node *head; //��������� �� ������ ������
	int count; //���������� ��������� � ������
public:
	list() : head(NULL), count(0) {}
	~list()
	{
		clear(); //������� ����������� ������, ������������ ��� �������� ������
	}
	int getCount() const //���������� ���������� ��������� � ������
	{
		return count;
	}

	int add(T data)//���������� �������� � ����� ������. ���������� ���������� ��������� � ������
	{
		node *to_add = new node;
		to_add->next = NULL;
		to_add->val = data;
		if (head == NULL) //���� � ������ ��� ���������
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

	int del(int x) //�������� �������� �� ������. ���������� ���������� ��������� � ������. 
	{			   //���������� -1, ���� ��������� ������
		if (x > count) return -1;
		node *to_del = head;
		if (x == 1) //���� ����� ������� ������ �������
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

	void clear() //������� ������
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

	T getData(int x) const //���������� ������ �� ������.
	{
		node *current;
		for (current = head; x > 1; x--)
			current = current->next;
		return current->val;
	}
};