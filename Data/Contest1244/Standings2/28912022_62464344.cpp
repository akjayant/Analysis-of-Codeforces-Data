#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int main ()
{
    ios::sync_with_stdio(false);
    int T,a,b,c,d,kk;cin >> T;
    while (T--)
    {
        cin >> a >> b >> c >> d >> kk;
        int ans1 = (a + c - 1) / c,ans2 = (b + d - 1) / d;
        if (ans1 + ans2 > kk) cout << -1 << endl;
        else cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}