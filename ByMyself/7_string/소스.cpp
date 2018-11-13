#include <iostream>
#include <string>
using namespace std;
#define MAX 100

int main() {
	int n, cnt = 0, ans = 0;
	char arr[MAX];
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		while (cnt < MAX) {
			arr[cnt] = ' ';
			cnt++;
		}
		bool check = false;
		for (int j = 1; j < word.length(); j++) {
			if (j=0 || (word.at(j) != word.at(j - 1))) {
				for (int k = 0; k < j; k++) {
					if (word.at(j - 1) == arr[k]) {
						ans++;
						check = true;
						break;
					}
					else {
						arr[j-1] = word.at(j - 1);
					}
				}
			}
			if (check) break;
		}
	}

	cout << ans;

	return 0;
}