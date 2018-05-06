#include <iostream>

using namespace std;
int main() {
	for (int test_num = 1; test_num <= 10; test_num++) {
		int total_count = 0;
		int width_num = 0;
		cin >> width_num;
		int height = 0;
		int arr[1000];
		for (int i = 0; i < width_num; i++) {
			cin >> height;
			arr[i] = height;
		}
		int tempi, temp_minus1, temp_minus2, temp_plus1, temp_plus2;

		for (int i = 2; i < width_num - 2; i++) {
			tempi = arr[i];
			temp_minus1 = arr[i - 1];
			temp_minus2 = arr[i - 2];
			temp_plus1 = arr[i + 1];
			temp_plus2 = arr[i + 2];
			while (tempi > temp_minus1 &&tempi > temp_minus2 && tempi > temp_plus1 &tempi > temp_plus2 && tempi != 0) {
				total_count++;
				tempi = tempi - 1;
			}
		}
		cout << "#" << test_num << " " << total_count << endl;
	}
	return 0;
}
