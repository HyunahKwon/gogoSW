#include<iostream>
#include<fstream>
using namespace std;
//pass!! 40~50 minutes
int count369(int val, int i) {
	int count = 0;
	while (val!=0) {
		int rest= val / i;
		if (rest == 3 || rest == 6 || rest == 9) count++;
		val = val%i;
		i /= 10;
	}
	return count;
}


void print369(int n, ofstream& fout) {
	int c = 10;
	int i = 0;
	for (i = 1; i <= n; i++) {
		if ((i / (1*c))>=10) c *= 10;
		int count = count369(i, c);
		if (count != 0) {
			for (int j = 0; j < count; j++) fout << "-";
			fout << " ";
		}else fout << i << " ";
	}
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin >> n;
	print369(n, fout);
	fin.close();
	fout.close();
}