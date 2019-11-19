#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
	int next,to;
}w[200001];
ll f[100001][3][3],ans;
int c[3][100001],head[100001],cnt,n,pre[100001];
int nxt[100001],du[100001],rt,las[100001][3][3];
int res[100001];
inline void add(int x,int y){
	w[++cnt].next=head[x];
	w[cnt].to=y; head[x]=cnt;
}
void dfs(int x,int fa){
	for (int i=head[x]; i; i=w[i].next){
		if (w[i].to==fa) continue;
		nxt[x]=w[i].to; pre[w[i].to]=x;
		dfs(w[i].to,x);
	}
}
int main(){
	int x,y;
	scanf("%d",&n);
	for (int i=0; i<3; i++)
		for (int j=1; j<=n; j++)
			scanf("%d",&c[i][j]);
	for (int i=1; i<n; i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		du[x]++,du[y]++;
	}
	int flag=0;
	for (int i=1; i<=n; i++){
		if (du[i]>2){flag=1; break;}
		if (du[i]==1) rt=i;
	}
	if (flag){
		puts("-1");
		return 0;
	}
	dfs(rt,0);
	memset(f,10,sizeof(f));
	x=rt,y=nxt[rt]; ans=f[0][0][0];
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++){
			if (i==j) continue;
			f[2][i][j]=c[i][x]+c[j][y];
		}
	for (int i=nxt[y],j=3; i&&j<=n; i=nxt[i],j++){
		for (int k=0; k<3; k++){
			for (int p=0; p<3; p++){
				if (k==p) continue;
				for (int u=0; u<3; u++){
					if (u==k||u==p) continue;
					f[j][k][p]=f[j-1][u][k]+c[p][i];
					las[j][k][p]=u;
				}
			}
		}
		if (j==n) x=i;
	}
	int u,v,p;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++){
			if (i==j) continue;
			if (f[n][i][j]<ans){
				ans=f[n][i][j];
				u=i,v=j;
			}
		}
	cout<<ans<<endl;
	res[x]=v; //res[pre[x]]=u;
	int num=n;
	while (x&&num>1){
		x=pre[x];
		p=las[num][u][v];
		res[x]=u; num--;
		v=u,u=p;
	}
	for (int i=1; i<=n; i++) printf("%d ",res[i]+1);
	return 0;
}
