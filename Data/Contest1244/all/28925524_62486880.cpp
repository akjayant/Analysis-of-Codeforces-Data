#include<bits/stdc++.h>
#define M 100005
#define ll long long
using namespace std;
int n,a[3][M],to[M<<1],pr[M<<1],la[M],tot,In[M],id=0,fa[M][9],num[M],b[6][3]= {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}},Ans[M];
void add(int x,int y) {
	to[++tot]=y,pr[tot]=la[x],la[x]=tot;
}
void dfs(int x,int f) {
	num[++id]=x;
	for(int i=la[x]; i; i=pr[i]) {
		int y=to[i];
		if(y==f)continue;
		dfs(y,x);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&a[0][i]);
	for(int i=1; i<=n; i++)scanf("%d",&a[1][i]);
	for(int i=1; i<=n; i++)scanf("%d",&a[2][i]);
	for(int i=1; i<n; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x),In[x]++,In[y]++;
	}
	bool ok=1;
	for(int i=1; i<=n; i++)if(In[i]>2)ok=0;
	if(!ok)printf("-1\n");
	else {
		int rt=1;
		for(int i=1; i<=n; i++)if(In[i]==1)rt=i;
		dfs(rt,0);
		int col;
		ll ans=1e18;
		for(int k=0; k<6; k++) {
			int now=0;
			ll sum=0;
			for(int i=1; i<=n; i++)sum+=a[b[k][now]][num[i]],now=(now+1)%3;
			if(sum<ans)ans=sum,col=k;
		}
		printf("%I64d\n",ans);
		int now=0;
		for(int i=1; i<=n; i++)Ans[num[i]]=b[col][now]+1,now=(now+1)%3;
		for(int i=1; i<=n; i++)printf("%d ",Ans[i]);
		puts("");
	}
	return 0;
}