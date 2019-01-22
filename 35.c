/*************************************************************************
	> File Name: 35.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月12日 星期六 17时49分01秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define MAX_N 1000000
int prime[MAX_N + 5] = {0};
int isprime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!isprime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] >= MAX_N) break;
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int get_digit(int x) {
    return (int)floor(log10(x)) + 1;
}

bool is_value(int n) {
    if (isprime[n] != 0) return false;
    int temp = get_digit(n), x = n;
    int h = (int)pow(10, (temp - 1));
    for (int i = 0; i < temp; i++) {
        x = x / 10 + (x % 10) * h;
        if (isprime[x] != 0) return false;
    }
    return true;
}

int sovle() {
    int sum = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] > MAX_N) break;
        if (is_value(prime[i])) sum++;
    }
    return sum;
}

int main() {
    init();
    int sum = sovle();
    printf("%d\n", sum);
    return 0;
}
