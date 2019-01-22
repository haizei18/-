/*************************************************************************
	> File Name: 18-1.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月17日 星期四 18时11分49秒
 ************************************************************************/

#include<stdio.h>
#define MAX 15
#define max(a, b) ((a) > (b) ? (a) : (b))

int keep[MAX + 5][MAX + 5] = {0}; //从i,j 点走到最后一行所取的最大值

int main() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j <= i; j++) {
            scanf ("%d", &keep[i][j]);
        }
    }
    for (int i = MAX - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            keep[i][j] += max(keep[i + 1][j], keep[i + 1][j + 1]);
        }
    }
    printf("%d\n", keep[0][0]);
    return 0;
}

