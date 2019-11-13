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

const int N = 1e5 + 5, md = 1e9 + 7;

char c[N];
int f[N];
int n, ans = 1;

int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    for(register int i = 1; i <= n; i++) {
        if(c[i] == 'w' || c[i] == 'm') {
            print(0, '\n');
            return 0;
        }
    }
    f[0] = f[1] = 1;
    for(register int i = 2; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % md;
    for(register int l = 1, r; l <= n; l = r + 1) {
        if(c[l] != 'u' && c[l] != 'n') { r = l; continue; }
        r = l;
        while(r < n && c[r + 1] == c[l]) ++r;
        ans = 1ll * ans * f[r - l + 1] % md;
    }
    print(ans, '\n');
    return 0;
}