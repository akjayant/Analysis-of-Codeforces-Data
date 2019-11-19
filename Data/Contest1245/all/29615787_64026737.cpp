#include<algorithm>
#include<cstdio>
#define MaxN 2050
using namespace std;
long long l[MaxN][MaxN],dis[MaxN],ans;
int n,x[MaxN],y[MaxN],k[MaxN],vis[MaxN];
int sav[MaxN],tn,las[MaxN],tot;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i++)scanf("%I64d",&dis[i]);
	for (int i=1;i<=n;i++)scanf("%d",&k[i]);
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	    if (i!=j){
	      l[i][j]=1ll*(k[i]+k[j])*
                ((x[i]<x[j] ? x[j]-x[i] : x[i]-x[j])+
	               (y[i]<y[j] ? y[j]-y[i] : y[i]-y[j]));
      }
  dis[0]=1ll<<60;
  for (int qt=1;qt<=n;qt++){
    int u=0;
    for (int i=1;i<=n;i++)
      if (vis[i]!=1&&dis[i]<dis[u])u=i;
    ans+=dis[u];
    if (vis[u]==0)sav[++tn]=u;
    else {
      x[++tot]=u;
      y[tot]=las[u];
    }
    vis[u]=1;
    for (int i=1;i<=n;i++)
      if (l[u][i]<dis[i]){
        if (vis[i]==0)vis[i]=2;
        las[i]=u;
        dis[i]=l[u][i];
      }
  }printf("%I64d\n",ans);
  printf("%d\n",tn);
  for (int i=1;i<=tn;i++)printf("%d ",sav[i]);puts("");
  printf("%d\n",tot);
  for (int i=1;i<=tot;i++)
    printf("%d %d\n",x[i],y[i]);
  return 0;
}
