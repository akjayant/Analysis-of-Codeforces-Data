#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fi first
#define sec second
#define pb push_back
#define pi pair <int, int>
#define len length()

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int ans = (a + c - 1) / c + (b + d - 1) / d;
    if (ans > k)
        cout << "-1\n";
    else
        cout << (a + c - 1) / c << " " << (b + d - 1) / d << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    loop(i,t )
    solve();
    return 0;
}
