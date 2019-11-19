#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define int long long

using namespace std;

const int N = 300707;
int n, m;
int dp1[N];
int dp2[N];
int md = 1e9 + 7;
signed main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("diameter.in", "r", stdin);
    //freopen("diameter.out", "w", stdout);
    cin >> n >> m;
    int t = max(n, m);
    dp1[1] = 2;
    dp2[1] = 0;
    for (int i = 2; i <= t; i++){
        dp1[i] = dp1[i - 1] + dp2[i - 1];
        dp2[i] = dp1[i - 1];
        dp1[i] %= md;
        dp2[i] %= md;
    }

    int ans = dp1[n] + dp1[m] + dp2[n] + dp2[m] - 2;
    ans  = ans % md;
    while (ans < 0){
        ans += md;
    }

    cout << ans << endl;
    return 0;
}
