#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define ll long long
#define int long long
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int solve(string s){
    if(s.size()<2) return 1;
    int dp[s.size()+1];
    for (int i = 0; i < s.size()+1; ++i)
    {
        dp[i]=1;
    }
    for (int i = s.size()-2; i >= 0; --i)
    {
        if(s[i]==s[i+1] && s[i]=='n') dp[i]=dp[i+1]+dp[i+2];
        else if(s[i]==s[i+1] && s[i]=='u') dp[i]=dp[i+1]+dp[i+2];
        else dp[i]=dp[i+1];
        dp[i]%=mod;
    }
    return dp[0]%mod;
}

signed main(){
    ios_base::sync_with_stdio(false); //fast io
    cin.tie(NULL);
    
    string s; 
    cin>>s;
    for (int i = 0; i < s.size(); ++i)
    {
        if(s[i]=='w' || s[i]=='m'){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<solve(s)%mod<<endl;
    return 0;
}
