/*************************************************************************
	> File Name: 7.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月04日 星期五 16时42分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#define MAX 200000
int prime[MAX + 5] = {0};

void init() {
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
    }
    return ;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}
