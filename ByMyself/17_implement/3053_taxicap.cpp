/* 택시기하학: D(T1,T2) = |x1-x2| + |y1-y2|  --> 원 = 마름모꼴
	유클리드 기하학: D(T1,T2) = root( (x1-x2)^2 + (y1-y2)^2 ) --> 원 = 동그란...
	출력 첫 줄: 유클리드 기하학에서 반지름 R인 원넓이 / 둘째줄: 택시기하학에서 반지름 R인 원넓이*/
#include <iostream>
using namespace std;
#define M_PI 3.14159265358979323846

int main() {
	int r;
	cin >> r;

	// 유클리드 기하학
	double area_euclid = M_PI * r * r;

	// 택시 기하학
	double area_taxi = double(1) / double(2) * (2 * r) * (2 * r);		// 한 대각선 * 다른 한 대각선 / 2

	cout << fixed;
	cout.precision(6);
	cout << area_euclid << endl << area_taxi << endl;

	return 0;
}