#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod = 1000000007;
    string s;
    cin>>s;
    int l = s.length();
    vector<ll> dp(l, 0);
    dp[0] = 1;
    if(s[0]=='w'||s[0]=='m'){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1; i<l; i++){
        dp[i] = dp[i-1];
        dp[i] %=mod;
        if(s[i]=='u'){
            if(s[i-1]=='u'){
                if(i>=2){
                    dp[i] += dp[i-2];
                } else {
                    dp[i] += 1;
                }
                dp[i]%=mod;
            }
        } else if(s[i]=='n'){
            if(s[i-1]=='n'){
                if(i>=2){
                    dp[i] += dp[i-2];
                } else {
                    dp[i] += 1;
                }
                dp[i]%=mod;
            }
        } else if(s[i]=='m'){
            cout<<0<<endl;
            return 0;
        } else if(s[i]=='w'){
            cout<<0<<endl;
            return 0;
        }
        dp[i]%=mod;
    }
    cout<<(dp[l-1]+mod)%mod<<endl;
    return 0;
}