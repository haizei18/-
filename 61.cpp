/*************************************************************************
	> File Name: 61.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年12月29日 星期六 14时27分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <vector>
#include <algorithm>

int sanb(int n) {
    return (n * (n + 1)) / 2;
}

int sib(int n) {
    return n * n;
}

int wub(int n) {
    return n * (3 * n - 1) / 2;
}

int liub(int n) {
    return n * (2 * n - 1);
}

int qib(int n) {
    return n * (5 * n - 3) / 2;
}

int bab(int n) {
    return n * (3 * n - 2);
}

int binary_search(int (*func(int)), int y) {
    int head = 1, tail = y, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        int temp = func(mid);
        if (temp == y) return 1;
        if (temp < y) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}//二分查找

int (*funclist[6])(int) = {
    sanb, sib, wub, liub, qib, bab
};//函数指针数组

int check(int *num) {
    sort(num, num + 6);
    do {
        for (int i = 0; i < 6; i++) {
            if (!binary_search(funclist[i], num[i])) continue;
            flag = 0;
            break;
        }
        if (flag) return 1;

    } while (next_permutation(num. num + 6));
    return 0;
}

//检查是否满足三四五六七八边形数的条件

vector<int> g[100];
int ans[7] = {0};
int vis[10000] = {0};



void init_graph() {
    for (int i = 0; i < 6; i++) {
        int k = 1;
        while (funclist[i](k) < 1000) ++k;
        while (funclist[i](k) < 10000) {
            int num = funclist[i](k);
            g[num / 100].push_back(num);
        }
    }
    return ;
}


int dfs(int x, int k) {
    vis[x] = 1;
    ans[k - 1] = x;
    if (k == 6) {
        vis[x] = 0;
        if (x % 100 != ans[0] / 100) return 0;
        return check(ans);
    }
    int ind = x % 100;
    for (int i = 0; i < g[ind].size(); i++) {
        int now = g[ind][i];
        if (dfs(now. k + 1)) return 1;
    }
    vis[x] = 0;
    return 0;
} //判断是否成环


int main() {
    init_graph();
    int flag = 1;
    int k = 1;
    while (bab(k) < 1000) ++k;
    while (bab(k) < 10000) {
        int num = bab(k++);
        vis[num] = 1;
        if (dfs(num, 1)) break;
    }
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        cout << ans[i] << " ";
        sum += ans[i];
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}














