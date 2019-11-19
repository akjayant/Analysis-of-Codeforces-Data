#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
ll n,k;
int seg[1000100*4];
int ans[1000100];
int l,r;
void build(int cr,int s,int e){
    if(s==e)
    {
        seg[cr]=s;
        return;
    }
    build(cr*2,s,(s+e)/2);
    build(cr*2+1,(s+e)/2+1,e);
    seg[cr]=min(seg[cr*2],seg[cr*2+1]);
}
int take(int cr,int s,int e){
    if(l>e||r<s)
        return 1e7;
    if(l<=s&&e<=r)
    {
        return seg[cr];
    }
    return min(take(cr*2,s,(s+e)/2),take(cr*2+1,(s+e)/2+1,e));
}
void upd(int cr,int s,int e)
{
    if(l>e||r<s)
        return;
    if(l<=s&&e<=r)
    {
         seg[cr]=1e7;
        return;
    }
    upd(cr*2,s,(s+e)/2);
    upd(cr*2+1,(s+e)/2+1,e);
    seg[cr]=min(seg[cr*2],seg[cr*2+1]);
}
int main(){
    cin>>n>>k;
    build(1,1,n);
    if(n*(n+1)/2>k)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ans[i]=i;
    }
    ll a=n*(n+1)/2;
    for(int i=n;i>=1;i--)
    {
        if(ans[i]==i)
        {   l=max(1LL,i-(k-a));r=i;
            int u=take(1,1,n);
            if(u<i)
            {   ll d=a+(i-u);
                if(d<=k)
                    a=d;
                ans[u]=i;
                ans[i]=u;
                l=u;r=u;
                upd(1,1,n);

            }
        }
    }
    cout<<a<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
    }
//
