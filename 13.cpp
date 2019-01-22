/*************************************************************************
	> File Name: 13.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月19日 星期三 19时16分50秒
 ************************************************************************/
//求１００位大数相加之和
#include <stdio.h>
#include <string.h>
int main() {
    char num[55];
    int ans[55] = {0};
    for (int i = 0; i < 100; i++) {
        scanf("%s", num);
        int len = strlen(num);
        if (len > ans[0]) ans[0] = len;
        for (int j = 0; j < len; j++) {
            ans[len - j] += (num[j] - '0');
        }//边加边处理进位
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] = ans[j] % 10;
            ans[0] += (j == ans[0]);
        }//处理进位
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }//倒着输出是因为存入和计算的时候都是倒着存入的
    printf("\n");
    return 0;
}
