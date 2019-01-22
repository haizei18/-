/*************************************************************************
	> File Name: 26.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月26日 星期三 20时06分05秒
 ************************************************************************/

//求1000以内循环节最长的数字d

#include <stdio.h>
#include <string.h>
#define MAX_N 1000

int dnum[MAX_N + 5] = {0};
//得到的循环节长度
int get_length(int d) {
    int n = 0, y = 1;
    memset(dnum, 0, sizeof(dnum));
    while (y && dnum[y] == 0) {
        dnum[y] = n;//标记dnum[y]已经出现过了
        y = y * 10 % d;
        n += 1;
    }
    return y ? n - dnum[y] : 0;
}


int main() {
    int ans = 0, length = 0;
    for (int d = 2; d < MAX_N; d++) {
        if (length < get_length(d)) {
            length = get_length(d);
            ans = d;
        }
    }
    printf("%d\n", ans);
    return 0;
}
