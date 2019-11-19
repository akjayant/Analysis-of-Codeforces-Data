#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;
 
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define y1 abcde
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const ll inf = 2e13;
const int N = 2e3 + 15;
const int L = 32;
int n, t, a, b, dp[L][2][2][2][2];

int rec(int i, int lower1, int upper1, int lower2, int upper2) {
    if(i == -1)
        return 1;
    if(dp[i][lower1][upper1][lower2][upper2] != -1)
        return dp[i][lower1][upper1][lower2][upper2];
    dp[i][lower1][upper1][lower2][upper2] = 0;
    for(int j = 0; j < 2; ++j) {
        int nowa = (1LL << i) & a;
        int nowb = (1LL << i) & b;
        int curj = (j << i);
        if(!lower1 && curj > nowa)
            continue;
        if(!upper1 && curj < nowb)
            continue;
        for(int k = 0; k < 2; ++k) {
            if(j & k)
                continue;
            int curk = (k << i);
            if(!lower2 && curk > nowa)
                continue;
            if(!upper2 && curk < nowb)
                continue;
            int x1 = lower1 | (curj < nowa);
            int y1 = upper1 | (curj > nowb);
            int x2 = lower2 | (curk < nowa);
            int y2 = upper2 | (curk > nowb);
            dp[i][lower1][upper1][lower2][upper2] += rec(i - 1, x1, y1, x2, y2);
        }
    }
    return dp[i][lower1][upper1][lower2][upper2];
}

main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> t;
    while(t--) {
        for(int i = 0; i < L; ++i)
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 2; ++k)
                    for(int l = 0; l < 2; ++l)
                        for(int f = 0; f < 2; ++f)
                            dp[i][j][k][l][f] = -1;
        cin >> a >> b;
        swap(a, b);
        cout << rec(L - 1, 0, 0, 0, 0) << endl;
    }
    return 0;
}