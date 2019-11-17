using namespace std;
typedef long long ll;
const int md = 1e9 + 7;

int n;
string p, t;

void solve() {
    cin >> p; n = int(p.size());
    for(int i=0;i<n;++i) if(p[i] == 'm' || p[i] == 'w') {cout << 0 << endl; return;}
    int dp[n+1]; memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i=0;i<n;++i) {
        (dp[i+1] += dp[i]) %= md;
        if(i+1 < n && (p[i] == 'n' && p[i+1] == 'n' || p[i] == 'u' && p[i+1] == 'u')) (dp[i+2] += dp[i]) %= md;
    }
    cout << dp[n] << endl;
}

int main() {




    ios_base :: sync_with_stdio(0);
    int tt = 1;

    while(tt--) solve();
}
