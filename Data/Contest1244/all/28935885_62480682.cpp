#pragma comment(linker, "/STACK:102400000,102400000")
// #include<bits/stdc++.h>
#include <ctime>
#include <iostream>
#include <assert.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define fi first
#define se second
#define endl '\n'
#define o2(x) (x)*(x)
#define BASE_MAX 31
#define mk make_pair
#define eb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(a, b) memset((a),(b),sizeof((a)))
#define iis std::ios::sync_with_stdio(false); cin.tie(0)
#define my_unique(x) sort(all(x)),x.erase(unique(all(x)),x.end())
using namespace std;
#pragma optimize("-O3")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pii;
inline LL read() {
    LL x = 0;int f = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x = f ? -x : x;
}
inline void write(LL x, bool f) {
    if (x == 0) {putchar('0'); if(f)putchar('\n');else putchar(' ');return;}
    if (x < 0) {putchar('-');x = -x;}
    static char s[23];
    int l = 0;
    while (x != 0)s[l++] = x % 10 + 48, x /= 10;
    while (l)putchar(s[--l]);
    if(f)putchar('\n');else putchar(' ');
}
int lowbit(int x) { return x & (-x); }
template<class T>T big(const T &a1, const T &a2) { return a1 > a2 ? a1 : a2; }
template<class T>T sml(const T &a1, const T &a2) { return a1 < a2 ? a1 : a2; }
template<typename T, typename ...R>T big(const T &f, const R &...r) { return big(f, big(r...)); }
template<typename T, typename ...R>T sml(const T &f, const R &...r) { return sml(f, sml(r...)); }
void debug_out() { cerr << '\n'; }
template<typename T, typename ...R>void debug_out(const T &f, const R &...r) {cerr << f << " ";debug_out(r...);}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__);

const LL INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int HMOD[] = {1000000009, 1004535809};
const LL BASE[] = {1572872831, 1971536491};
const int mod = 1e9 + 7;//998244353
const int MOD = 1e9 + 7;
LL ksm(LL a, LL b, int MOD) {LL res = 1;for(; b; b>>=1, a=a*a%MOD) if(b&1) res = res * a % MOD;return res;}
const int INF = 0x3f3f3f3f;
const int MXN = 2e5 + 7;
const int MXE = 2e6 + 7;

int n, m;
LL dp[MXN][3][3], ar[MXN][3];
int pre[MXN][3][3], fa[MXN];
std::vector<int> mp[MXN], vs;
void dfs(int u, int ba) {
    vs.eb(u);
    for(int v: mp[u]) {
        if(v == ba) continue;
        dfs(v, u);
    }
}
int du[MXN], id[MXN];
int main() {
#ifndef ONLINE_JUDGE
    freopen("E://ADpan//in.in", "r", stdin);
    // freopen("E://ADpan//out.out", "w", stdout);
#endif
    n = read();
    for(int i = 0; i < 3; ++i) for(int j = 1; j <= n; ++j) ar[j][i] = read();
    int flag = 0;
    for(int i = 1, a, b; i < n; ++i) {
        a = read(), b = read();
        mp[a].eb(b), mp[b].eb(a);
        ++ du[a], ++ du[b];
        if(du[a] >= 3 || du[b] >= 3) flag = 1;
    }
    if(flag) {
        printf("-1\n");
        return 0;
    }
    clr(dp, 0x3f);
    int rt = 0;
    for(int i = 1; i <= n; ++i) if(du[i] == 1) rt = i;
    dfs(rt, 0);
    for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) if(i != j) dp[1][i][j] = ar[vs[1]][i] + ar[vs[0]][j];
    for(int i = 2; i < n; ++i) {
        std::vector<int> a;
        a.eb(0), a.eb(1), a.eb(2);
        do {
            dp[i][a[0]][a[1]] = dp[i-1][a[1]][a[2]] + ar[vs[i]][a[0]];
        }while(next_permutation(a.begin(), a.end()));
    }
    int a, b;
    LL ans = INFLL;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(dp[n-1][i][j] < ans) {
                ans = dp[n-1][i][j];
                a = i, b = j;
                id[vs[n-1]] = a, id[vs[n-2]] = b;
            }
        }
    }
    int c = 0;
    for(int i = 0; i < 3; ++i) if(i != a && i != b) c = i;
    id[vs[n-3]] = c;
    for(int i = n - 4; i >= 0; --i) {
        id[vs[i]] = id[vs[i + 3]];
    }
    printf("%lld\n", ans);
    for(int i = 1; i <= n; ++i) printf("%d ", id[i] + 1);
    printf("\n");
#ifndef ONLINE_JUDGE
    cout << "time cost:" << clock() << "ms" << endl;
#endif
    return 0;
}