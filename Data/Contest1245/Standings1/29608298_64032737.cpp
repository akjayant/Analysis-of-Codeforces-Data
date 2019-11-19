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

int h[11][11];
ld dp[11][11];
ld dp2[11][11];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) cin >> h[i][j];

    vector<ld> d;
    dp[0][0] = 0;
    dp[0][1] = 6;
    dp[0][2] = 6;
    dp[0][3] = 6;
    dp[0][4] = 6;
    dp[0][5] = 6;
    dp2[0][0] = 0;
    dp2[0][1] = 6;
    dp2[0][2] = 6;
    dp2[0][3] = 6;
    dp2[0][4] = 6;
    dp2[0][5] = 6;
    d.pb(dp[0][5]);
    d.pb(dp[0][4]);
    d.pb(dp[0][3]);
    d.pb(dp[0][2]);
    d.pb(dp[0][1]);
    d.pb(dp[0][0]);
    for (int i = 0; i < 10; i++){
        if (i%2 == 0){
            for (int j = (i == 0 ? 6 : 0); j < 10; j++){
                ld s = 0;
                for (int l = 0; l < 6; l++) s += d[l];
                dp[i][j] = (ld)s/(ld)6 + 1;
                dp2[i][j] = (ld)s/(ld)6 + 1;
                if (h[i][j] != 0) dp[i][j] = min(dp[i][j], dp2[i - h[i][j]][j]);
                d.pop_back();
                d.pb(dp[i][j]);
                for (int l = 4; l >= 0; l--) swap(d[l], d[l + 1]);
//                cerr << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
        else {
            for (int j = 9; j >= 0; j--){
                ld s = 0;
                for (int l = 0; l < 6; l++) s += d[l];
                dp[i][j] = (ld)s/(ld)6 + 1;
                dp2[i][j] = (ld)s/(ld)6 + 1;
                if (h[i][j] != 0) dp[i][j] = min(dp[i][j], dp2[i - h[i][j]][j]);
                d.pop_back();
                d.pb(dp[i][j]);
                for (int l = 4; l >= 0; l--) swap(d[l], d[l + 1]);
//                cerr << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
    }
    cout << fixed << setprecision(10) << dp[9][0];
    return 0;
}
