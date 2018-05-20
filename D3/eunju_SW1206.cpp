#include<iostream>
#include<algorithm>
using namespace std;

//pass about 35min
int main() {
	int testcase = 10;
	int width;
	int result[10] = { 0, };
	while (testcase) {
		cin >> width;
		int *height = new int[width];
		int sum = 0;
		for (int i = 0; i < width; i++) {
			cin >> height[i];
		}
		for (int i = 2; i < width; i++) {
			if (height[i] > height[i - 1] && height[i]>height[i + 1]) {
				int lmin = min(height[i] - height[i - 1], height[i] - height[i - 2]);
				int rmin = min(height[i] - height[i + 1], height[i] - height[i + 2]);
				if(lmin >=0 && rmin >=0) sum += min(lmin, rmin);
			}
		}

		result[testcase - 1] = sum;
		testcase--;
	}
	for (int i = 9; i >= 0; i--) cout << "#" << 10-i << " " << result[i] << endl;
}