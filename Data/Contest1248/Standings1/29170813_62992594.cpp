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
const int mod = 1e9 + 7;
int n, m;
ll f[100010];
int main()
{
    read(n), read(m);
    f[0] = 1, f[1] = 1;
    rep(i, 2, max(n, m)) f[i] = (f[i - 1] + f[i - 2]) % mod;
    printf("%lld\n", (f[n] * 2 + f[m] * 2 - 2) % mod);
    return 0;
}