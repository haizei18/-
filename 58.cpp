/*************************************************************************
	> File Name: 58.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月29日 星期六 20时37分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 200000

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

int main() {
    init();
    int sum = 0, cnt = 0;
    for (int i = 3; i < 100; i += 2) {
        sum = (2 * i) - 1;
        for (int j = 1; j < i * i; j++) {
            if (prime[j]) cnt++;
        }
        if (cnt / sum < 0.1) break;
    cout << i << endl;
    }

    return 0;
}
