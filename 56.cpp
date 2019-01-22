/*************************************************************************
	> File Name: 56.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月29日 星期六 19时48分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 205

int main() {
    int ans = 0;
    for (int i = 2; i < 100; i++) {
        int f[max_n + 5] = {0};
        f[0] = f[1] = 1;
        f[1] = i;
        for (int j = 2; j < 100; j++) {
            for (int k = 1; k <= f[0]; k++) f[k] *= i;
            for (int k = 1; k <= f[0]; k++) {
                if (f[k] < 10) continue;
                f[k + 1] += f[k] / 10;
                f[k] %= 10;
                f[0] += (f[0] == k);
            }
            int sum = 0;
            for (int k = 1; k <= f[0]; k++) sum += f[k];
            if (ans < sum) ans = sum;
        }
    }
    cout << ans << endl;
    return 0;
}
