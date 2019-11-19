#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int maxn=35;
int bitA[maxn],bitB[maxn];
ll dp[maxn][2][2][2];
inline ll dfs(int pos,int st,int flagA,int flagB)
{
    if(!pos) return st;
    if(dp[pos][st][flagA][flagB]!=-1) return dp[pos][st][flagA][flagB];
    int upA=flagA?1:bitA[pos],upB=flagB?1:bitB[pos];
    ll ans=0;
    for(int i=0;i<=upA;++i){
        for(int j=0;j<=upB;++j){
            ans+=dfs(pos-1,st|(i&j),flagA||i<upA,flagB||j<upB);
            //cout<<pos<<' '<<i<<' '<<j<<' '<<dfs(pos-1,st|(i&j),flagA||i<upA,flagB||j<upB)<<endl;
        }
    }
    return dp[pos][st][flagA][flagB]=ans;
}
inline ll solve(ll L,ll R)
{
    memset(dp,-1,sizeof(dp));
    ll ans=(L+1)*(R+1);
    int lenA=0,lenB=0;
    while(L){bitA[++lenA]=L&1;L>>=1;}
    while(R){bitB[++lenB]=R&1;R>>=1;}
    while(lenA<lenB) bitA[++lenA]=0;
    while(lenB<lenA) bitB[++lenB]=0;
    return ans-dfs(lenA,0,0,0);
}
int main()
{
    #ifdef local
    freopen("a.in","r",stdin);
    #endif // local
    int t,l,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&l,&r);
        ll ans=solve(r,r);
        if(l){
            ans-=solve(l-1,r)*2;
            ans+=solve(l-1,l-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
