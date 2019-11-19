#include <bits/stdc++.h>
#define ll long long
#define lf long double
#define INF 1000000000
#define MAX 100001
#define M 1000000007
using namespace std;

ll last;

ll dp[MAX][2][3];

ll DP(ll i, ll prev, ll cnt) {
    if (i==last) return 1LL;
    if (dp[i][prev][cnt]!=0) return dp[i][prev][cnt];
    if (cnt==2) return dp[i][prev][cnt] = DP(i+1, prev^1, 1);
    dp[i][prev][cnt] = (DP(i+1, prev, 2) + DP(i+1, prev^1, 1))%M;
    if (dp[i][prev][cnt]<0) dp[i][prev][cnt]+=M;
    return dp[i][prev][cnt];
}

int main() {
    ll n, m;
    cin >> n >> m;
    last = n;
    for (ll i=0;i<MAX;i++) {
        for (ll prev = 0;prev<2;prev++) {
            for (ll cnt = 0;cnt<3;cnt++) dp[i][prev][cnt] = 0;
        }
    }
    ll res = (DP(1, 0, 1) + DP(1, 1, 1))%M;
    if (res<0) res+=M;
    last = m;
    for (ll i=0;i<MAX;i++) {
        for (ll prev = 0;prev<2;prev++) {
            for (ll cnt = 0;cnt<3;cnt++) dp[i][prev][cnt] = 0;
        }
    }
    res+= (DP(1, 0, 1) + DP(1, 1, 1))%M;
    res=(res-2)%M;
    if (res<0) res+=M;
    cout << res << endl;
    return 0;
}