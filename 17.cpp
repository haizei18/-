/*************************************************************************
	> File Name: 17.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月19日 星期三 18时26分50秒
    ************************************************************************/
#include <stdio.h>
int Get_LetterNum(int i) {
        static int LN20[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
        static int LN_shi[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
        if (i < 20) {
            return LN20[i];
        } else if (i < 100) {
            return LN_shi[i / 10] + LN20[i % 10];
        } else if (i < 1000) {
            if (i % 100 == 0) {
                return LN20[i / 100] + 7;
            }
            return LN20[i / 100] + 10 + Get_LetterNum(i % 100);
        } else {
            return 11;
        }
    }
int main() {
    int n;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum += Get_LetterNum(i);
    }
    printf("%d\n", sum);
    return 0;
}
