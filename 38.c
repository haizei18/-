/*************************************************************************
	> File Name: 38.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月12日 星期六 20时24分51秒
 ************************************************************************/

#include<stdio.h>
#define MAX 10000
#include<math.h>


bool is_valued (int n, int *result) {
    int num = 0, a[10] = {0};
    int ret = 0, x, i = 1;
    while (num < 9) {
        x = i * n;
        while (x) {
            if (x  % 10 == 0) return false;
            if (a[x % 10]) return false;
            a[x % 10] = 1; num++;
            x /= 10;
        }
        ret *= (int)pow(10, floor(log10(n * i)) + 1);
        ret += n * i;
        ++i;
    }
    (*result) = ret;
    return true;
}


int main() {
    int max_num = 0, num;
    for (int i = 1; i < MAX; i++) {
        int temp = is_valued(i, &num);
        if (temp) {
            printf("%d : %d\n", i, num);
            if (num > max_num) max_num = num;
        }
    }
    printf("%d\n", max_num);
    return 0;
}
