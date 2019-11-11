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
const int inf = 2e9;
const int N = 2e5 + 15;
int n, ans, dp[N];
string s;

main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> s;
    n = s.size();
    s = '#' + s;
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == 'w' || s[i] == 'm')
            return cout << 0 << endl, 0;
        else if(s.substr(i-1, 2) == "nn" || s.substr(i-1, 2) == "uu")
            dp[i] = (dp[i-2] + dp[i-1]) % mod;
        else
            dp[i] = dp[i-1];
    }
    cout << dp[n] << endl;
    return 0;
}