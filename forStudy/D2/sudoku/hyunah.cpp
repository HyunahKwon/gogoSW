#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9][9], row = 0, column = 0;
vector<int> v_row, v_col;

bool comp_row(int arr[1][9], int row, int column){
	bool res = true;

	for (row = 0; row < 9; row++){
		for (column = 0; column < 9; column++){
			v_row.push_back(arr[row][column]);
		}
		sort(v_row.begin(), v_row.end());

		for (int i = 1; i < 9; i++){
			if (v_row.at(i) == v_row.at(i - 1)){
				res = false;
				break;
			}
		}
		v_row.clear();
	}
	return res;
}

bool comp_col(int arr[9][9], int row, int column){
	bool res = true;

	for (column = 0; column < 9; column++){
		for (row = 0; row < 9; row++){
			v_col.push_back(arr[row][column]);
		}
		sort(v_col.begin(), v_col.end());

		for (int i = 1; i < 9; i++){
			if (v_col.at(i) == v_col.at(i - 1)){
				res = false;
				break;
			}
		}
		v_col.clear();
	}
	return res;
}

int main(){
	int tc, t, i, j;
	vector <int> small;
	vector <int> compare;

	cin >> tc;

	for (t = 0; t < tc; t++){
		bool res_row = true, res_col = true, res_small = true;
		cout << "#" << t+1 << " ";
		for (row = 0; row < 9; row++){
			for (column = 0; column < 9; column++){
				cin >> arr[row][column];
			}
		}

		res_row = comp_row(arr, row, column);
		res_col = comp_col(arr, row, column);
		
		// comp_small
		compare.clear();
		for (i = 0; i < 9; i++)
			compare.push_back(i + 1);
		i = 0, j = 0;
		while (i < 9){
			while (j < 9){
				small.clear();
				for (row = i; row < i + 3; row++){
					for (column = j; column < j + 3; column++){
						small.push_back(arr[row][column]);
					}
				}
				j += 3;
				sort(small.begin(), small.end());
				if (small != compare){
					res_small = false;
					break;
				}
			}
			i += 3;
			j = 0;
		}

		if (res_row == false || res_col == false || res_small == false)
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}

	return 0;
}