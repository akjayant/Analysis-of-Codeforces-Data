#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
typedef long long ll;
const ll inf=1e17;
ll a[maxn+5],b[maxn+5];
ll pre[maxn+5],suf[maxn+5];
ll preb[maxn+5],sufb[maxn+5];
int n;
ll k;
ll check(int mid,ll *a,ll *pre,ll *suf)
{
    ll ans=inf;
    for(int i=1;i<=n;++i)
    {
        ll res=i*a[i]-pre[i];
        int id=lower_bound(a+1,a+n+1,a[i]+mid)-a;
        if(id>n) ans=min(ans,res);
        else
        {
            res+=suf[id]-(a[i]+mid)*(n-id+1);
            ans=min(ans,res);
        }
    }
    return ans;
}
int main()
{
   // freopen("ce.in","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;++i) scanf("%lld",&a[i]),b[i]=-a[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i],preb[i]=preb[i-1]+b[i];
    for(int i=n;i>=1;--i) suf[i]=suf[i+1]+a[i],sufb[i]=sufb[i+1]+b[i];
    int l=0,r=1e9,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        ll ans=min(check(mid,a,pre,suf),check(mid,b,preb,sufb));
        if(ans<=k) r=mid;else l=mid+1;
    }
    cout<<r<<endl;
    return 0;
}
