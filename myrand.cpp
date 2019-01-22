/*************************************************************************
	> File Name: myrand.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月29日 星期六 09时37分38秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#define MAX_N 100000

static int my_seed = 37;

void my_srand(int x) {
    my_seed = x;
}

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
    }
    return ;
} 

int my_rand() {
    #define i my_seed
    do {
        i = i * 5 % 11003;
    } while (i > 10000);
    return i;
    #undef i
}

int quick_mod(int a, int b, int c) {
    for (int i = 2; i < b; i++) {


    }

    return ans;
}

int check(int a, int b) {
    int vis[10001] = {0};
    for (int i = 0; i < 10000; i++) {
        int temp = my_rand();


    }
}

int main() {
	init();
    int a, b;
    get_a_and_b(&a, &b);

	for (int i = 1; i < prime[0]; i++) {
		b = prime[i];
		if (prime[i] > 11000) break;
	}
	printf("%d\n", b);
    my_srand(time(0));
    int vis[101] = {0};
    for (int i = 0; i < 100; i++) {
        int temp = my_rand();
        vis[temp] && printf("error");
        vis[temp] = 1;
        printf("%d\n", temp);
    }
    return 0;
}
