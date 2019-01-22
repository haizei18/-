/*************************************************************************
	> File Name: 93.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月29日 星期六 18时13分19秒
 ************************************************************************/
//四个数字三个符号随机组合所有情况

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
using namespace std;
#define MAX_N 10000

int vis[MAX_N + 5] = {0};

double calc(char *result, int n) {
    stack<double> s;
    for (int i = 0; i < n; i++) {
        if (result[i] <= '9' && result[i] >= '0') {
            s.push(result[i] - '0');
            continue;
        }
        double a = s.top() - '0'; s.pop();
        double b = s.top() - '0'; s.pop();
        switch (result[i]) {
            case '+': s.push(a + b); break;
            case '-': s.push(a - b); break;
            case '*': s.push(b * a); break;
            case '/': s.push(b / a); break;
        }
    }
    return s.top();
}

#define ESP 1e-7

int dfs(char *result, int k, int a, int b, int *num) {
    if (k == 7) {
        double ret = calc(result, 7);
        if (ret > 0 && fabs(ret - floor(ret) < ESP)) {
            vis[(int)ret] = 1;
        }
        return 1;
    }

    if (b + 1 < a) {
        result[k] = '+', dfs(result, k + 1, a, b + 1, num);
        result[k] = '-', dfs(result, k + 1, a, b + 1, num);
        result[k] = '*', dfs(result, k + 1, a, b + 1, num);
        result[k] = '/', dfs(result, k + 1, a, b + 1, num);
    }
    if (a < 4) {
        result[k] = num[a] + '0';
        dfs(result, k + 1, a + 1, b, num);
    }
    return 0;
}


int main() {
    int len = 0, ret = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            for (int k = j + 1; k <= 9; k++) {
                for (int l = k + 1; k <= 9; k++) {
                    int num[4] = {i, j, k, l};
                    char result[7] = {0};
                    memset(vis, 0, sizeof(vis));
                    do {
                        dfs(result, 0, 0, 0, num);
                    } while (next_permutation(num, num + 4));
                    int temp_len = 1;
                    for (; vis[temp_len]; temp_len++);
                    if (temp_len - 1 > len) {
                        len = temp_len;
                        ret = i * 1000 + j * 100 + k * 10 + l;
                    }
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}


