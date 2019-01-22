/*************************************************************************
	> File Name: 5.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月04日 星期五 16时32分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include<inttypes.h>

int gcd(int32_t a, int32_t b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    int64_t ans = 1;
    for (int32_t i = 1; i <= 20; i++) {
        ans *= i / (gcd(ans, i));
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
