#include <bits/stdc++.h>
#define N 100005
typedef long long ll;
using namespace std;

const ll mod=1e9+7;

char s[N];
ll dp[N];

int main(){
    scanf("%s",s+1);
    ll n=strlen(s+1);
    for(ll i=1;i<=n;i++){
        if(s[i]=='w'||s[i]=='m'){
            puts("0"); return 0;
        }
    }
    ll ans=1;
    dp[0]=dp[1]=1;
    for(ll i=2;i<=100000;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
    for(ll i=1,j;i<=n;i++){
        if(s[i]=='u'||s[i]=='n'){
            ll now=0;
            for(j=i;j<=n;j++){
                if(s[j]!=s[i]) break;
                now++;
            }
            ans=ans*dp[now]%mod;
            i=j-1;
        }
    }
    cout<<ans<<endl;
}
