#include <iostream>
using namespace std;

int main(){
	int N, B, C;  // N: ������ ����, B: �Ѱ����� �������� ��, C: �ΰ����� �������� ��
	long long sum = 0;
	int i;

	cin >> N;

	int *A = new int[N];  // A:������

	for (i = 0; i < N; i++)
		cin >> A[i];    // ���� �� ������ �� �ֱ�
	cin >> B >> C;

	for (i = 0; i < N; i++){
		sum++;  // �Ѱ����� 1��
		// �ΰ��������� �����ϴ� ������ �� x*C >= A - B
		if (A[i] - B < 0)
			continue;
		else
			sum += ((A[i] - B) % C == 0 ? (A[i] - B) / C : (A[i] - B) / C + 1);		
	}
	cout << sum;

	return 0;
}