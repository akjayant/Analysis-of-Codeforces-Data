#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll maxn=1e5+5;
ll dp[maxn];
int main(){
    ios::sync_with_stdio(0);
    ll t,i,t1,t2,t3,a,b,c,n;
    string s;
    cin>>s;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int flag=0;
    for (i=0;i<s.size();i++){
        if (s[i]=='m'||s[i]=='w')
            flag=1;
        if (i<s.size())
            dp[i+1]=(dp[i+1]+dp[i])%mod;
        if (i+1<s.size()&&s[i]==s[i+1]&&(s[i]=='u'||s[i]=='n'))
            dp[i+2]=(dp[i+2]+dp[i])%mod;
    }
    if (flag)
        cout<<"0\n";
    else cout<<dp[s.size()]<<'\n';
}
