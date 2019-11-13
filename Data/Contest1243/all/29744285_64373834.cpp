#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mk make_pair
using namespace std;
const int N = 1123456;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
inline long long read () {
    char c = getchar();
    long long t = 0, f = 1;
    while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    return t * f;
}
int a[N];
void solve() {
    int n, m, i, j;
    cin >> n;
    for(i = 1; i <= n; i ++) {
        a[i] = read();
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int mx = 1;
    for(i = 1; i <= n; i ++) {
        mx = max(mx, min(i, a[i]));
    }
    cout << mx << endl;
}
main()
{
    int t = read();
    while(t -- > 0) {
        solve();
    }
}



