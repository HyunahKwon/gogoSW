/*
���������� N~1���� �۾����� �����
	��) 5�� ���
			*****
			 ****
			  ***
			   **
				*
*/

#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int rev = N; rev > i; rev--) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++)
			cout << "*";
		cout << endl;
	}

	return 0;
}