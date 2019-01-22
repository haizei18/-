/*************************************************************************
	> File Name: 45.c
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月15日 星期二 16时27分06秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>
typedef int64_t (*calcFunc)(int64_t);

int64_t Triangle(int64_t n) {
    return n * (2 * n - 1);
}

int64_t Pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t Hexagonal(int64_t n) {
    return n * (2 * n - 1);
}

bool valid(int64_t n, calcFunc f) {
    int64_t head = 1, tail = n, mid;
    mid = (head + tail) >> 1;
    while (head <= tail) {
        if (f(mid) == n) return true;
        if (f(mid) < n) head = mid + 1;
        else tail = mid - 1;
        mid = (head + tail) >> 1;
    }
    return false;
}

int main() {
    int64_t n = 1, t, cnt = 2;
    while (cnt) {
        ++n;
        t = Hexagonal(n);
        if (valid(t, Triangle) && valid(t, Pentagonal)) {
            --cnt;
        }
    }
    printf("%"PRId64"\n", t);
    return 0;
}
