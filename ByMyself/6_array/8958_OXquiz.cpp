/* OX퀴즈: O(맞은 경우, 점수는 연속된 O의 개수), X: 틀린 문제 0점 */
#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	string result;
	cin >> tc;
	
	while (tc > 0) {
		cin >> result;
		int o = 0, ans = 0;				// o: 연속된 O의 개수 저장
		for (int i = 0; i < result.length(); i++) {
			if (result[i] == 'O') {
				o++;
				ans += o;
			}
			else {
				o = 0;			// 연속 끊겼으니 초기화
			}
		}
		cout << ans << endl;
		tc--;
	}
	return 0;
}