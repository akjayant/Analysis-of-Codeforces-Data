#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pll pair<ll, ll>
#define ppii pair<pii, pii>
using namespace std;
const int N=1e5+1;
const ll mod=1e9+7;
int n;
char c[2]={'u', 'n'};
ll dp[N], ans=1;
string s;
bool chk()
{
    for(int i=0; i<s.size(); i++){
        if(s[i]=='m'||s[i]=='w') return 1;
    }
    return 0;
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("sol.inp", "r", stdin);
    //freopen("sol.out", "w", stdout);
    cin>>s;
    n=s.size();
    dp[0]=dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    if(chk()) ans=0;
    else{
        int cnt=0;
        for(int i=0; i<=1; i++){
            cnt=0;
            for(int j=0; j<s.size(); j++){
                if(s[j]==c[i]) cnt++;
                else{
                    ans=(ans*dp[cnt])%mod;
                    cnt=0;
                }
            }
            ans=(ans*dp[cnt])%mod;
        }
    }
    cout<<ans<<'\n';
}
