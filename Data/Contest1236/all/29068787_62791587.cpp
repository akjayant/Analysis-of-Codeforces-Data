#include <bits/stdc++.h>
#define lson root<<1
#define rson root<<1|1
using namespace std;
//priority_queue<int,vector<int>,greater<int> > q;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+7;
const int mod=1e9+7;
ll quit(ll n,ll m)
{
    ll ans=1;
    while(m){
        if(m&1) ans=ans*(n%mod)%mod;
        n=(n%mod)*(n%mod)%mod;
        m>>=1;
    }
    return ans;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ll ans=quit(quit(2,m)-1,n);
    printf("%lld\n",ans);
    return 0;
}
