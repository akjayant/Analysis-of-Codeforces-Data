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

    int k;
    cin >> n >> m >> k;

    map<int, set<int>> row;
    map<int, set<int>> col;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        row[x].insert(y);
        col[y].insert(x);
    }

    int t = 1;
    int b = n;
    int l = 1;
    int r = m;

    int x = 1;
    int y = 1;

    while (t <= b && l <= r) {
        if (row.count(x)) {
            set<int> s = row[x];
            int start = *s.begin();
            for (int i = t; i <= b; i++) for (int j = start; j <= r; j++) {
                if (!row[i].count(j)) {
                    cout << "No" << endl;
                    return 0;
                }
                row[i].erase(j);
                if (row[i].size() == 0) row.erase(i);
                col[j].erase(i);
                if (col[j].size() == 0) col.erase(j);
            }
            r = start-1;
        }
        y = r;
        t++;
        if (t > b) break;

        if (col.count(y)) {
            set<int> s = col[y];
            int start = *s.begin();
            for (int i = start; i <= b; i++) for (int j = l; j <= r; j++) {
                if (!row[i].count(j)) {
                    cout << "No" << endl;
                    return 0;
                }
                row[i].erase(j);
                if (row[i].size() == 0) row.erase(i);
                col[j].erase(i);
                if (col[j].size() == 0) col.erase(j);
            }
            b = start - 1;
        }
        x = b;
        r--;
        if (l > r) break;

        if (row.count(x)) {
            set<int> s = row[x];
            auto it = s.end();
            it--;
            int end = *it;
            for (int i = t; i <= b; i++) for (int j = l; j <= end; j++) {
                    if (!row[i].count(j)) {
                        cout << "No" << endl;
                        return 0;
                    }
                    row[i].erase(j);
                    if (row[i].size() == 0) row.erase(i);
                    col[j].erase(i);
                    if (col[j].size() == 0) col.erase(j);
                }
            l = end+1;
        }
        y = l;
        b--;
        if (t > b) break;

        if (col.count(y)) {
            set<int> s = col[y];
            auto it = s.end();
            it--;
            int end = *it;
            for (int i = t; i <= end; i++) for (int j = l; j <= r; j++) {
                    if (!row[i].count(j)) {
                        cout << "No" << endl;
                        return 0;
                    }
                    row[i].erase(j);
                    if (row[i].size() == 0) row.erase(i);
                    col[j].erase(i);
                    if (col[j].size() == 0) col.erase(j);
                }
            t = end + 1;
        }
        x = t;
        l++;
    }
    cout << "Yes" << endl;

//    int T;
//    cin >> T;
//    for (int t = 1; t <= T; t++) {
//
//    }
    return 0;
}