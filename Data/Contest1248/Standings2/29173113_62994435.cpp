#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define zoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    zoom;
    ll n, m, i;
    cin >> n >> m;
    vector<vector<ll> > dp1(m, vector<ll>(4, 0));
    dp1[m - 1][1] = 1;
    dp1[m - 1][2] = 1;
    for(i = m - 2; i >= 0; i -= 1) {
    	dp1[i][0] = dp1[i + 1][1];
    	dp1[i][1] = (dp1[i + 1][2] + dp1[i + 1][3]) % MOD;
    	dp1[i][2] = (dp1[i + 1][0] + dp1[i + 1][1]) % MOD;
    	dp1[i][3] = dp1[i + 1][2];
    }
    vector<vector<ll> > dp2(n, vector<ll>(4, 0));
    dp2[n - 1][1] = 1;
    dp2[n - 1][2] = 1;
    for(i = n - 2; i >= 0; i -= 1) {
    	dp2[i][0] = dp2[i + 1][1];
    	dp2[i][1] = (dp2[i + 1][2] + dp2[i + 1][3]) % MOD;
    	dp2[i][2] = (dp2[i + 1][0] + dp2[i + 1][1]) % MOD;
    	dp2[i][3] = dp2[i + 1][2];
    }
    ll one = ((dp1[0][0] + dp1[0][1]) % MOD + (dp1[0][2] + dp1[0][3]) % MOD) % MOD;
    ll two = ((dp2[0][0] + dp2[0][1]) % MOD + (dp2[0][2] + dp2[0][3]) % MOD) % MOD;
    cout << ((one + two) % MOD - 2 + MOD) % MOD;
    return 0;
}