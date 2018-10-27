#include <iostream>
#include <cstring>
using namespace std;

char matrix[101][101];
int dlist[10000][2];

void grow(int r, int c, int d, int g);
int countRec(void);

int main() {
    int N, M, r, c, d, g;

    /* Initialize */
    memset(matrix, 0xff, sizeof(char)*101*101);

    /* Input */
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d %d %d", &c, &r, &d, &g);
        grow(r, c, d, g);
    }

    /* Solve */
    printf("%d\n", countRec());

    return 0;
}

void grow(int r, int c, int d, int g) {
    int dy[4] = {0,-1,0,1};
    int dx[4] = {1,0,-1,0};
    int cnt = 0;

    memset(dlist, 0xff, sizeof(int)*10000*2);

    dlist[cnt][0] = r; dlist[cnt++][1] = c;
    dlist[cnt][0] = r+dy[d]; dlist[cnt++][1] = c+dx[d];
    while(g--) {
        int brow = dlist[cnt-1][0];
        int bcol = dlist[cnt-1][1];
        for(int i=cnt-2; i>=0; i--) {
            dlist[cnt][0] = brow + (dlist[i][1] - bcol);
            dlist[cnt++][1] = bcol - (dlist[i][0] - brow);
        }
    }
    for(int i=0; i<cnt; i++) {
        matrix[dlist[i][0]][dlist[i][1]] = 1;
    }
}

int countRec(void) {
    int count=0;
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if((matrix[i][j] == 1) && (matrix[i][j+1] == 1) && (matrix[i+1][j] == 1) && (matrix[i+1][j+1] == 1))
                count++;
        }
    }
    return count;
}