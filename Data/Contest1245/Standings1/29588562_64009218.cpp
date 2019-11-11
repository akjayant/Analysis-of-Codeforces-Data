#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
#define fi first
#define se second
#define pb push_back
char a[N];
const LL mod=1e9+7;
LL ans=1;
LL dp[N];
int main() {
    ios::sync_with_stdio(false);
    dp[0]=dp[1]=1;
    for(int i=2;i<N;i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=mod;
    }
    cin>>a+1;
    int n=strlen(a+1);


    int sta=-1;
    LL res=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='m'||a[i]=='w'){
            return cout<<0<<endl,0;
        }
        if(a[i]=='u'){
            if(sta==-1){
                sta=1;
                res=1;
            }else {
                if(sta==1)res++;
                else {
                    ans=ans*dp[res];
                    ans%=mod;
                    sta=1;
                    res=1;
                }
            }
        }else if(a[i]=='n'){
            if(sta==-1){
                sta=0;
                res=1;
            }else{
                if(sta==0)res++;
                else{
                    ans=ans*dp[res];
                    res=1;
                    ans%=mod;
                    sta=0;
                }
            }
        }else {
            ans=ans*dp[res]%mod;
            sta=-1;
            res=0;
        }
    }
  //  cout<<ans<<' '<<res<<endl;
    ans=ans*dp[res]%mod;
    cout<<ans<<endl;
    return 0;
}