/* ��(0), ��(1) ��¦�� �����?
 ��(�� �� ��, �� �� ��), ��(�� �� ��, �� �� ��), ��(�� �� ��, �� �� ��), ��(�� �� ��), ��(�� �� ��) */
#include <iostream>
using namespace std;

int main() {
	int a;

	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			cin >> a;
			if (a == 0)
				cnt++;
		}
		switch (cnt) {
		case 1:
			cout << "A" << endl;	// ��
			break;
		case 2:
			cout << "B" << endl;	// ��
			break;
		case 3:
			cout << "C" << endl;	// ��
			break;
		case 4:
			cout << "D" << endl;	// ��
			break;
		default:
			cout << "E" << endl;	// �� 
			break;
		}
	}
	return 0;
}