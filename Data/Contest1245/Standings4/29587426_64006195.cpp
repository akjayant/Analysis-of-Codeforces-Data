#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
const ll MOD = 1e9+7;

int main(){
    fastio;
    string s;
    cin>>s;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i] == 'm' || s[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }
    }
    vector<unsigned int> dp(n+1,1);
    for(int i=1;i<n;i++){
        dp[i+1] = dp[i]%MOD;
        if(s[i] == 'u' && s[i-1]=='u'){
            dp[i+1] = (dp[i+1]+dp[i-1])%MOD;
        }
        if(s[i] == 'n' && s[i-1] == 'n'){
            dp[i+1] = (dp[i+1]+dp[i-1])%MOD;
        }
    }
    cout << dp[n]%MOD << endl;
    return 0;
}