/*************************************************************************
	> File Name: 37.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月12日 星期六 19时04分01秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 50000000
#include<math.h>

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

void init() {
    is_prime[0] = is_prime[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i >= MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

bool is_valued(int n) {
    int x = n;
    while (x) {
        if (is_prime[x] != 0) return false;
        x /= 10;
    }
    int h = (int)pow(10, floor(log10(n)));
    x = n;
    while (x) {
        if (is_prime[x] != 0) return false;
        x -= (x / h) * h;
        h /= 10;
    }
    return true;
}

int solve() {
    int many = 0, flag = 11;
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] < 10) continue;
        if (!is_valued(prime[i])) continue;
        many += prime[i];
        if (!(--flag)) break;
    }
    return many;
}

int main() {
    init();
    int sum = solve();
    printf("%d\n", sum);
    return 0;
}
