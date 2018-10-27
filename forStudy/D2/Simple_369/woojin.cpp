#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void print_369(int n);
int pow(int a, int b);

int main(void) {
    int N;

    //freopen("sample_input.txt", "r", stdin);
    scanf("%d", &N);
    print_369(1);
    for(int i = 2; i <= N; ++i) {
        printf(" ");
        print_369(i);
    }
    printf("\n");

    return 0;
}

void print_369(int n) {
    int i=1, count = 0, orig = n;
    while(n != 0) {
        int tmp = (n % pow(10,i));
        n = n - tmp;
        if((tmp / pow(10,(i-1))) != 0 && (tmp / pow(10,(i-1))) % 3 == 0) count++;
        i++;
    }
    if(count == 0) printf("%d", orig);
    else {
        for(int j=0; j<count; j++) printf("-");
    }
}

int pow(int a, int b) {
    int result = 1;
    if(b == 0) return 1;
    else {
        for(int i=0; i<b; i++) {
            result *= a;
        }
    }
    return result;
}