/*************************************************************************
	> File Name: 3.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月04日 星期五 14时45分34秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <inttypes.h>
#define NUM 600851475143

int main() {
    int64_t num = NUM, ans = 0;
    for (int64_t i = 2; i * i <= num; i++) {
        if (num % i == 0) ans = i;
        while (num % i == 0) num /= i;
    }
    if (num != 1) ans = num;
    printf("%" PRId64 "\n", ans);
    return 0;
}
