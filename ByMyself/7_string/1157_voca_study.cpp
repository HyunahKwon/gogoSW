/* �� �ܾ�� ���� ���� ���� ���ĺ���? �������� '?' ���
	a: 97, A: 65, z:122, Z:90  */
#include <iostream>
#include <string>
using namespace std;

int main() {
	string voca;
	int max = -1, spell[26], temp;	// spell[26]: ���ĺ� �������

	cin >> voca;
	for (int i = 0; i < 26; i++) spell[i] = 0;		// initialize
	for (int i = 0; i < voca.length(); i++) {		// ���ĺ� ����++
		voca[i] >= 97 ? spell[voca[i] - 97]++ : spell[voca[i] - 65]++;
	}
	for (int i = 0; i < 26; i++) {
		if (spell[i] == max) {
			temp = -1;					// �ٷ� break;�ϸ� �ȵ�����!!
		}
		else if (spell[i] > max && spell[i] != 0) {
			max = spell[i];
			temp = i;
		}
	}

	if (temp == -1)
		cout << "?";
	else
		cout << char(temp + 65);	// �빮�� ���

	return 0;
}