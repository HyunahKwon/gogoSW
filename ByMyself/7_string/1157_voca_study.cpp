/* 이 단어에서 가장 많이 사용된 알파벳은? 여러개면 '?' 출력
	a: 97, A: 65, z:122, Z:90  */
#include <iostream>
#include <string>
using namespace std;

int main() {
	string voca;
	int max = -1, spell[26], temp;	// spell[26]: 알파벳 순서대로

	cin >> voca;
	for (int i = 0; i < 26; i++) spell[i] = 0;		// initialize
	for (int i = 0; i < voca.length(); i++) {		// 알파벳 개수++
		voca[i] >= 97 ? spell[voca[i] - 97]++ : spell[voca[i] - 65]++;
	}
	for (int i = 0; i < 26; i++) {
		if (spell[i] == max) {
			temp = -1;					// 바로 break;하면 안됨주의!!
		}
		else if (spell[i] > max && spell[i] != 0) {
			max = spell[i];
			temp = i;
		}
	}

	if (temp == -1)
		cout << "?";
	else
		cout << char(temp + 65);	// 대문자 출력

	return 0;
}