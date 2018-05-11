#include <iostream>
#include <string>
using namespace std;

/*
	1. 일단 string으로 받아서 int값으로 저장하려고 '0' 아스키만큼 뺐음
	2. 몇 번 바꾸는지만 알면 소팅해서 풀어도 된다고 생각
*/

string str;
int tc, exchange, i, j;
int arr[6];

void swap(int* a, int* b){
	int* temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

int selSort(int arr[], int size, int cnt){
	int max, current = 0;
	int temp[6];
	for (i = 0; i < size; i++)
		temp[i] = arr[i];

	for (i = 0; i < size; i++){
		max = i;
		bool flag = false;
		for (j = i + 1; j < size; j++){
			if (arr[max] <= arr[j]){
				max = j;
				flag = true;
			}
		}
		if (flag){
			swap(arr[max], arr[i]);
			current++;
			if (current == cnt)
				return 0;
		}
	}
	for (i = 0; i < size; i++){
		if (arr[i] != temp[i])
			return cnt - current;
	}
	return cnt;
}

int main(){
	string str;
	int tc, exchange;  // tc: testcase, exchange: # of swapping
	int arr[6];

	cin >> tc;

	for (int test_case = 1; test_case <= tc; test_case++){
		string str;
		int exchange;
		int arr[6];
		cin >> str >> exchange;

		for (i = 0; i < str.length(); i++)
			arr[i] = str.at(i) - '0';    // calculate based on ascii value

		int remain_cnt = selSort(arr, str.length(), exchange);

		if (remain_cnt > 0){
			if (remain_cnt % 2){
				swap(arr[str.length() - 1], arr[str.length() - 2]);
				if (remain_cnt == exchange)
					swap(arr[str.length() - 1], arr[str.length() - 2]);
			}
		}
		else{
			if (arr[str.length() - 2] < arr[str.length() - 1])
				swap(arr[str.length() - 1], arr[str.length() - 2]);
		}

		cout << "#" << test_case << " ";
		for (i = 0; i < str.length(); i++)
			cout << arr[i];
		cout << "\n";
	}
	return 0;
}