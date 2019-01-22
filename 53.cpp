/*************************************************************************
	> File Name: 53.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月29日 星期六 19时26分54秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#define max_n 100


int f[max_n + 5][max_n + 5] = {0};

int main() {
    int temp = 0;
    for (int i = 0; i <= max_n; i++) {
        f[i][0] = f[i][i] = 1;
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
            if (f[i][j] > 1000000) f[i][j] = 1000001;
            temp += (f[i][j] > 1000000);
        }
    }
    printf("%d\n", temp);
    return 0;
}
