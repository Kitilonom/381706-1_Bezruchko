#pragma once
#include <iostream>
#include "ost.h"
#include <queue>

using namespace std;

template <class T>
class List_on_array
{
	T* Elems; // ������ ������
	int* nextElem; // ������ �������� ���������� ��������
	int* predElem; // �� ����������
	queue<int> freeMesto; // ������� ������ �����
	int size_List; // ������
	int start; // ������  
	int end; // �����
	int count_Elem; // ���������� ���������
public:
	List_on_array(int _size_List = 0); // ����������� ��� ���������
	List_on_array(List_on_array<T> &L); // ����������� �����������
	~List_on_array(); // ����������

	void push(int n, T elem); // �������� ����-��
	void pushStart(T elem); // �������� � ������
	void pushEnd(T elem); // �������� � �����
	T pull(int n); // ����� ������������
	T pullStart(int n); // ����� ������
	T pullEnd(int n); // ����� ���������

	bool IsEmpty(); // ���� ������, �� true

	friend ostream& operator<< (ostream& os, List_on_array<T> L); // �����
};

// �����������
template<class T>
inline List_on_array<T>::List_on_array(int _size_List)
{
	if (_size_List <= 0) throw -1; // ������, ���� ������ ������ ��� ����� 0
	size_List = _size_List; // ������ � ������
	count_Elem = 0; // ������ ��� ������
	start = -1; // ������ ���
	end = -1; // ����� ����

	// ������������� ��������
	Elems = new T[size_List]; 
	nextElem = new unsigned[size_List];
	predElem = new unsigned[size_List];

	// ����������� �� �������� � �������, ��� � ��� ������ ������ ���!
	for (int i = 0; i < size_List; i++)
	{
		nextElem[i] = -2;
		predElem[i] = -2;
		freeMesto.push(i); // ��� ������ � ��������� ������
	}
}

// ����������� �����������
template<class T>
inline List_on_array<T>::List_on_array(List_on_array<T>& L)
{
	// ����������� �������
	Elems = new T[L.size_List];
	nextElem = new int[L.size_List];
	predElem = new int[L.size_List];
	for (int i = 0; i < L.size_List; i++)
		{
			Elems[i] = L.Elems[i]; // ������ ������
			nextElem[i] = L.nextElem[i]; // ������ �������� ���������� ��������
			predElem[i] = L.predElem[i]; // �� ����������
		}
	freeMesto = L.freeMesto; // ������� ������ �����
	size_List = L.size_List; // ������
	start = L.start; // ������  
	end = L.end; // �����
	cpunt_elem = L.count_Elem; // ���������� ���������
}

template<class T>
inline List_on_array<T>::~List_on_array()
{
	// ������ ��� ������� :)
	delete[]Elems;
	delete[]nextElem;
	delete[]predElem;
}

template<class T>
inline void List_on_array<T>::push(int n, T elem)
{
	if (count == size) throw - 1; // ���� �� ��� ��������, �� �����, ������ �� ���������
	if (n <= 0 || n > count - 1) throw - 1; //  ��� ���� �� �������� ���������, �� ���� �� ��������
	int tmp = freeMesto.front(); // ����������� ��������� �����
	freeMesto.pop(); // � ������� ��� �� �������
	Elems[tmp] = elem; // � ��� ��������� ����� ��������� �������
	count_Elem++; // ������ ��������� ����� ������

	int tmppred = start;
	int tmpnext = nextElem[tmpstart];
	// ������� ��������� ���������
	for (int i = 0; i < n-1; i++)
	{
		tmppred = tmpnext;
		tmpnext = nextElem[i];
	}
	// �������������� ��������� ��������
	nextInd[tmp] = tmpnext;
	nextInd[pred] = tmppred;
	// �������������� ���������� ��������
	predElem[tmp] = tmppred;
	predElem[tmpnext] = tmp;
}

// �������� � ������
template<class T>
inline void List_on_array<T>::pushStart(T elem)
{
	if (count == size) throw - 1; // ���� �� ��� ��������, �� �����, ������ �� ���������
	int tmp = freeMesto.front(); // ����������� ��������� �����
	freeMesto.pop(); // � ������� ��� �� �������
	Elems[tmp] = elem; // ���������� ������
	count++; // ��� ����� ������!
	// �������� ����� 
	nextElem[tmp] = start;
	if (start != -1)
		predElem[start] = tmp;
	else
		end = tmp;
	start = tmp;	
}

// �������� � �����
template<class T>
inline void List_on_array<T>::pushEnd(T elem)
{
	if (count == size) throw - 1; // ���� �� ��� ��������, �� �����, ������ �� ���������
	int tmp = freeMesto.front(); // ����������� ��������� �����
	freeMesto.pop(); // � ������� ��� �� �������
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

// �������� �����-��
template<class T>
inline T List_on_array<T>::pull(int n)
{
	if (count == 0) throw - 1; // ���� ����, �� �����
	if (n <= 0 || n > count - 1) throw - 1; // ���� �� ������� - ���� �����
	T tmp;
	int tmpindex = start;
	// ������� �� n 
	for (int i = 0; i < n; i++)
	{
		tmpindex = nextElem[tmpindex];
	}
	tmp = Elems[tmpindex];
	freeMesto.push(tmpindex);
	count_Elem--; // ��� ����� ������
	// �������� �����, ��� ��� ���-�� ����
	nextElem[predElem[tmpindex]] = nextElem[tmpindex];
	predElem[nextElem[tmpindex]] = predElem[tmpindex];
	return tmp;
}

// �������� � ������
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

// �������� � �����
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

// ���� ���� = true
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