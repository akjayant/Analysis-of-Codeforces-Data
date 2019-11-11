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

const int N = 105;

char s[N], ans[N];
bool ok[N];
int T, n, a, b, c, cnt;

int main() {
    read(T);
    while(T--) {
        read(n); read(a); read(b); read(c);
        scanf("%s", s + 1);
        memset(ok, 0, sizeof(ok)); cnt = 0;
        for(register int i = 1; i <= n; i++) {
            if(s[i] == 'R' && b) {
                --b;
                ans[i] = 'P';
                ok[i] = 1;
                ++cnt;
            }
            if(s[i] == 'P' && c) {
                --c;
                ans[i] = 'S';
                ok[i] = 1;
                ++cnt;
            }
            if(s[i] == 'S' && a) {
                --a;
                ans[i] = 'R';
                ok[i] = 1;
                ++cnt;
            }
        }
        if(cnt >= (n + 1) / 2) {
            printf("YES\n");
            for(register int i = 1; i <= n; i++) {
                if(ok[i]) putchar(ans[i]);
                else if(a) putchar('R'), --a;
                else if(b) putchar('P'), --b;
                else putchar('S'), --c;
            }
            putchar('\n');
        } else printf("NO\n");
    }
    return 0;
}