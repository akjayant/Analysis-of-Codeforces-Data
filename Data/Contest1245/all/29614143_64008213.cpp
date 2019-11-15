#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxx=1e5+10;
char s[maxx];
ll dp[maxx];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=mod;
    }
    ll ans=1; char pre; int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='m'||s[i]=='w'){
            return 0*puts("0");
        }
        if(s[i]==pre){
            cnt++;
        }else{
            if(pre=='n'||pre=='u')ans=ans*dp[cnt]%mod;
            pre=s[i]; cnt=1;
        }
    }
    if(pre=='u'||pre=='n') ans=ans*dp[cnt]%mod;
    cout<<ans<<endl;
}
