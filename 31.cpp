/*************************************************************************
	> File Name: 31.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月21日 星期五 19时06分40秒
 ************************************************************************/
#include <stdio.h>

int w[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int d[201] = {0};

int main() {
    d[0] = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = w[i]; j < 201; j++) {
            d[j] += d[j - w[i]];
        }
    }
    printf("%d\n", d[200]);
    return 0;
}
