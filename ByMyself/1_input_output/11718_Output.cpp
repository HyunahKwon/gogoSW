#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;

	while (1) {
		//cin >> text; --> 출력초과 뜸..
		getline(cin, text);
		if (text == "") {
			break;
		}
		cout << text << endl;
	}

	return 0;
}
