#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
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
const int mod = 998244353;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
LL ksm(LL a, LL b) {LL res = 1;for(; b; b>>=1, a=a*a%mod) if(b&1) res = res * a % mod;return res;}
const int MXN = 1e5 + 7;
const int MXE = 2e5 + 7;

int n, m;
LL k;
LL ar[MXN], pre[MXN], suf[MXN];
int fk(int i, int l, int r, LL x) {
    int mid, ans = -1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(ar[i] - ar[mid] > x) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
bool ok(LL x) {
    LL tk = k, ans;
    for(int i = 1; i <= n; ++i) {
        int p = upper_bound(ar + i, ar + 1 + n, ar[i] + x) - ar;
        if(p != n + 1) {
            ans = suf[p] - (ar[i]+x)*(n-p+1);
        }
        ans += (LL)i * ar[i] - pre[i];
        if(ans <= tk) return true;
    }
    for(int i = 1; i <= n; ++i) {
        if(ar[i] - ar[1] > x) {
            int p = fk(i, 1, i, x);
            ans = p * (ar[i]-x) - pre[p];
        }
        ans += suf[i] - ar[i] * (n - i + 1);
        if(ans <= tk) return true;
    }
    return false;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("E://ADpan//in.in", "r", stdin);
    // freopen("E://ADpan//out.out", "w", stdout);
#endif
    n = read(), k = read();
    for(int i = 1; i <= n; ++i) ar[i] = read();
    sort(ar + 1, ar + 1 + n);
    for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + ar[i];
    for(int i = n; i >= 1; --i) suf[i] = suf[i+1] + ar[i];
    LL L = 0, R = ar[n] - ar[1], mid, ans = ar[n] - ar[1];
    ar[n + 1] = INFLL;
    while(L <= R) {
        mid = (L + R) >> 1;
        if(ok(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    printf("%lld\n", ans);
#ifndef ONLINE_JUDGE
    cout << "time cost:" << clock() << "ms" << endl;
#endif
    return 0;
}