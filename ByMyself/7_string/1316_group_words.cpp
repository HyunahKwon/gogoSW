/* �ҿ�����, ������ ������ ����(�����ؼ� ���� ���ڸ� ����) ���� �׷� �ܾ �ƴϴ�
	ccazzzzbb, kin, happy, new, year, a: �׷�ܾ�
	aabbbccb (�� �� b), aba (�� �� a), abab (���� a, b): �׷�ܾ� X */
#include <iostream>
#include <string>
using namespace std;
#define MAX 100

int main() {
	int n;
	cin >> n;
	int cnt = n;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		bool alphabet[26] = { false };
		for (int j = 0; j < word.length(); j++) {
			if (j == 0 || word[j] != word[j - 1]) {	// �� ���ڶ� �ٸ� ���ĺ��̸�
				if (alphabet[word[j] - 'a'] == true) { // �̹� ���� ���ĺ��� ������
					cnt--;	// �׷� �ܾ �ƴϴϱ� ����-1
					break;
				}
				else
					alphabet[word[j] - 'a'] = true; // ó�� ������ ���ĺ��̸�, ���Դٰ� üũ
			}
		}
	}
	cout << cnt;

	return 0;
}