#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <functional>
#include <map>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <random>

using namespace std;

typedef long long ll;
#define pii pair<int, int>
#define mp make_pair

ll read() {
    int f = 1;
    ll res = 0;
    char ch;
    do {
        ch = getchar();
        if (ch == '-') f = -f;
    } while (ch < '0' || ch > '9');
    do {
        res = res * 10 + ch - '0';
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return f == 1 ? res : -res;
}

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int N = 1000005;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const ll INF = 1e18;
int n,m;
int A[N], B[N];
char str[N];


int head[N], to[N * 2], nxt[N * 2], tot = 1, weight[N * 2];
void addEdge(int u, int v, int w = 1) {
    tot++;
    nxt[tot] = head[u];
    to[tot] = v;
    head[u] = tot;
    weight[tot] = w;
}

void initGraph() {
    for (int i = 0; i <= n; i++) head[i] = 0;
    tot = 1;
}

int countOne(ll set) {
    int res = 0;
    while (set) {
        res++;
        set &= set - 1;
    }
    return res;
}

bool contain(ll set, int i) {
    return (set & (1LL << i)) > 0;
}

ll myPow(ll a, ll p) {
    if (p == 0) return 1;
    ll res = myPow(a, p / 2);
    res *= res;
    res %= mod;
    if (p % 2 == 1) {
        res *= a;
        res %= mod;
    }
    return res % mod;
}

void addMode(ll &a, ll b) {
    a = (a+b) % mod;
    if (a < 0) a += mod;
}

ll mul(ll a, ll b) {
    ll res = a % mod * b % mod;
    if (res < 0) res += mod;
    return res;
}

int cal(int &b, int &c) {
    int res = 0;
    if (b >= c / 2) {
        res += c/2 * 2 + c/2;
        b -= c/2;
    } else {
        res += b + b * 2;
        b = 0;
    }
    return res;
}

int main() {

    fast_io();

    cin >> n;
    vector<vector<int>> res(n);
    int idx = 1;
    for (int i = 0; i < n; i+=2) {
        for (int j = 0; j < n; j++) res[j].push_back(idx++);
        if (i + 1 < n) {
            for (int j = n - 1; j >= 0; j--) res[j].push_back(idx++);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j];
            if (j != n-1) cout << " ";
            else cout << endl;
        }
    }

//    int T;
//    cin >> T;
//    for (int t = 1; t <= T; t++) {
//
//    }
    return 0;
}