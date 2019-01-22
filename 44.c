/*************************************************************************
	> File Name: 44.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月15日 星期二 15时50分42秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int64_t pentagonal(int64_t x) {
    return x * (3 * x - 1) / 2;
}

int64_t is_pentagonal (int64_t n) {
    int64_t head = 1, tail = 500000000, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (pentagonal(mid) == n) return 1;
        if (pentagonal(mid) < n) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}


int main() {
    int64_t i = 1, j = 1, ans = INT64_MAX;
    while (pentagonal(j + 1) - pentagonal(j) < ans) {
        j++;
        i = j - 1;
        do {
            if (is_pentagonal(pentagonal(j) + pentagonal(i))) {
                if (is_pentagonal(pentagonal(j) - pentagonal(i))) {
                    if (pentagonal(j) - pentagonal(i) < ans) {
                        ans = pentagonal(j) - pentagonal(i);
                    }
                }
            }
            i--;
        } while (i >= 1 && pentagonal(j) - pentagonal(i) < ans);
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
