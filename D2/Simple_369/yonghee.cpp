#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int input_num = 0; //입력받는 숫자
	cin >> input_num;
	int mok = 0; //몫
	int digit = 0; //자릿수
	int temp = 0; //자릿수 구할 때 잠시 사용할 변수
	for (int i = 1; i <= input_num; i++) {
		digit = 0;
		temp = i;
		while (1) { //자릿수 구하고
			digit++;
			temp /= 10;
			if (temp < 1) {
				break;
			}
		}
		int tempi = i;
		int temppow = 0;
		int count = 0;
		for (int j = digit-1; j >=0; j--) { //자릿수만큼 출력크
			mok = tempi / pow(10, j);
			if (mok == 3 || mok == 6 || mok == 9)  count++;

			temppow = pow(10, j);
			tempi =tempi % temppow;
		}
		if (count == 0) cout << i;
		else {
			while (count > 0) {
				cout << "-";
				count--;
			}
		}
		cout << " ";
	}
	system("pause");
	return 0;
}
