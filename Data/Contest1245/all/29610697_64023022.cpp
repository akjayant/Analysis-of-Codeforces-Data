#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct
{
	ll u,v,w;
}edg;
edg s[5000005];
vector<ll> ansp,ansv;
ll n,m,x[2005],y[2005],c[2005],k[2005],tot,fa[2005],ans,o,uu,vv,cnt;
inline bool tmb(const edg&p1,const edg&p2)
{
	return p1.w<p2.w;
}
ll find(ll x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)cin>>c[i],tot++,s[tot].u=n+1,s[tot].v=i,s[tot].w=c[i];
	for(int i=1;i<=n;i++)cin>>k[i];
	for(int i=1;i<=n;i++)
	 for(int j=i+1;j<=n;j++)
	 tot++,s[tot].u=i,s[tot].v=j,s[tot].w=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
	sort(s+1,s+tot+1,tmb);
	for(int i=1;i<=n+1;i++)fa[i]=i;
	cnt=n;
    for(int i=1;i<=tot;i++)
    {
    	uu=find(s[i].u);
	    vv=find(s[i].v);
	    if(uu==vv)continue;
	    fa[uu]=vv;
	    cnt--;
	    ans+=s[i].w;
	    if(s[i].u==n+1)ansp.push_back(s[i].v);else ansv.push_back(i);
    	if(!cnt)break;
    }
    cout<<ans<<endl;
	o=ansp.size();
    cout<<o<<endl;
    for(int i=0;i<o;i++)cout<<ansp[i]<<' ';
    cout<<endl;
    o=ansv.size();
    cout<<o<<endl;
    for(int i=0;i<o;i++)cout<<s[ansv[i]].u<<' '<<s[ansv[i]].v<<endl;
    return 0;
}
