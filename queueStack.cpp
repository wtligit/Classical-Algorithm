#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class solutionStoQ {
	stack<int> stack1;
	stack<int> stack2;
public:
	void push(int a) {
		stack1.push(a);
	}
	int pop() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				int a = stack1.top();
				stack1.pop();
				stack2.push(a);
			}
		}
		int tmp = stack2.top();
		stack2.pop();
		return tmp;
	}
};
class solutionQtoS {
	queue<int> queue1;
	queue<int> queue2;
public:
	void push(int a) {
		if (queue1.empty()) {
			queue2.push(a);
		}
		else {
			queue1.push(a);
		}
	}
	int pop() {
		if (queue1.empty()) {
			while (queue2.size() > 1) {
				queue1.push(queue2.front());
				queue2.pop();
			}
			int tmp= queue2.front();
			queue2.pop();
			return tmp;
		}
		else {
			while (queue1.size() > 1) {
				queue2.push(queue1.front());
				queue1.pop();
			}
			int tmp = queue1.front();
			queue1.pop();
			return tmp;
		}
	}
};
int main() {
	solutionStoQ s1;
	s1.push(2);
	cout << s1.pop() << endl;
	solutionQtoS s2;
	s2.push(20);
	cout << s2.pop() << endl;
	while (1);
	return 0;
}