#include <iostream>
using namespace std;

char gear[4][9];
int clock[4];

void rotate(int target, int clockwise);
int sum();
void print();
int main(){
	// [0]: 12��, [2]: 3��, [6]: 9�� ����
	char temp;  // swap�� ���� ����

	int k; // ȸ��Ƚ��
	int target, clockwise; // target: ��Ϲ��� ��ȣ, clockwise: 1�̸� �ð����, -1�̸� �ݽð����

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 8; j++)
			cin >> gear[i][j];
	}

	cin >> k;
	
	while (k != 0){
		cin >> target >> clockwise;
		memset(clock, 0, sizeof(clock));
		clock[target - 1] = clockwise;		

		if (target == 1) {
			for (int i = 0; i <= 2; i++) {
				if (gear[i][2] != gear[i + 1][6])  //1�� != 2��
					clock[i + 1] = clock[i] * (-1);
			}
		}
		else if (target == 2) {
			if (gear[0][2] != gear[1][6])
				clock[0] = clock[1] * (-1);
			for (int i = 1; i <= 2; i++) {
				if (gear[i][2] != gear[i + 1][6])
					clock[i + 1] = clock[i] * (-1);
			}
		}
		else if (target == 3) {
			if (gear[2][2] != gear[3][6])  // 3��, 4�� ��
				clock[3] = clock[2] * (-1);
			for (int i = 2; i > 0; i--) {
				if (gear[i][6] != gear[i - 1][2])
					clock[i - 1] = clock[i] * (-1);
			}
		}
		else {  // ���4
			for (int i = 3; i > 0; i--) {
				if (gear[i][6] != gear[i - 1][2])
					clock[i - 1] = clock[i] * (-1);
			}
		}

		for (int i = 0; i < 4; i++){
			rotate(i, clock[i]);
		}

		//print();
		k--;
	}
	cout << sum() << endl;

	return 0;
}

void rotate(int target, int clockwise){  // ��� ȸ��!
	char temp;
	if (clockwise == 1){
	temp = gear[target][7];
		for (int i = 7; i > 0; i--){
			gear[target][i] = gear[target][i - 1];
		}
	gear[target][0] = temp;
	}
	else if (clockwise == -1){
		temp = gear[target][0];
		for (int i = 0; i < 7; i++){
			gear[target][i] = gear[target][i + 1];
		}
		gear[target][7] = temp;
	}
	else
		return;
}

int sum(){
	int sum = 0;
	
	if (gear[0][0] == '1')
		sum += 1;
	if (gear[1][0] == '1')
		sum += 2;
	if (gear[2][0] == '1')
		sum += 4;
	if (gear[3][0] == '1')
		sum += 8;

	return sum;
}

void print(){
	for (int i = 0; i < 4; i++){
		cout << "gear" << i + 1 << ": ";
		for (int j = 0; j < 8; j++)
			cout << gear[i][j];
		cout << endl;
	}
}