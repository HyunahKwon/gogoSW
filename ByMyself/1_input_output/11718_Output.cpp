#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;

	while (1) {
		//cin >> text; --> ����ʰ� ��..
		getline(cin, text);
		if (text == "") {
			break;
		}
		cout << text << endl;
	}

	return 0;
}
