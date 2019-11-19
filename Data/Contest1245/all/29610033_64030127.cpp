#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[2005],b[2005],root[2005],fa[2005];
ll ans=0,lowcost[2005],w[2005];
vector<int> e[2005];
int main(){
	int i,j,k,sz;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for (i=1;i<=n;i++) scanf("%lld",&lowcost[i]);
	for (i=1;i<=n;i++) scanf("%lld",&w[i]);
	root[0]=0;
	lowcost[0]=2000000000;
	for (i=1;i<=n;i++){
		for (j=1,k=0;j<=n;j++)
		if (lowcost[j]&&lowcost[j]<lowcost[k]) k=j;
		if (!fa[k]) root[++root[0]]=k;
		else e[fa[k]].push_back(k);
		ans+=lowcost[k];
		lowcost[k]=0;
		for (j=1;j<=n;j++)
		if ((w[k]+w[j])*(abs(a[k]-a[j])+abs(b[k]-b[j]))<lowcost[j])
		lowcost[j]=(w[k]+w[j])*(abs(a[k]-a[j])+abs(b[k]-b[j])),fa[j]=k;
	}
	printf("%lld\n%d\n",ans,root[0]);
	for (i=1;i<=root[0];i++) printf("%d ",root[i]);
	printf("\n%d\n",n-root[0]);
	for (i=1;i<=n;i++)
	for (j=0,sz=e[i].size();j<sz;j++) printf("%d %d\n",i,e[i][j]);
	return 0;
}