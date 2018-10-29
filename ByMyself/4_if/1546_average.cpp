/* 최댓값M, 모든 점수 --> 점수/M*100
	새로운 평균!!   */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> score;
	int temp, max = 0;
	double sum = 0.0;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		score.push_back(temp);
		if (temp > max) {
			max = temp;		//M
		}
	}

	for (int i = 0; i < n; i++) {
		sum += double(score.at(i)) / double(max) * 100;
	}
	
	cout << fixed;	// 소수점 고정
	cout.precision(2);
	cout << sum / double(n) << endl;	// avg 출력

	return 0;
}