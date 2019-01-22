/*************************************************************************
	> File Name: 32.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月11日 星期五 20时52分57秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int canAdd[10001] = {0};

int get_digit(int x) {
    return (int)floor(log10(x)) + 1;
}

int howmanydigs(int i, int j) {
    return get_digit(i) + get_digit(j) + get_digit(i * j);
}

bool is_value(int n, int *num) { 
    while (n) {
        if (n % 10 == 0) return false;
        if (num[n % 10 - 1]) return false;
        num[n % 10 - 1] = 1;
        n /= 10;
    }
    return true;
}

int Is_value(int i, int j) {
    int num[9] = {0};
    if (is_value(i, num) && is_value(j, num) && is_value(i * j, num))
    return 1;
}


int main() {
    int sum = 0, digs;
    for (int i = 2; i < 100; i++) {
        for (int j = i + 1; ; j++) {
            digs = howmanydigs(i, j);
            if (digs < 9) continue;
            else if (digs > 9) break;
            if (Is_value(i, j) && !canAdd[i * j]) {
                sum += (i * j);
                canAdd[i * j] = 1;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
