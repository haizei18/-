/*************************************************************************
	> File Name: 24.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月26日 星期三 18时41分52秒
 ************************************************************************/
#include <stdio.h>
#define MAX_N 10

int jnum[MAX_N] = {0};
int dnum[MAX_N] = {0};

void init() {
    jnum[0] = dnum[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        dnum[i] = 1; //dnum[i] = 1代表第i个数字还没被使用
        jnum[i] = i * jnum[i - 1]; // jnum[i]存放的是第i个数字的阶乘
    }
    return ;
}

int judge_num(int n, int k) {
    int ind = (k / jnum[n]) + 1, i = -1;
    while (ind > 0) {
        i++;
        ind -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}

int main() {
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    k -= 1;
    for (int i = n - 1; i >= 0; i--) {
        int num = judge_num(i, k);
        printf("%d", num);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}
