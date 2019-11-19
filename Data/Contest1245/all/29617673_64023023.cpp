#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=2005;
int n,X[MN],Y[MN];
ll val[MN][MN],low[MN],c[MN],k[MN];
int vis[MN];
bool used[MN];
int main(){
	scanf("%d",&n);
	for(reg int i=1;i<=n;i++)scanf("%d%d",X+i,Y+i);
	for(reg int i=1;i<=n;i++)scanf("%lld",c+i);
	for(reg int i=1;i<=n;i++)scanf("%lld",k+i);
	for(reg int i=1;i<=n;i++)
		for(reg int j=i+1;j<=n;j++)
			val[i][j]=val[j][i]=(k[i]+k[j])*(abs(X[i]-X[j])+abs(Y[i]-Y[j]));
	for(reg int i=1;i<=n;i++)low[i]=c[i];
	reg ll Ans=0;
	for(reg int t=1;t<=n;t++){
		reg int pos=-1;reg ll val=0x3f3f3f3f3f3f3f3f;
		for(reg int i=1;i<=n;i++)
			if(!used[i]&&low[i]<val)val=low[i],pos=i;
		Ans+=val;used[pos]=1;
		for(reg int i=1;i<=n;i++)
			if(!used[i]&&low[i]>::val[pos][i])
				low[i]=::val[pos][i],vis[i]=pos;
	}
	reg int t1=0,t2=0;
	for(reg int i=1;i<=n;i++)
		if(vis[i])t2++;else t1++;
	printf("%lld\n%d\n",Ans,t1);
	for(reg int i=1;i<=n;i++)
		if(!vis[i])printf("%d ",i);
	puts("");printf("%d\n",t2);
	for(reg int i=1;i<=n;i++)
		if(vis[i])printf("%d %d\n",vis[i],i);
	return 0;
}