/*************************************************************************
	> File Name: 31-1.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月21日 星期五 19时12分06秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int w(int k) {
    static int arr[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    return arr[k - 1];
}

//用前k硬币配n元有f(k,n)种方法
int f(int k, int n) {
    if (k == 1) return 1;
    if (n == 0) return 1;
    if (n < 0) return 0;
    return f(k - 1, n) + f(k, n - w(k));
}

int main() {
    printf("%d\n", f(8, 200));
    return 0;
}
