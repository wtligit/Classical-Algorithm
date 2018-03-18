#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 0xffff

template<class Type>
class my_stack {
private:
	int top;
	int size;
	Type* array;
public:
	//Ĭ�ϴ�С
	my_stack():top(-1), size(MAXSIZE) {
		array = new Type[size];
		if (array == NULL) {
			cerr << "��̬�洢����ʧ��!" << endl;
			exit(1);
		}
	}
	//�Զ����С
	my_stack(int stackSize):top(-1), size(stackSize) {
		array = new Type[size];
		if (array == NULL) {
			cerr << "��̬�洢����ʧ��!" << endl;
			exit(1);
		}
	}
	~my_stack() {
		delete[] array;
	}
	bool Empty();
	void Push(Type tp);
	void Pop();
	Type Top();
	int Size();
};
template<class Type>
bool my_stack<Type>::Empty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}
template<class Type>
void my_stack<Type>::Push(Type tp) {
	if (top + 1 < size) {
		array[++top] = tp;
	}
	else {
		cout << "ջ����" << endl;
		exit(1);
	}
}
template<class Type>
void my_stack<Type>::Pop() {
	if (top >= 0) {
		top--;
	}
	else {
		cout << "ջ�գ�" << endl;
		exit(1);
	}
}
template<class Type>
Type my_stack<Type>::Top() {
	if (top != -1) {
		return array[top];
	}
	else {
		cout << "ջ�գ�" << endl;
		exit(1);
	}
}
template<class Type>
int my_stack<Type>::Size() {
	return top + 1;
}
/*
int main() {
	my_stack<int> st;
	st.Push(1);
	cout << st.Size() << endl;
	cout << st.Top() << endl;
	st.Pop();
	cout << st.Size() << endl;
	while (1);
	return 0;
}*/