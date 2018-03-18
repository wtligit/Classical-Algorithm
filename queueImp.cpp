#include<iostream>
#include<stdio.h>
using namespace std;
template <class Type>
struct queueItem {
	Type value;
	queueItem<Type>* next;
	/*
	myClass()=delete;//表示删除默认构造函数

	myClass()=default;//表示默认存在构造函数
	*/
	queueItem() = default;
	queueItem(Type t):value(t),next(NULL){}
};
template <class Type>
class my_queue {
private:
	int count;
	queueItem<Type>* phead;
	queueItem<Type>* pend;
public:
	my_queue() :phead(NULL), pend(NULL), count(0) {
		phead = new queueItem<Type>();
		pend = phead;
		count = 0;
	}
	~my_queue() {
		while (phead->next != NULL) {
			phead = phead->next;
		}
	}
	bool IsEmpty();
	int Size();
	void Push(Type tp);
	void Pop();
	Type Front();
};
template <class Type>
bool my_queue<Type>::IsEmpty() {
	return count == 0;
}
template <class Type>
int my_queue<Type>::Size() {
	return count;
}
template <class Type>
void my_queue<Type>::Push(Type tp) {
	queueItem<Type>* pnode = new queueItem<Type>(tp);
	pend->next = pnode;
	pend = pnode;
	count++;
}
template <class Type>
void my_queue<Type>::Pop() {
	if (count == 0) {
		return;
	}
	queueItem<Type>* pnode = phead->next;
	phead->next = phead->next->next;
	delete pnode;
	count--;
}
template <class Type>
Type my_queue<Type>::Front() {
	return phead->next->value;
}
/*
int main() {
	my_queue<int> qu;
	qu.Push(1);
	if (!qu.IsEmpty()) {
		cout << qu.Size() << endl;
	}
	qu.Pop();
	cout << qu.Size() << endl;
	while (1);
	return 0;
}*/