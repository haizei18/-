/*************************************************************************
	> File Name: 12.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月15日 星期二 18时09分56秒
 ************************************************************************/

#include<stdio.h>
#define MAX 100000
int prime[MAX + 5] = {0};
int num[MAX + 5] = {0};
int min_num[MAX + 5] = {0};


void initprime() {
    for (int i = 2; i  < MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            min_num[i] = 1;
            num[i] = 2;
        } 
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i >= MAX) break;
            prime[i * prime[j]] = 1;
            if (i  % prime[j] == 0) {
                min_num[i * prime[j]] =  min_num[i] + 1;
                num[i * prime[j]] = num[i] / (min_num[i] + 1) * (min_num[i] + 2);
                break;
            } else {
                min_num[i * prime[j]] = 1;
                num[i * prime[j]] = num[i] * num[prime[j]];
            }
        }
    }
}
//记录第n个三角数的因子个数

int factor_num(int n) {
    //n为奇数表示
    if (n & 1) {
        return num[n] * num[(n + 1) / 2];
    }//n为偶数
    return num[n / 2] * num[n + 1];
}
int main() {
    initprime();
    int n = 1;
    while (factor_num(n) < 500) ++n;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}

