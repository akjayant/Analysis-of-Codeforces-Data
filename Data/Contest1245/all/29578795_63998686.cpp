#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    
    string s;
    cin>>s;
    ll n=s.size();
    ll mod = 1e9+7;
    ll dp[n+1][2]={};
    dp[0][0]=1;
    bool pos = false;
    if(s[0]=='m' || s[0]=='w') pos=true;
    for(int i=1;i<n;i++){
        dp[i][0] += dp[i-1][0] + dp[i-1][1];
        if(s[i]=='u' && s[i-1]=='u'){
            dp[i][1] += dp[i-1][0];
        }
        if(s[i]=='n' && s[i-1]=='n'){
            dp[i][1] += dp[i-1][0];
        }
        if(s[i]=='w' || s[i]=='m') pos = true;
        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
    if(pos){
        cout << 0 << endl;
        return 0;
    }
    ll ans = dp[n-1][0] + dp[n-1][1];
    ans %= mod;
    cout << ans << endl;
}