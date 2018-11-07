/* 알파벳 글자수 세기(크로아티아 알파벳으로) 
	c=, c-, dz=, d-, lj, nj, s=, z= */
#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0;
	string voca;
	cin >> voca;

	for (int i = 0; i < voca.length(); i++) {
		switch (voca[i]) {
		case '=':
			if (i >= 2 && voca[i - 2] == 'd' && voca[i - 1] == 'z')	// dz=
				cnt--;
			else if (voca[i - 1] == 'c' || voca[i - 1] == 's' || voca[i - 1] == 'z')	// c=, s=, z=
				continue;
			break;
		case '-':
			if (voca[i - 1] == 'c' || voca[i - 1] == 'd')	// c-, d-
				continue;
			else
				cnt++;
			break;
		case 'j':
			if (voca[i - 1] == 'l' || voca[i - 1] == 'n')	// lj, nj
				continue;
			else
				cnt++;
			break;
		default:
			cnt++;
			break;
		}
	}
	cout << cnt;

	return 0;
}