#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define ll long long
#define rep(i, a, b) for (int i = a; i <= (int)b; i ++)
void read(int & x) {
    x = 0; int flag = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
void read(ll & x) {
    x = 0; int flag = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
using namespace std;
int n, m, cnt[2][2], a[100010], b[100010];
int main()
{
    int T;
    read(T);
    while(T --) {
        ll ans = 0;
        rep(i, 0, 1) rep(j, 0, 1) cnt[i][j] = 0;
        read(n);
        rep(i, 1, n) read(a[i]), cnt[0][a[i] % 2] ++;
        read(m);
        rep(i, 1, m) read(b[i]), cnt[1][b[i] % 2] ++;
        rep(i, 1, n) ans += cnt[1][a[i] % 2];
        printf("%lld\n", ans);
    }
    return 0;
}