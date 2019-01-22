/*************************************************************************
	> File Name: 43.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2019年01月13日 星期日 16时47分26秒
 ************************************************************************/

using namespace std;
#include <inttypes.h>
#include <stdio.h>
#include<algorithm>

int64_t is_valued(int32_t *a) {
    if (a[0] == 0) return 0;
    int32_t j = 0, p[7] = {2, 3, 5, 7, 11, 13, 17};
    int64_t num = a[0], ret = a[0];
    for (int32_t i = 0; i < 10; i++) {
        ret = ret * 10 + a[i];
        num = num * 10 + a[i];
        if (i < 3) continue;
        num -= 1000 * a[i - 3];
        if (num % p[j++]) return 0;
    }
    return ret;
}

int32_t main() {
    int32_t a[10] = {0};
    for (int32_t i = 0; i < 10; i++) {
        a[i] = i;
    }
    int64_t sum = 0, temp;
    do {
        sum += is_valued(a);

    } while (next_permutation(a, a + 10));
    printf("%"PRId64"\n", sum);
    return 0;
}


