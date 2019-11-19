#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 10, MOD = 1e9 + 7;
int n;

int get(string s)
{
    int x = 0, mn = 1e9, cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') x ++;
        else x --;
        if (x < mn) {
            mn = x;
            cnt = 1;
        }
        else if (x == mn) cnt++;
    }
    if (x != 0) return 0;
    else return cnt;
}

int32_t main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0, l = 0, r = 0; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i ++) {
        for (int j = i; j < n; j ++) {
            swap(s[i], s[j]);
            int x = get(s);
            if (x > ans) ans = x, l = i, r = j;
            swap(s[i], s[j]);
        }
    }
    cout << ans << " " << l + 1 << " " << r + 1 << "\n";
}
