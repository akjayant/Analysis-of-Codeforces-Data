#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long double lb;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2005;

struct ele {
    int u, v; ll val;
    ele (int a = 0, int b = 0, ll c = 0) : u(a), v(b), val(c) {}
    bool operator < (const ele A) const { return val < A.val; }
} a[N * N];

vector <int> ans1;
vector <pii> ans2;
int x[N], y[N], c[N], k[N], f[N];
int n, len, top; ll ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(x[i]), read(y[i]);
    for(register int i = 1; i <= n; i++) read(c[i]), a[++top] = ele(0, i, c[i]);
    for(register int i = 1; i <= n; i++) read(k[i]);
    for(register int i = 1; i <= n; i++) {
        for(register int j = i + 1; j <= n; j++) {
            a[++top] = ele(i, j, 1ll * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])));
        }
    }
    for(register int i = 1; i <= n; i++) f[i] = i;
    sort(a + 1, a + top + 1);
    for(register int i = 1; i <= top; i++) {
        int x = find(a[i].u), y = find(a[i].v);
        if(x != y) {
            if(a[i].u == 0) ans1.push_back(a[i].v);
            else ans2.push_back(make_pair(a[i].u, a[i].v));
            ans += a[i].val;
            f[x] = y;
        }
    }
    print(ans, '\n');
    print((int)ans1.size(), '\n');
    for(register int i = 0; i < (int)ans1.size(); i++) print(ans1[i], ' ');
    putchar('\n');
    print((int)ans2.size(), '\n');
    for(register int i = 0; i < (int)ans2.size(); i++) print(ans2[i].first, ' '), print(ans2[i].second, '\n');
    return 0;
}