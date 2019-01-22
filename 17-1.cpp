/*************************************************************************
	> File Name: 17-1.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月09日 星期三 17时58分24秒
 ************************************************************************/

#include<stdio.h>
int LN_20[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int LN_10[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

int Get_number(int n) {
    int temp;
    if (n < 20) {
        return LN_20[n];
    } else if (n < 100) {
        return LN_10[n / 10] + LN_20[n % 10];
    } else if (n < 1000) {
        temp = Get_number(n % 100);
        if (temp != 0) {
            return LN_20[n / 100] + 10 + temp;
        }
        return LN_20[n / 100] + 7;
    } else if (n == 1000) {
        return 11;
    }
    return 0;
}

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum += Get_number(i);
    }
    printf("%d\n", sum);
    return 0;
}
