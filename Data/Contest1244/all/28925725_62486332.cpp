#include<cstdio>
#define M 100005
int val[M][5];
int Deg[M];
int Ans[M],Col[M];
int fa[M];
struct E{
	int to,nx;
}edge[M<<1];
int tot,head[M];
void Addedge(int a,int b){
	edge[++tot].to=b;
	edge[tot].nx=head[a];
	head[a]=tot;
}
int A[M],sz;
void dfs(int now){
	A[++sz]=now;
	for(int i=head[now];i;i=edge[i].nx){
		int nxt=edge[i].to;
		if(fa[now]==nxt)continue;
		fa[nxt]=now;
		dfs(nxt);
	}
}
int n;
void Solve(){
	long long ans=1e18;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j)continue;
			Col[A[1]]=i;Col[A[2]]=j;
			long long res=val[A[1]][i]+val[A[2]][j];
			for(int k=3;k<=n;k++){
				for(int q=1;q<=3;q++){
					if(q==Col[A[k-1]]||q==Col[A[k-2]])continue;
					res+=val[A[k]][q];
					Col[A[k]]=q;
					break;
				}
			}
			if(res<ans){
				ans=res;
				for(int k=1;k<=n;k++)Ans[k]=Col[k];
			}
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)printf("%d ",Ans[i]);puts("");
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&val[i][1]);
	for(int i=1;i<=n;i++)scanf("%d",&val[i][2]);
	for(int i=1;i<=n;i++)scanf("%d",&val[i][3]);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		Addedge(a,b);
		Addedge(b,a);
		Deg[a]++;Deg[b]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(Deg[i]>2){puts("-1");return 0;}
		cnt+=Deg[i]==1;
	}
	if(cnt!=2){puts("-1");return 0;}
	for(int i=1;i<=n;i++){
		if(Deg[i]==1){
			dfs(i);
			Solve();
			break;
		}
	}
	return 0;
}