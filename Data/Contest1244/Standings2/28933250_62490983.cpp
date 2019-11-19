#include<bits/stdc++.h>
using namespace std;
//bool cur1;
#define M 100005
int n,i,j,c[3][M],x,y,z,h[M],nx[M<<1],r[M<<1],tot,cnt[M],son[M],rt,ans[M];
long long dp[M][3][3],sum;
void add(int x,int y) {
	r[++tot]=y,nx[tot]=h[x],h[x]=tot;
}
void dfs(int x,int f) {
	for(int i=h[x]; i; i=nx[i])
		if(r[i]!=f) {
			son[x]=r[i];
			if(cnt[r[i]]==1) {
				dp[x][0][1]=c[0][x]+c[1][r[i]];
				dp[x][0][2]=c[0][x]+c[2][r[i]];
				dp[x][1][0]=c[1][x]+c[0][r[i]];
				dp[x][1][2]=c[1][x]+c[2][r[i]];
				dp[x][2][0]=c[2][x]+c[0][r[i]];
				dp[x][2][1]=c[2][x]+c[1][r[i]];
			} else {
				dfs(r[i],x);
				dp[x][0][1]=c[0][x]+dp[r[i]][1][2];
				dp[x][0][2]=c[0][x]+dp[r[i]][2][1];
				dp[x][1][0]=c[1][x]+dp[r[i]][0][2];
				dp[x][1][2]=c[1][x]+dp[r[i]][2][0];
				dp[x][2][0]=c[2][x]+dp[r[i]][0][1];
				dp[x][2][1]=c[2][x]+dp[r[i]][1][0];
			}
		}
}
//bool cur2;
int main() {
//	printf("%.lf\n",((&cur2)-(&cur1))/1024.0/1024);
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&c[0][i]);
	for(i=1; i<=n; i++)scanf("%d",&c[1][i]);
	for(i=1; i<=n; i++)scanf("%d",&c[2][i]);
	for(i=1; i<n; i++)scanf("%d%d",&x,&y),add(x,y),add(y,x),cnt[x]++,cnt[y]++;
	for(i=1; i<=n; i++)
		if(cnt[i]>2) {
			printf("-1\n");
			return 0;
		} else if(cnt[i]==1)rt=i;
	dfs(rt,0),x=0,y=1,sum=dp[rt][0][1];
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			if(i!=j&&dp[rt][i][j]<sum)sum=dp[rt][i][j],x=i,y=j;
	printf("%I64d\n",sum),ans[rt]=x,z=son[rt];
	while(cnt[z]>1) {
		ans[z]=y;
		for(i=0; i<3; i++)if(i!=x&&i!=y)break;
		x=y,y=i,z=son[z];
	}
	ans[z]=y;
	for(i=1; i<=n; i++) {
		printf("%d",ans[i]+1);
		if(i<n)printf(" ");
		else printf("\n");
	}
	return 0;
}