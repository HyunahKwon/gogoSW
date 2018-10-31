/* 단어의 개수는 몇 개인가. 공백 연달아 두 번 못 들어옴 */
#include <iostream>
using namespace std;

#define MAX 1000000

int main() {
	char word[MAX + 1] = {};		// initialize
	cin.getline(word, MAX + 1);		// MAX + 1개의 문자열만 입력받을게

	int i = 1;
	int cnt = 0;

	while (i < MAX + 1) {
		// 글자 다음 공백이면 단어 1개, 맨 뒤에 공백 있거나 없을 수 있음
		if ((word[i - 1] != ' ' && word[i] == ' ') || (word[i - 1] != ' ' && word[i] == NULL)) {
			cnt++;								
		}
		if (word[i] == NULL) {					// null이면 끝
			break;
		}
		i++;
	}
	cout << cnt;

	return 0;
}