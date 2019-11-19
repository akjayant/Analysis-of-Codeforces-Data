#include  <bits/stdc++.h>
using namespace std;
#define ll long long

inline ll read() {
    ll x = 0, y = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') y = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch & 15); ch = getchar(); }
    return x * y;
}

ll T, cnt1, cnt2, cnt3, cnt4, n, m;
int main() {
    register int i;
    T = read();
    while (T --) {
        cnt1 = cnt2 = cnt3 = cnt4 = 0;
        n = read(); 
        for (i = 1; i <= n; i ++) {
            int x = read();
            if (x % 2) cnt1 ++;
            else cnt2 ++;
        }
        m = read();
        for (i = 1; i <= m; i ++) {
            int x = read();
            if (x % 2) cnt3 ++;
            else cnt4 ++;
        }
        cout << cnt1 * cnt3 + cnt2 * cnt4 << endl;
    }
    return 0;
}