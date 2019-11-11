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

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'w' || s[i] == 'm'){
            cout << 0;
            return 0;
        }
    }
    vector<ll> dp(s.size() + 1);
    dp[0] = 1;
    for (int i = 1; i <= s.size(); i++){
        dp[i] += dp[i - 1];
        if (i > 1 && ((s[i - 1] == 'n' && s[i - 2] == 'n') || (s[i - 1] == 'u' && s[i - 2] == 'u'))) dp[i] += dp[i - 2];
        dp[i] %= M;
//        cerr << dp[i] << endl;
    }
    cout << dp[s.size()];
    return 0;
}
