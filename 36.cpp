/*************************************************************************
	> File Name: 36.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月04日 星期五 16时17分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#define MAX 1000000

int is_huiwen(int x, int n) {
    int temp = x, num = 0;
    while(x) {
        num = num * n + x % n;
        x /= n;
    }
    return temp == num;
}


int main() {
    int sum = 0;
    for (int i = 1; i <= MAX; i++) {
        if(!is_huiwen(i, 10)) continue;
        if(!is_huiwen(i, 2)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
