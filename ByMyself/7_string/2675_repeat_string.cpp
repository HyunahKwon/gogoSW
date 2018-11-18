/* 문자열 S 입력받고 각 문자를 r번 반복 */
#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc != 0) {
		int r;
		string s;
		cin >> r >> s;

		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < r; j++) {
				cout << s.at(i);
			}
		}
		cout << endl;
		tc--;
	}
	
	return 0;
}