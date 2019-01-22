/*************************************************************************
	> File Name: 34.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月04日 星期五 15时46分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#define MAX_N 2540160 // 9! * 7


int get_jeichen(int *num) {
    num[0] = 1;
    for (int i = 1; i < 10; i++) {
        num[i] = num[i - 1] * i;
    }
}

int is_value(int x, int *a) {
    int temp = x, sum = 0;
    while (x) {
        sum += a[x % 10];
        x /= 10;
    }
    return temp == sum;
}

int solve(int *num) {
    int sum = 0;
    for (int i = 10; i <= MAX_N; i++) {
        if (is_value(i, num)) sum += i;
    }
    return sum;
}

int main() {
    int num[10] = {0};
    get_jeichen(num);
    int sum = solve(num);
    printf("%d\n", sum);
    return 0;
}
