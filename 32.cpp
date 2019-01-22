/*************************************************************************
	> File Name: 32.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月21日 星期五 19时49分30秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#define max_n 100000

int valid[max_n] = {0};

int digit(int i) {
    return floor(log10(i)) + 1;
}

int get_digit(int n, int *num) {
    while (n) {
        if (n % 10 == 0) return 0;
        if (num[n % 10]) return 0;
        num[n % 10] = 1;
        n /= 10;
    }
    return 1;
}

int is_digit(int a, int b, int c) {
    int num[10] = {0};
    if (!get_digit(a, num)) return 0;
    if (!get_digit(b, num)) return 0;
    if (!get_digit(c, num)) return 0;
    return 1;
}

int main() {
    int num[10] = {0};
    printf("%d\n", digit(891));
    printf("%d\n", get_digit(123,num));
    printf("%d\n", is_digit(12,34,56));
    int ans = 0;
    for (int a = 2; digit(a) + digit(a) + digit(a * a) <= 9; a++) {
        for (int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {
            if (is_digit(a, b, a * b)) {
                ans += (a * b);
                valid[a * b] = 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
