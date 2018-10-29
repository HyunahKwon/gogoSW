/* n<10: 앞에 0붙여서 두 자리 수로 만들고 각 자리 수 더함
	--> n*10+0 가장 오른쪽 자리 수 + 합의 가장 오른쪽 자리 수 이어 붙이자
	예) 26 --> 2+6=8 --> 새로운 수:68 --> 6+8=14 --> 새로운 수:84 ...
	다시 n으로 돌아오는 사이클의 길이
*/
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int temp, new_num = n;
	int cycle = 0;
	do {
		temp = 0;
		cycle++;
		if (new_num < 10) {
			temp = new_num * 10 + new_num;
			new_num = new_num * 10 + new_num;
		}
		else {			// 두 자리 수
			temp = new_num / 10 + new_num % 10;		// 십의 자리, 일의 자리
			if (temp % 10 == 0) {
				new_num = new_num % 10 * 10;
			}
			else {
				new_num = new_num % 10 * 10 + temp % 10;	// 일의 자리 + 더한 수의 일의 자리
			}
		}
	} while (n != new_num);

	cout << cycle;

	return 0;
}