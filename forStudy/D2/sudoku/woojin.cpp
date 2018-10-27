#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int sudoku[9][9];

int solve();

int main(void) {
    int test_case;

    //freopen("input.txt", "r", stdin);
    scanf("%d", &test_case);
    for(test_case = 1; test_case <= 10; ++test_case) {
        /* Initialize */
        memset(sudoku, 0xff, sizeof(int)*81);

        /* Input */
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        /* Solve */
        printf("#%d %d\n", test_case, solve());
    }

    return 0;
}

int solve() {
    int check1[10], check2[10];

    /* case 1,2 : row, column check */
    for(int i=0; i<9; i++) {
        memset(check1, 0xff, sizeof(int)*10);
        memset(check2, 0xff, sizeof(int)*10);
        for(int j=0; j<9; j++) {
            if(check1[sudoku[i][j]] == 1) return 0;
            else check1[sudoku[i][j]] = 1;
            if(check2[sudoku[j][i]] == 1) return 0;
            else check2[sudoku[j][i]] = 1;
        }
    }
    /* case 3 */
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            memset(check1, 0xff, sizeof(int)*10);
            for(int k=i*3; k<i*3+3; k++) {
                for(int l=j*3; l<j*3+3; l++) {
                    if(check1[sudoku[k][l] == 1] == 1) return 0;
                    else check1[sudoku[k][l]] = 1;
                }
            }
        }
    }
    return 1;
}