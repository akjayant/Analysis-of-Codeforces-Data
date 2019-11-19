#include<bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld double
#define null nullptr
#define endl '\n'

using namespace std;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e5 + 7;
const int M = 1e9 + 7;

int t;
ll l, r;
ll dp[33][2][2];

ll solve(ll a, ll b){
    if (a < 0 || b < 0) return 0;
    for (int i = 0; i < 33; i++){
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
        dp[i][1][0] = 0;
        dp[i][1][1] = 0;
    }
    vector<int> x, y;
    if (!a) x.pb(0);
    if (!b) y.pb(0);
    while (a){
        x.pb(a%2);
        a /= 2;
    }
    while (b){
        y.pb(b%2);
        b /= 2;
    }
    while (x.size() < y.size()) x.pb(0);
    while (x.size() > y.size()) y.pb(0);
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    dp[0][1][1] = 1;
    int n = x.size();
    for (int i = 0; i < n; i++){
        for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
        for (int ta = 0; ta < 2; ta++)
        for (int tb = 0; tb < 2; tb++){
            if ((ta^tb) == (ta + tb)){
                if (a == 1 && ta > x[i]) continue;
                if (b == 1 && tb > y[i]) continue;
                int na = a*(ta == x[i]);
                int nb = b*(tb == y[i]);
                dp[i + 1][na][nb] += dp[i][a][b];
            }
        }
    }
    return dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    cin >> t;
    while (t--){
        cin >> l >> r;
//        cerr << solve(l - 1, l - 1) << endl;
        cout << solve(r, r) - 2ll*solve(r, l - 1) + solve(l - 1, l - 1) << endl;
    }
    return 0;
}
