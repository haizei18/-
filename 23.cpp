/*************************************************************************
	> File Name: xianxin.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月02日 星期三 18时16分27秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 28123
#include <math.h>

int temp[MAX_N + 5] = {0};
int prime[MAX_N + 5] = {0};
int sum[MAX_N + 5] = {0};
int min_num[MAX_N + 5] = {0};
//sum求的是因子和，min_num是记录一个数最小因子的次幂

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            min_num[i] = 1;
            sum[i] = 1 + i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                min_num[prime[j] * i] = min_num[i] + 1;
                sum[prime[j] * i] = sum[i] / ((pow(prime[j], min_num[i] + 1)) - 1) * ((pow(prime[j], min_num[i] + 2)) - 1);
                break;
            } else {
                min_num[prime[j] * i] = 1;
                sum[prime[j] * i] = sum[prime[j]] * sum[i];

            }
        }
    }
    return ;
}



int main() {
    init();
    for (int i = 2; i <= MAX_N; i++) {
        sum[i] -= i;
        if (sum[i] > i) min_num[++min_num[0]] = i;
    }
    for (int i = 1; i <= min_num[0]; i++) {
        for (int j = 1; j <= min_num[0]; j++) {
            if (min_num[i] + min_num[j] > MAX_N) break;
                temp[min_num[i] + min_num[j]] = 1;
            }
    }
    int ans = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (!temp[i]) ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
