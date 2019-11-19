#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i,A,B) for(int i=A;i<=B;i++)
#define mod 1000000007
#define v1d vector<int>
#define v1c vector<char>
#define v2d vector<vector<int>>
#define v1s vector<string>
#define vip vector<pair<int,int> >
#define v2p vector<vector<pair<int,int> > >
#define v2s vector<vector<string> >
#define vsp vector<pair<string,string> >
#define pa pair<int,int>

int fun(int n){
    v2d dp(n+5,v1d(3,0));
    dp[0][0]= 0;
    dp[1][1]= 0;
    dp[1][2]= 1;
    dp[2][1]= 1;dp[2][2]= 1;
    for(int i=3;i<=n;i++){
        dp[i][1]= dp[i-1][2]%mod;
        dp[i][2]= (dp[i-1][1]+dp[i-1][2])%mod;
    }
    int p= (2*(dp[n][1]+dp[n][2]))%mod;
    return p;
} 

int32_t main(){
    IOS;
    int p=0,q=0;
    int n,m;cin>>n>>m;
    int ans= fun(n);//cout<<ans<<endl;
    ans%= mod;
    ans+= fun(m);
    ans%= mod;
    ans= (ans-2+mod)%mod;
    cout<<ans;
    
    
    
    
    
    
    
    
    return 0;
}