#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	int t, n, matched=100001;   // t: testcase, n: # of earthwormm
	long long min[10] = { 100000000000 }, res, sum=0;   // res=|V|
	vector< pair<long long, long long> > v(1);
	vector< long long > result_vector;
	
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;  // coordinate

	//sorting
	sort(v.begin(), v.end());

	// matching
	for (int i = 0; i < n; i++){
		if (matched != i){
			for (int j = i+1; j < n; j++){
				res = ((v[i].first - v[j].first) * (v[i].first - v[j].first)) + ((v[i].second - v[j].second) * (v[i].second - v[j].second));
				if (min[i] > res && j!=i && j != matched){
					min[i] = res;
					matched = j;
					//cout << i << "일 때 " << j << "이고      거리는: " << min[i] << endl;
				}
			}
		}
		//cout << i << "일 때 짝은: " << matched << "이고      거리는: " << min[i] << endl;
		min[i+1] = 100000000000;
		if (min[i] != 100000000000){
			result_vector.push_back(min[i]);
		}
	}

	for (int i = 0; i < n/2; i++){
		if (i % 2 == 0)
			sum += result_vector.at(i);
		else
			sum -= result_vector.at(i);
	}
	cout << sum << endl;

	return 0;
}