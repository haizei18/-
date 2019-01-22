/*************************************************************************
	> File Name: cube.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月15日 星期二 15时10分38秒
 ************************************************************************/

#include<stdio.h>


int Cube(int n) {
    return n * n * n;
}

int is_cube(int a) {
    int rang = a;
    if (a < 0) rang = -a;
    int max = rang, min = - rang;
    int mid = (min + max) >> 1;
    while (max >= min) {
        if (Cube(mid) == a) break;
        if (Cube(mid) < a) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
        mid = (min + max) >> 1;
    }
    return Cube(mid) == a;
}

int main() {
    printf("%d\n", is_cube(27));
    printf("%d\n", is_cube(125));
    printf("%d\n", is_cube(44));

    return 0;
}
