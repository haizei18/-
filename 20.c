/*************************************************************************
	> File Name: 20.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月17日 星期四 18时52分28秒
 ************************************************************************/
//求100的阶乘

#include<stdio.h>

int a[500] = {0};

int main() {
    a[0] = a[1] = 1;
    for (int i = 2; i <= 100; i++) {
        for (int j = 1; j <= a[0]; j++) {
            a[j] *= i;
        }   
        for (int j = 1; j <= a[0]; j++) {
            if (a[j] < 10) continue;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
            a[0] += (j == a[0]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= a[0]; i++) {
        ans += a[i];
    }
    printf("%d\n", ans);
    return 0;
}
