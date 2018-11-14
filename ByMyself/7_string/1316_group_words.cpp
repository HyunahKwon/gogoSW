/* 불연속적, 이전에 나오지 않은(연속해서 같은 글자면 ㄱㅊ) 경우는 그룹 단어가 아니다
	ccazzzzbb, kin, happy, new, year, a: 그룹단어
	aabbbccb (맨 뒤 b), aba (맨 뒤 a), abab (뒤의 a, b): 그룹단어 X */
#include <iostream>
#include <string>
using namespace std;
#define MAX 100

int main() {
	int n;
	cin >> n;
	int cnt = n;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		bool alphabet[26] = { false };
		for (int j = 0; j < word.length(); j++) {
			if (j == 0 || word[j] != word[j - 1]) {	// 앞 글자랑 다른 알파벳이면
				if (alphabet[word[j] - 'a'] == true) { // 이미 나온 알파벳이 있으면
					cnt--;	// 그룹 단어가 아니니까 개수-1
					break;
				}
				else
					alphabet[word[j] - 'a'] = true; // 처음 나오는 알파벳이면, 나왔다고 체크
			}
		}
	}
	cout << cnt;

	return 0;
}