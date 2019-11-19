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
const int maxn = 510;
int ans = 0, ax = 1, ay = 1, n, pre[maxn], suf[maxn], a[maxn];
char s[maxn];
bool ok[maxn];
void calc(int aa, int b) {
    //if(aa != 1 || b != 10) return;
    pre[0] = n;
    //rep(i, 1, n) cout << s[i]; puts("");
    rep(i, 1, n) {
        if(s[i] == '(') a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
        pre[i] = min(pre[i - 1], a[i]);
    }
    suf[n + 1] = 0;
    int tmp = 0;
    for(int i = n; i; i --) {
        suf[i] = s[i] == '(' ? suf[i + 1] + 1 : suf[i + 1] - 1;
        if(s[i] == '(') tmp ++; else tmp = min(tmp - 1, -1);
        ok[i] = tmp >= 0 ? 1 : 0;
    }
    int cnt = 0;
    if(pre[n] == 0) cnt = 1;
    rep(i, 2, n)
        if(ok[i] && suf[i] + pre[i - 1] >= 0) cnt ++;//, cout << i << " "; cout << endl;
    if(cnt > ans) ax = aa, ay = b, ans = cnt;
    //rep(i, 1, n) cout << pre[i] << " "; puts("");
    //rep(i, 1, n) cout << ok[i] << " "; puts("");
    //rep(i, 1, n) cout << suf[i] << " "; puts("");
}
int main()
{
    read(n);
    scanf("%s", s + 1);
    pre[0] = 0;
    rep(i, 1, n) {
        if(s[i] == '(') a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
        if(a[i] >= 0) pre[i] = min(pre[i - 1], a[i]);
    }
    if(a[n] != 0) {
        puts("0\n1 1\n");
        return 0;
    }
    rep(i, 1, n) {
        int tmp = 0;
        rep(j, i, n) {
            tmp += s[i] == '(' ? 1 : -1;
            if(tmp < 0) break;
        }
        suf[i] = tmp;
    }
    calc(1, 1);
    rep(i, 1, n) rep(j, i + 1, n) {
        if(s[i] == s[j]) continue;
        swap(s[i], s[j]);
        calc(i, j);
        swap(s[i], s[j]);
    }
    printf("%d\n", ans);
    printf("%d %d\n", ax, ay);
    return 0;
}