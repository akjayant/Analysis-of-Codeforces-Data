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

const int N = 40;

ll f[N][2][2];
int T, l, r;

ll solve(int a, int b) {
    if(a == -1 || b == -1) return 0;
    memset(f, 0, sizeof(f));
    f[0][0][0] = f[0][0][1] = f[0][1][0] = f[0][1][1] = 1;
    for(register int i = 0; i <= 29; i++) {
        for(register int j = 0; j <= 1; j++) {
            for(register int k = 0; k <= 1; k++) {
                for(register int x = 0; x <= 1; x++) {
                    for(register int y = 0; y <= 1; y++) {
                        if(x && y) continue;
                        if(j && x > ((a >> i) & 1)) continue;
                        if(k && y > ((b >> i) & 1)) continue;
                        f[i + 1][j][k] += f[i][j && (x == ((a >> i) & 1))][k && (y == ((b >> i) & 1))];
                    }
                }
            }
        }
    }
    return f[30][1][1];
}

int main() {
    read(T);
    while(T--) {
        read(l); read(r);
        print(solve(r, r) - solve(r, l - 1) * 2 + solve(l - 1, l - 1), '\n');
    }
    return 0;
}