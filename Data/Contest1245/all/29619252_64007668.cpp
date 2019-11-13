#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int dp[N],ans=1;
int main()
{
    string s;
    cin>>s;
    int sz=s.size();
    for(int i=0;i<sz;i++){
        if(s[i]=='m'||s[i]=='w'){
            printf("0\n");
            exit(0);
        }
    }
    dp[0]=1,dp[1]=1;
    for(int i=2;i<N;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    bool u=false,n=false;
    int st,en;
    for(int i=0;i<s.size();i++){
        if(s[i]=='u'&&(i==0||s[i-1]!='u')){
            u=true;
            st=i;
        }
        if(s[i]=='n'&&(i==0||s[i-1]!='n')){
            n=true;
            st=i;
        }
        if(u){
            if(s[i]=='u'&&(i==sz||s[i+1]!='u')){
                u=false;
                en=i;
                ans=((ll)ans*dp[en-st+1])%mod;
            }
        }
        if(n){
            if(s[i]=='n'&&(i==sz||s[i+1]!='n')){
                n=false;
                en=i;
                ans=((ll)ans*dp[en-st+1])%mod;
            }
        }

    }
    printf("%d\n",ans);
    return 0;
}
