#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
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

const int N = 1e5 + 5;

ll s[N], k;
int a[N];
int n, ans;

int main() {
    read(n); read(k);
    for(register int i = 1; i <= n; i++) read(a[i]);
    sort(a + 1, a + n + 1); ans = a[n] - a[1];
    for(register int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for(register int i = 1; i <= n; i++) {
        ll las = k - (1ll * a[i] * i - s[i]);
        if(las < 0) break;
        int l = a[i], r = a[n], res = a[n];
        while(l <= r) {
            int mid = (l + r) >> 1;
            int pos = lower_bound(a + 1, a + n + 1, mid) - a;
            if(s[n] - s[pos - 1] - 1ll * mid * (n - pos + 1) <= las) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans = min(ans, res - a[i]);
    }
    for(register int i = n; i >= 1; i--) {
        ll las = k - (s[n] - s[i - 1] - 1ll * a[i] * (n - i + 1));
        if(las < 0) break;
        int l = a[1], r = a[i], res = a[1];
        while(l <= r) {
            int mid = (l + r) >> 1;
            int pos = lower_bound(a + 1, a + n + 1, mid) - a - 1;
            if(1ll * mid * pos - s[pos] <= las) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        ans = min(ans, a[i] - res);
    }
    print(ans, '\n');
    return 0;
}