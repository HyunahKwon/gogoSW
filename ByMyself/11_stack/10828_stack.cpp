/*스택 구현하기*/
#include <iostream>
#include <string>
using namespace std;
#define MAX 10000

int main() {
	int arr[MAX], n, top = -1, x;
	string str;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {		
			cin >> x;
			arr[++top] = x;			// push(x)
		}
		else if (str == "pop") {	// pop()
			if (top == -1)
				cout << "-1" << endl;
			else
				cout << arr[top--] << endl;
		}
		else if (str == "size") {		// size()
			cout << top + 1 << endl;
		}
		else if (str == "empty") {		// empty()
			if (top == -1)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "top") {		// top()
			if (top == -1)
				cout << "-1" << endl;
			else
				cout << arr[top] << endl;
		}
	}
	return 0;
}