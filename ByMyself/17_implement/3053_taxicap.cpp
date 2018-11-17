/* �ýñ�����: D(T1,T2) = |x1-x2| + |y1-y2|  --> �� = �������
	��Ŭ���� ������: D(T1,T2) = root( (x1-x2)^2 + (y1-y2)^2 ) --> �� = ���׶�...
	��� ù ��: ��Ŭ���� �����п��� ������ R�� ������ / ��°��: �ýñ����п��� ������ R�� ������*/
#include <iostream>
using namespace std;
#define M_PI 3.14159265358979323846

int main() {
	int r;
	cin >> r;

	// ��Ŭ���� ������
	double area_euclid = M_PI * r * r;

	// �ý� ������
	double area_taxi = double(1) / double(2) * (2 * r) * (2 * r);		// �� �밢�� * �ٸ� �� �밢�� / 2

	cout << fixed;
	cout.precision(6);
	cout << area_euclid << endl << area_taxi << endl;

	return 0;
}