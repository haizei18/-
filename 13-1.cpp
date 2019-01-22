/*************************************************************************
	> File Name: 13.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月19日 星期三 19时16分50秒
 ************************************************************************/
//求n的m次幂
#include <stdio.h>
#include <string.h>
int main() {
    int m, n;
    while (scanf("%d%d", &n, &m) != EOF) {
        int ans[50] = {0};
        ans[0] = ans[1] = 1;
        for (int j = 0; j < m; j++) {
            for (int j = 1; j <= ans[0]; j++) {
                ans[j] *= n;
            }
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] = ans[j] % 10;
            ans[0] += (j == ans[0]);
        }
        for (int i = ans[0]; i > 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
