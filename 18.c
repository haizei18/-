/*************************************************************************
	> File Name: 18.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月15日 星期二 20时43分34秒
 ************************************************************************/

#include<stdio.h>
#define MAX 15

int map[MAX + 5][MAX + 5];
int keep[MAX + 5][MAX + 5];

int solve(int i, int j) {
    if (i == MAX) return 0;
    if (keep[i][j]) return keep[i][j];
    int lnum = solve(i + 1, j), rnum = solve(i + 1, j + 1);
    keep[i][j] = (lnum > rnum ? lnum : rnum) + map[i][j];
    return keep[i][j];
}

int main() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", map[i] + j);
        }
    }
    printf("%d\n", solve(0, 0));
    return 0;
}
