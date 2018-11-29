/* 스택 구현하기 */
#include <iostream>
#include <string>
using namespace std;
#define MAX 10000

int arr[MAX], n;
int top = -1;

void push(int n) {
	arr[++top] = n;
}

void pop() {
	if (top == -1)
		cout << "-1" << endl;
	else
		cout << arr[top--] << endl;
}

void size() {
	cout << top + 1 << endl;
}

void empty(){
	if (top == -1)
	cout << "1" << endl;
	else
	cout << "0" << endl;
}

void f_top() {
	if (top == -1)
		cout << "-1" << endl;
	else
		cout << arr[top] << endl;
}

int main() {
	string str;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {	
			int x;
			cin >> x;
			push(x);
		}
		else if (str == "pop")
			pop();
		else if (str == "size")
			size();
		else if (str == "empty")	
			empty();
		else if (str == "top")
			f_top();
	}
	return 0;
}