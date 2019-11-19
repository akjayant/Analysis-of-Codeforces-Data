#include <bits/stdc++.h>
using namespace std;
void solve () {
    int n; cin >> n;
    string s; cin >> s;
    s = "#" + s;
    int fi = -1, lst = n + 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1' && fi == -1) fi = i;
        if (s[i] == '1') lst = i;
    }
    if (lst == n + 1) {
        cout << n << endl;
        return;
    }
    int ans = lst + max(lst, n - lst + 1);
    ans = max(ans, (n - fi + 1) + max(fi, n - fi + 1));
    cout << ans << endl;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(n--) solve();
}