#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

string s;
int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n = s.size();
    s = ';' + s;
    vector <int> dp(n + 1);
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        if(s[i] == 'm' || s[i] == 'w') finish(0);
        dp[i] = dp[i - 1];
        if((s[i] == 'n' && s[i - 1] == 'n') || (s[i] == 'u' && s[i - 1] == 'u')){
            dp[i] += dp[i - 2];
        }
        if(dp[i] >= mod) dp[i] -= mod;
    }
    cout << dp[n] << endl;
}
