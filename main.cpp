// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//stack as linked list is a dynamic allocation of nodes, but as an array we allocate the whole arraey and fill array with data
template <class T>
class stack {
private:
	int top;
	int maxsize;
	T* list;
public:
	stack(int size) {
		maxsize = size;
		list = new T[maxsize];
	}
	bool isempty();
	bool isfull();
	void push(T a);
	void pop();
	T stacktop();
	void initialize();
};
template <class T>
void stack<T>::initialize() {
	top = 0;
}
template<class T>
T stack<T>::stacktop() {
	return list[top];
}
template<class T>
bool stack<T>::isempty() {
	return(top == 0);
}
template<class T>
bool stack<T>::isfull() {
	return(top == maxsize);
}
template<class T>
void stack<T>::push(T a) {
	if (top != maxsize) {
		list[top] = a;
		//cout << list[top] << endl;
		top++;
	}
	//else {
		//cout << "full stack" << endl;
	//}
}
template<class T>
void stack<T>::pop() {
	if (!isempty()) {
		top--;
	}
	else {
		cout << "cannot remove empty stack" << endl;
	}
}
template <class T>
class queue {
private:
	int qfront;
	int qback;
	int maxsize;
	T* list;
public:
	queue(int size) {
		maxsize = size;
		list = new T[maxsize];
	}
	int count = 0;
	void dequeue();
	bool isempty();
	bool isfull();
	void inqueue(T a);
	T front();
	T back();
};
template<class T>
void queue<T>::dequeue() {
	if (!isempty()) {
		count--;
		qfront = (qfront + 1) % maxsize;

	}
	else {
		cout << "queue empty" << endl;
	}
}
template<class T>
void queue<T>::inqueue(T a) {
	if (!isfull()) {
		qback = (qback + 1) % maxsize;
		count++;
		list[qback] = a;
	}
	else {
		cout << "queue full" << endl;
	}
}
template<class T>
T queue<T>::back() {
	if (!isempty())
		return list[qback];
}
template<class T>
T queue<T>::front() {
	if(!isempty())
	return list[qfront];
}

template<class T>
bool queue<T>::isempty() {
	return(count == 0);
}
template<class T>
bool queue<T>::isfull() {
	return(count == maxsize);
}


int main()
{
	string line;
	cin >> line;
	//convert upper to lower
	queue<char> queue(200);
	stack<char> stack(200);
	stack.initialize();
	for (int i = 0; i < line.length(); i++) {
		//cout << line[i] << endl;
		if (isupper(line[i])) {
			line[i] = tolower(line[i]);
		}
			stack.push(line[i]);
			queue.inqueue(line[i]);
	}
	for (int i = 0; i < line.length(); i++) {
		if (queue.front() == stack.stacktop()) {
			//cout << "Popping" << endl;
			stack.pop();
			queue.dequeue();
		}
		else {
			cout << "Not Palindrome" << endl;
			system("pause");
			return 0;
		}
	}
	if (queue.isempty() && stack.isempty()) {
		cout << "Palindrome" << endl;
	}
	

	system("pause");
    return 0;
}

