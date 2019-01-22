/*************************************************************************
	> File Name: 7-1.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月04日 星期五 16时49分13秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#define MAX 200000
int prime[MAX + 5] = {0};

void init() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
