/* 시험 점수 90~100:A, 80~89:B, 70~79:C, 60~69:D, 나머지:F */
#include <iostream>
using namespace std;

int main() {
	int score;
	cin >> score;

	if (score >= 90)
		cout << "A" << endl;
	else if (score >= 80 && score <= 89)
		cout << "B" << endl;
	else if (score >= 70 && score <= 79)
		cout << "C" << endl;
	else if (score >= 60 && score <= 69)
		cout << "D" << endl;
	else
		cout << "F" << endl;

	return 0;
}