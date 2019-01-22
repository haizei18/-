/*************************************************************************
	> File Name: 4.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月04日 星期五 14时55分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>

int is_hiuwen(int x) {
    int num = 0, temp = x;
    while(x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return temp == num;
}

int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (i * j < ans) continue;
            if (!is_hiuwen(i * j)) continue;
            ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
