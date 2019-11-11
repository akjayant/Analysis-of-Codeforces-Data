#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int maxn=100010;
const int INF=0x3f3f3f3f;
char s[maxn];
ll dp[maxn][3];
int main()
{
    #ifdef local
    freopen("a.in","r",stdin);
    #endif // local
    while(~scanf("%s",s+1)){
        int n=strlen(s+1);
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            if(s[i]=='u'){
                dp[i][0]=dp[i-1][1];
                dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
                dp[i][1]%=mod;
                dp[i][2]=0;
            }
            else if(s[i]=='n'){
                dp[i][0]=dp[i-1][2];
                dp[i][1]=0;
                dp[i][2]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
                dp[i][2]%=mod;
            }
            else{
                dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
                dp[i][0]%=mod;
                dp[i][1]=dp[i][2]=0;
            }
        }
        ll ans=(dp[n][0]+dp[n][1]+dp[n][2])%mod;
        for(int i=1;i<=n;++i) if(s[i]=='m'||s[i]=='w') ans=0;
        printf("%lld\n",ans);
    }
    return 0;
}
