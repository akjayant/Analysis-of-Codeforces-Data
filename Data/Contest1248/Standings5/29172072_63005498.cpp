#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int N = 1e5;
const int M = 1e9 + 7;
int n, m;
int dp[N][3][3];

int calc(int at, int lastb, int lastw, int mx) {
    if (at == mx)
        return 1;
    int &res = dp[at][lastb][lastw];
    if (res != -1)
        return res;
    res = 0;
    if (lastb < 2)
        res = (res + calc(at + 1, lastb + 1, 0, mx)) % M;
    if (lastw < 2)
        res = (res + calc(at + 1, 0, lastw + 1, mx)) % M;
    return res;
}

int main(int argc, char **argv) {
    scanf("%d%d", &n, &m);
    memset(dp, -1, sizeof(dp));
    int a = calc(0, 0, 0, m);
    memset(dp, -1, sizeof(dp));
    int b = calc(0, 0, 0, n);
    int answer = (((a - 2) % M + M) % M + b) % M;
    printf("%d\n", answer);
    return 0;
}