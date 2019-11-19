#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
using namespace std;
 
const ll inf = 1e17;
const ll N = 1e5+10;
const ll bits = 30;
const ll mod = 1e9+7;


ll dp[N][2][2], dp2[N][2][2];


int main(){
    FASTIO;
    
    ll n,m;

    cin>>n>>m;

    ll ans = 0; // all different


    // horizontal

    dp[0][0][0] = 0; 
    dp[0][1][1] = 0; 

    dp[0][1][0] = 1;
    dp[0][0][1] = 1;

    for(int i=1;i<n;i++){
        dp[i][1][0] += (dp[i-1][0][0] + dp[i-1][0][1])%mod;
        dp[i][0][1] += (dp[i-1][1][0] + dp[i-1][1][1])%mod;
        dp[i][1][1] += dp[i-1][1][0]%mod;
        dp[i][0][0] += dp[i-1][0][1]%mod;
    }

    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            ans+=dp[n-1][i][j];
            ans%=mod;   
        }
    }



    dp2[0][0][0] = 0; 
    dp2[0][1][1] = 0; 

    dp2[0][1][0] = 1;
    dp2[0][0][1] = 1;

    for(int i=1;i<m;i++){
        dp2[i][1][0] += (dp2[i-1][0][0] + dp2[i-1][0][1])%mod;
        dp2[i][0][1] += (dp2[i-1][1][0] + dp2[i-1][1][1])%mod;
        dp2[i][1][1] += (dp2[i-1][1][0])%mod;
        dp2[i][0][0] += (dp2[i-1][0][1])%mod;
    }

    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            ans+=dp2[m-1][i][j]%mod;
            ans%=mod;
        }
    }

    cout<<(ans-2+mod)%mod<<"\n";

    

    

}