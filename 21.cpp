/*************************************************************************
	> File Name: xianxin.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月02日 星期三 18时16分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#define MAX_N 10000
#include <math.h>
int prime[MAX_N + 5] = {0};
int fnum[MAX_N + 5] = {0};
int mnum[MAX_N + 5] = {0};
int snum[MAX_N + 5] = {0};
//snum求的是因子和，fnum求的是因子个数，mnum是记录一个数最小因子的次幂

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            fnum[i] = 2;
            mnum[i] = 1;
            snum[i] = 1 + i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                fnum[prime[j] * i] = fnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                snum[prime[j] * i] = snum[i] / ((pow(prime[j], mnum[i] + 1)) - 1) * ((pow(prime[j], mnum[i] + 2)) - 1);
                break;
            } else {
                mnum[prime[j] * i] = 1;
                fnum[prime[j] * i] = fnum[prime[j]] * fnum[i];
                snum[prime[j] * i] = snum[prime[j]] * snum[i];

            }
        }
    }
}

int main() {
    init();
    for (int i = 2; i <= MAX_N; i++) {
        snum[i] -= i;
    }
    int sum = 0;
    int d;
    for (int i = 2; i <= MAX_N; i++) {
        d = snum[i];
        if (d <= MAX_N && snum[d] == i && i != d) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
