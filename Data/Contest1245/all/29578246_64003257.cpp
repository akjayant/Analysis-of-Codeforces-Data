#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll inf=(1ll<<61);
const ll mod=(1e9+7);
const int MX=3e5+9;
string s;
ll dp[MX];
ll DP(ll x){
    if(x <= 1)return 1;
    if(x == 2)return 2;
    ll &ret=dp[x];if(ret!=-1)return ret;
    return ret=(DP(x-1) + DP(x-2))%mod;
}
int main(){
    cin>>s;
    memset(dp,-1,sizeof(dp));
    for (auto pp:s){
        if (pp=='m'||pp=='w'){
            return cout <<0,0;
        }
    }
    vector<int>v;
    for (int i=0;i<s.size();i++){
        if (s[i]!='u'&&s[i]!='n') continue;
        ll d=0;
        for (int j=i;j<s.size();j++){
            if (s[j]==s[i]) d++;
            else break;
        }
        v.push_back(d);
        i+=d-1;
    }
    ll ans=1;
    for(auto pp:v){
        ans = (ans * DP(pp))%mod;
    }
    cout<<ans<<endl;
}
