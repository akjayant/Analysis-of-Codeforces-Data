#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define debug(x) cout<<#x<<" is "<<x<<endl;
const int maxn=1e5+5;
const ll mod=1e9+7;

char ch[maxn];
ll dp[maxn][2];

int main(){
    dp[0][1]=1;
    for(int i=1;i<=100000;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]=dp[i-1][0];
    }
    //debug(dp[2][0]);
    //debug(dp[2][1]);
    scanf("%s",ch);
    int n=strlen(ch);
    int F=1;
    ll ans=1;
    ll a1,a2;
    a1=a2=0;
    for(int i=0;i<n;i++){
        if(ch[i]=='w'||ch[i]=='m')F=0;
        else if(ch[i]=='u'){
            a1++;
            ans=ans*((dp[a2][0]+dp[a2][1])%mod)%mod;
            a2=0;
        }
        else if(ch[i]=='n'){
            a2++;
            ans=ans*((dp[a1][0]+dp[a1][1])%mod)%mod;
            a1=0;
        }
        else{
            ans=ans*((dp[a2][0]+dp[a2][1])%mod)%mod;
            ans=ans*((dp[a1][0]+dp[a1][1])%mod)%mod;
            //ians=ans*((dp[a1][0]+dp[a1][1]+dp[a2][0]+dp[a2][1])%mod)%mod;
            a1=a2=0;
        }
        //debug(ans);
        //debug(a2);
    }
    ans=ans*((dp[a2][0]+dp[a2][1])%mod)%mod;
    ans=ans*((dp[a1][0]+dp[a1][1])%mod)%mod;
    if(F)printf("%lld\n",ans);
    else printf("0\n");
    return 0;
}
