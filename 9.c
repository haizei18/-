/*************************************************************************
	> File Name: 9.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月15日 星期二 16时58分49秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    int flag = 1;
    int a, b, c, d;
    for (int i = 1; i < 32 && flag; i++) {
        for (int j = 1 + i; j < 32 && flag; j++) {
            a = j * j - i * i;
            b = 2 * i * j;
            c = j * j + i * i;
            if (1000  % (a + b + c) == 0) {
                d = (int)pow(1000 / (a + b +c), 3);
                printf("%d\n", a * b * c * d);
                flag = 0;
            }
        }
    }
    return 0;
}
