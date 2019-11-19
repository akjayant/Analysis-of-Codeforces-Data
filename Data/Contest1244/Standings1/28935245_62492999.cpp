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

const int N = 2e5 + 5;

char c[N], t[N], ans[N];
bool used[N];
int n, k, pos, len;

void check() {
    if(n & 1) return;
    for(register int i = 1; i < n; i++) if(c[i] == c[i + 1]) return;
    if(c[1] == c[n]) return;
    if(k % 2 == 0) {
        printf("%s\n", c + 1);
    } else {
        for(register int i = 1; i <= n; i++) {
            if(c[i] == 'W') c[i] = 'B';
            else c[i] = 'W';
        }
        printf("%s\n", c + 1);
    }
    exit(0);
}

int main() {
    read(n); read(k); scanf("%s", c + 1); check();
    for(register int i = 1; i < n; i++) if(c[i] == c[i + 1]) pos = i + 1;
    if(c[1] == c[n]) pos = 1;
    for(register int i = pos; i <= n; i++) t[++len] = c[i];
    for(register int i = 1; i < pos; i++) t[++len] = c[i];
    t[0] = t[1]; t[n + 1] = t[n];
    for(register int l = 1, r; l <= n; l = r + 1) {
        r = l;
        if(t[l] == t[l + 1]) { ans[l] = t[l]; continue; }
        while(t[r + 1] != t[r]) ++r;
        if(t[l] == t[r]) {
            if(k >= (r - l + 1) / 2) {
                for(register int j = l; j <= r; j++) ans[j] = t[l];
            } else {
                for(register int j = l; j <= l + k; j++) ans[j] = t[l];
                for(register int j = r; j >= r - k; j--) ans[j] = t[l];
                if(k & 1) {
                    for(register int j = l + k + 1; j <= r - k - 1; j++) {
                        if(t[j] == 'W') ans[j] = 'B';
                        else ans[j] = 'W';
                    }
                } else {
                    for(register int j = l + k + 1; j <= r - k - 1; j++) {
                        ans[j] = t[j];
                    }
                }
            }
        } else {
            if(k >= (r - l + 1) / 2 - 1) {
                int mid = (l + r) >> 1;
                for(register int j = l; j <= mid; j++) ans[j] = t[l];
                for(register int j = mid + 1; j <= r; j++) ans[j] = t[r];
            } else {
                for(register int j = l; j <= l + k; j++) ans[j] = t[l];
                for(register int j = r; j >= r - k; j--) ans[j] = t[r];
                if(k & 1) {
                    for(register int j = l + k + 1; j <= r - k - 1; j++) {
                        if(t[j] == 'W') ans[j] = 'B';
                        else ans[j] = 'W';
                    }
                } else {
                    for(register int j = l + k + 1; j <= r - k - 1; j++) {
                        ans[j] = t[j];
                    }
                }
            }
        }
    }
    for(register int i = n - pos + 2; i <= n; i++) putchar(ans[i]);
    for(register int i = 1; i <= n - pos + 1; i++) putchar(ans[i]);
    putchar('\n');
    return 0;
}