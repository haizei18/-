/*************************************************************************
	> File Name: 30.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月04日 星期五 15时26分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#define MAX_N 354294
#include <math.h>


int is_equal(int x) {
    int temp = x, num = 0;
    while(x) {
        num += (int)pow((x % 10), 5);
        x /= 10;
    }
    return temp == num;
}

int main () {
    int sum = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!is_equal(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
