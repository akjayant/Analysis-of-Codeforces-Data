#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:500000000")
#include <functional>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <complex>
#include <sstream>
#include <fstream>
#include <numeric>
#include <ctype.h>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#define Int long long
#define INF 0x3F3F3F3F
#define eps 1e-9
using namespace std;

#define N 100009

int C[3][N];
vector<int> g[N];
vector<int> chain;

bool dfs(int v, int prev) {
    int cnt = 0;
    int t = -1;
    chain.push_back(v);
    for (auto to : g[v]) {
        if (to == prev) {
            continue;
        }
        cnt++;
        t = to;
    }
    if (cnt > 1) {
        return false;
    }
    if (cnt == 0) {
        return true;
    }
    return dfs(t, v);
}

int main() {
    int n, i, a, b;
    scanf("%d", &n);
    for (int c = 0; c < 3; c++) {
        for (i = 0; i < n; i++) {
            scanf("%d", &C[c][i]);
        }
    }
    for (i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int start = -1;
    for (i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            start = i;
            break;
        }
    }
    if (start == -1 || !dfs(start, -1)) {
        puts("-1");
        return 0;
    }
    pair<Int, vector<int>> res = {1ll << 62ll, {}};
    vector<int> perm = {0, 1, 2};
    do {
        Int sum = 0;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            int c = perm[i % 3];
            sum += C[c][chain[i]];
            arr[chain[i]] = c;
        }
        res = min(res, {sum, arr});
    } while (next_permutation(perm.begin(), perm.end()));
    cout << res.first << endl;
    for (i = 0; i < n; i++) {
        printf("%d ", res.second[i] + 1);
    }
}