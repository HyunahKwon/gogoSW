/*
���������� 1~N���� Ŀ���� �����
	��) 5�� ���
		    *
		   **
		  ***
		 ****
		*****
*/

#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int rev = N; rev > i; rev--) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++)
			cout << "*";
		cout << endl;
	}

	return 0;
}