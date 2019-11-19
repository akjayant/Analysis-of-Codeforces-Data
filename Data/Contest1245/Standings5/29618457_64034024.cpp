#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct edge
{
    int fr,to;
	LL cost;
}e[4000010];
int n,x[2010],y[2010],c[2010],k[2010],tot;
int pa[2010],co[2010],bui[2010];
LL ans;
bool used[4000010];
bool cmp1(edge a,edge b)
{
    return a.cost<b.cost;
}
int find(int xx)
{
    int ansf=xx;
    while(pa[ansf]>0) ansf=pa[ansf];
    int pp=xx;
    while(pa[xx]>0)
    {
    	xx=pa[xx];
    	pa[pp]=ansf;
    	pp=xx;
	}
	return ansf;
}
void hebing(int i,int j)
{
    int pi=find(i),pj=find(j);
    if(pi==pj) return ;
    if(pa[pi]<pa[pj])
    {
        pa[pi]+=pa[pj];
        pa[pj]=pi;
        co[pi]=min(co[pi],co[pj]);
	}
	else
	{
	    pa[pj]+=pa[pi];
	    pa[pi]=pj;
	    co[pj]=min(co[pi],co[pj]);
	}
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d %d",&x[i],&y[i]);
    for (int i=1;i<=n;i++)
      scanf("%d",&c[i]);
    for (int i=1;i<=n;i++)
      scanf("%d",&k[i]);
    for (int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++)
      {
          tot++;
          e[tot].fr=i;
          e[tot].to=j;
          e[tot].cost=(LL)(abs(x[i]-x[j])+abs(y[i]-y[j]))*(LL)(k[i]+k[j]);
	  }
	sort(e+1,e+1+tot,cmp1);
	for(int i=1;i<=n;i++)
	{
	    pa[i]=-1;
	    co[i]=c[i];
	}
	for(int i=1;i<=tot;i++)
	{
	    if(find(e[i].fr)!=find(e[i].to))
	    {
	        if(e[i].cost<max(co[find(e[i].fr)],co[find(e[i].to)]))
	        {
	            hebing(e[i].fr,e[i].to);
	            used[i]=true;
	            ans+=e[i].cost;
			}
		}
	}
	for (int i=1;i<=n;i++)
	  if(pa[i]<0) ans+=co[i];
	cout << ans << endl;
	int tmp=0;
	for (int i=1;i<=n;i++)
	  if(pa[i]<0)
	  {
	      bui[i]=i;
	      tmp++;
	  }
	cout << tmp << endl;
	for(int i=1;i<=n;i++)
	{
	    if(c[i]<c[bui[find(i)]]) bui[find(i)]=i;
	}
	for(int i=1;i<=n;i++)
	{
	    if(pa[i]<0) cout << bui[i] << ' ';
	}
	cout << endl;
	tmp=0;
	for (int i=1;i<=tot;i++)
	  if(used[i]) tmp++;
	cout << tmp <<endl;
	for (int i=1;i<=tot;i++)
	  if(used[i])
	  {
	      cout<< e[i].fr << ' ' << e[i].to << endl;
	  }
    return 0;
}