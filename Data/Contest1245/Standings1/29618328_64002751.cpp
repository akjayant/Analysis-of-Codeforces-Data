#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
#define cases(t) for (int cas = 1; cas <= int(t); ++cas)
typedef long long ll;
typedef double db;
using namespace std;

#ifdef NO_ONLINE_JUDGE
#define LOG(args...) do { cout << #args << " -> "; err(args); } while (0)
void err() { cout << endl; }
template<typename T, typename... Args> void err(T a, Args... args) { cout << a << ' '; err(args...); }
#else
#define LOG(...)
#endif

const int N = 105;
char str[N];
char ans[N];
int a, b, c, n;
int r, p, s;

int main() {
    int t; scanf("%d", &t);
    cases(t) {
        scanf("%d", &n);
        scanf("%d%d%d", &a, &b, &c);
        scanf("%s", str);
        memset(ans, 0, sizeof ans);
        r = p = s = 0;
        for (int i = 0; i < n; ++i) {
            if (str[i] == 'R')	r++;
            if (str[i] == 'P')	p++;
            if (str[i] == 'S')	s++;
        }
        int res = min(a, s) + min(b, r) + min(c, p);
        if (res >= (n + 1) / 2) {
            puts("YES");
            for (int i = 0; i < n; ++i) {
                if (str[i] == 'R' && b > 0) {
                    ans[i] = 'P';
                    b--;
                }
                if (str[i] == 'P' && c > 0) {
                    ans[i] = 'S';
                    c--;
                }
                if (str[i] == 'S' && a > 0) {
                    ans[i] = 'R';
                    a--;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (ans[i] != 0)	continue;
                if (a > 0) {
                    ans[i] = 'R';
                    a--;
                } else if (b > 0) {
                    ans[i] = 'P';
                    b--;
                } else if (c > 0) {
                    ans[i] = 'S';
                    c--;
                }
            }
            for (int i = 0; i < n; ++i)	putchar(ans[i]);
            putchar('\n');
        } else {
            puts("NO");
        }
    }
    return 0;
}