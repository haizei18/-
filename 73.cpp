/*************************************************************************
	> File Name: 72.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月29日 星期六 15时36分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 12000
int prime[MAX_N + 5] = {0};
int phi[MAX_N + 5] = {0};

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            phi[i] = i - 1;
        }
    for (int j = 1; j <= prime[0]; j++) {
        if (i * prime[j] > MAX_N) break;
        prime[i * prime[j]] = 1;
        if (i % prime[j] == 0) {
            phi[i * prime[j]] = phi[i] * prime[j];
            break;
        } else {
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
    }
    return ;
}

int main () {
    init_prime();
    long long sum = 0;
    for (int i = 2; i <= MAX_N; i++) sum += phi[i];
    cout << sum << endl;
    return 0;
}
