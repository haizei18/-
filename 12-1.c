/*************************************************************************
	> File Name: 12-1.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月15日 星期二 19时31分39秒
 ************************************************************************/
//暴力算法时间复杂度高
#include<stdio.h>

int num(int n) {
    return (n + 1) * n / 2;
}

int factor_num(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) cnt += 2;
    }
    return cnt;
}

int main() {
    int n = 1;
    while (factor_num(num(n)) < 500) ++n;
    printf("%d\n", num(n));
    return 0;
}

