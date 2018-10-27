#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

char Gear[5][9];
int K;


void rotate_spread(int gear_num, int direction);
void rotate(int gear_num, int direction);
int getScore();
int pow(int a, int b);

int main() {
    int gear_num, direction;

    /* Initialize */

    /* Input */
    for(int i=1; i<=4; i++)
        scanf("%s", Gear[i]);
    scanf("%d", &K);
    for(int i=0; i<K; i++) {
        scanf("%d %d", &gear_num, &direction);
        rotate_spread(gear_num, direction);
    }

    /* Solve */
    printf("%d", getScore());

    return 0;
}

void rotate_spread(int gear_num, int direction) {
    char joint[4][2];
    for(int i=1; i<=3; i++) joint[i][0] = Gear[i][2];
    for(int i=2; i<=4; i++) joint[i-1][1] = Gear[i][6];

    int direction_tmp = direction;
    for(int i=gear_num; i<=3; i++) {
        direction_tmp *= -1;
        if(joint[i][0] != joint[i][1]) {
            rotate(i+1, direction_tmp);
        }else break;
    }
    direction_tmp = direction;
    for(int i=gear_num-1; i>=1; i--) {
        direction_tmp *= -1;
        if(joint[i][0] != joint[i][1]) {
            rotate(i, direction_tmp);
        }else break;
    }
    rotate(gear_num, direction);
}

void rotate(int gear_num, int direction) {
    if(direction == -1) {
        Gear[gear_num][8] = Gear[gear_num][0];
        for (int j = 0; j < 8; j++) {
            Gear[gear_num][j] = Gear[gear_num][j + 1];
        }
    }else {
        Gear[gear_num][8] = Gear[gear_num][7];
        for(int j=7; j>=1; j--) {
            Gear[gear_num][j] = Gear[gear_num][j-1];
        }
        Gear[gear_num][0] = Gear[gear_num][8];
    }
}

int getScore() {
    int score=0;
    for(int i=1; i<=4; i++) {
        if(Gear[i][0] == '1') score += pow(2, i-1);
    }
    return score;
}

int pow(int a, int b) {
    int res = 1;
    for(int i=0; i<b; i++) res *= a;
    return res;
}