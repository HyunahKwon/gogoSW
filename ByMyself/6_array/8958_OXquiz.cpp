/* OX����: O(���� ���, ������ ���ӵ� O�� ����), X: Ʋ�� ���� 0�� */
#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	string result;
	cin >> tc;
	
	while (tc > 0) {
		cin >> result;
		int o = 0, ans = 0;				// o: ���ӵ� O�� ���� ����
		for (int i = 0; i < result.length(); i++) {
			if (result[i] == 'O') {
				o++;
				ans += o;
			}
			else {
				o = 0;			// ���� �������� �ʱ�ȭ
			}
		}
		cout << ans << endl;
		tc--;
	}
	return 0;
}