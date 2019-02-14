#pragma once
#include <iostream>
#include <stack>
#include "ost.h"

using namespace std;

class Polish {
	stack<int> stk;
	bool isOk;
	char c;
public:
	Polish() : isOk(true) {};
	void Read();
	void Print();
};


void Polish::Read()
{
	do {
		while (c = cin.peek(), c == ' ' || c == '\t') cin.get();
		if (c == EOF || c == '\n' || c == '=') {
			isOk = false;
			cin.get();
		}
		else {
			int t;
			cin >> t;
			if (cin.fail()) {
				//получаем операнды
				int a, b;
				b = stk.top();
				stk.pop();
				a = stk.top();
				stk.pop();
				//вычисляем
				switch (c) {
				case '+':
					a += b;
					break;
				case '-':
					a -= b;
					break;
				case '*':
					a *= b;
					break;
				case '/':
					a /= b;
					break;
				default:
					break;
				}
				stk.push(a);
				//восстанавливаем чтение, выносим знак операции из потока ввода
				cin.clear();
				if (c = cin.peek(), c != EOF && c != '\n' && c != '=') cin.get();
			}
			else
				stk.push(t);
		}
	} while (isOk);
}

inline void Polish::Print()
{
	cout << stk.top() << endl;
}


