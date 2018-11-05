/* 40점 이상 = 그대로, 40점 미만: 보충수업 들으면 40점(강제임) --> 평균점수? */
#include <iostream>
using namespace std;

int main() {
	int score[5], sum = 0;		// 원섭, 세희, 상근, 숭, 강수

	for (int i = 0; i < 5; i++) {
		cin >> score[i];
		if (score[i] < 40) score[i] = 40;	// 40점+보충수업
		sum += score[i];
	}
	cout << sum / 5;

	return 0;
}