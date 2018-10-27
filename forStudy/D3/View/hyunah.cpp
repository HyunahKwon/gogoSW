#include <iostream>
using namespace std;

int main(){
	int buildings[1000] = { 0 };
	int n, i, left, right, testcase;   // n: 길이
	int able[10] = { 0 }; //케이스 별 가능한 수

	for (testcase = 0; testcase < 10; testcase++){
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> buildings[i];

		// start calculation . . .
		for (i = 1; i < n - 2; i++){
			if (buildings[i] > buildings[i - 2] && buildings[i] > buildings[i - 1] && buildings[i] > buildings[i + 2] && buildings[i] > buildings[i + 1]){
				if (buildings[i - 2] > buildings[i - 1])
					left = buildings[i] - buildings[i - 2];
				else 
					left = buildings[i] - buildings[i - 1];
				
				
				if (buildings[i + 2] > buildings[i + 1])
					right = buildings[i] - buildings[i + 2];
				else
					right = buildings[i] - buildings[i + 1];
				

				if (left > right)
					able[testcase] += right;
				else
					able[testcase] += left;
			}
		}
	}
	for (testcase = 0; testcase < 10; testcase++)
		cout << "#" << testcase + 1 << " " << able[testcase] << endl;

	return 0;
}