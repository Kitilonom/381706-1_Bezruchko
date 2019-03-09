#pragma once
#include <iostream>
#include "ost.h"

using namespace std;

template<typename T>
class Queue
{
private:
	T *queuePtr;     // ��������� �� �������
	const int size;  // ������������ ���������� ��������� � �������
	int begin,       // ������ �������
		end;         // ����� �������
	int elemCT;      // ������� ���������
public:
	Queue(int = 10);          // ����������� �� ���������
	Queue(const Queue<T> &); // ����������� �����������
	~Queue();                // ����������

	void enqueue(const T &); // �������� ������� � �������
	T dequeue(); // ������� ������� �� �������
	void printQueue();
	int getelemCT(); // �������� �������
	int getsize();
	bool IsEmpty(); // ������ = ������
};

// ���������� ������� ������� ������ Queue

// ����������� �� ���������
template<typename T>
Queue<T>::Queue(int sizeQueue) :
	size(sizeQueue), // ������������� ���������
	begin(0), end(0), elemCT(0)
{
	if (sizeQueue <= 0) throw - 1;
	// �������������� ������ ������� ��� ��������� ����� � ������ �������
	queuePtr = new T[size + 1];
}

// ����������� �����
template<typename T>
Queue<T>::Queue(const Queue &otherQueue) :
	size(otherQueue.size), begin(otherQueue.begin),
	end(otherQueue.end), elemCT(otherQueue.elemCT),
	queuePtr(new T[size + 1])
{
	for (int ix = 0; ix < size; ix++)
		queuePtr[ix] = otherQueue.queuePtr[ix]; // �������� �������
}

// ���������� ������ Queue
template<typename T>
Queue<T>::~Queue()
{
	delete[] queuePtr;
}

// ������� ���������� �������� � �������
template<typename T>
void Queue<T>::enqueue(const T &newElem)
{
	// ���������, ���� �� ��������� ����� � �������
	if (elemCT >= size) throw 1;

	// �������� �������� �� ��, ��� ������� �������� ����������� � 0 �������
	queuePtr[end++] = newElem;

	elemCT++;

	// �������� ��������� ���������� �������
	if (end > size)
		end -= size + 1; // ���������� end �� ������ �������
}

// ������� �������� �������� �� �������
template<typename T>
T Queue<T>::dequeue()
{
	// ���������, ���� �� � ������� ��������
	if (elemCT <= 0) throw - 1;

	T returnValue = queuePtr[begin++];
	elemCT--;

	// �������� ��������� ���������� �������
	if (begin > size)
		begin -= size + 1; // ���������� behin �� ������ �������

	return returnValue;
}

template<typename T>
void Queue<T>::printQueue()
{
	cout << "�������: ";

	if (end == 0 && begin == 0)
		cout << " ������\n";
	else
	{
		for (int ix = end; ix >= begin; ix--)
			cout << queuePtr[ix] << " ";
		cout << endl;
	}
}

template<typename T>
inline int Queue<T>::getelemCT()
{
	return elemCT;
}

template<typename T>
inline int Queue<T>::getsize()
{
	return size;
}

template<typename T>
inline bool Queue<T>::IsEmpty()
{
	if (elemCT == 0)
		return true;
	return false;
}