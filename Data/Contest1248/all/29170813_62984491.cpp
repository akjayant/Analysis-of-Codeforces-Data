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
    x = 0; int flag = 1; char ch = ' ';
    while (ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
void read(ll & x) {
    x = 0; int flag = 1; char ch = ' ';
    while (ch < '0' || ch > '9') { if(ch == '-') flag = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    x *= flag;
}
using namespace std;
int n, a[100010], b[100010];
int main()
{
    read(n);
    rep(i, 1, n) read(a[i]);
    sort(a + 1, a + 1 + n);
    ll sa = 0, sb = 0;
    int m = n / 2;
    rep(i, 1, m) sa += a[i];
    rep(i, m + 1, n) sb += a[i];
    printf("%lld\n", sa * sa + sb * sb);
    return 0;
}