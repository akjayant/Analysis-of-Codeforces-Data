#include<bits/stdc++.h>
#define LL long long
#define N 1000005
#define Ms(a,b) memset(a,b,sizeof a)
#define db(x) cerr<<#x<<"="<<x<<endl;
#define db2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define db3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
using namespace std;
struct edge {
	int to,nxt;
} e[N<<1];
int n,c[3][N],head[N],ind[N];
LL ans=2e18,now;
int col[N],tmp[N];
void dfs(int x,int l,int a,int b) {
	tmp[x]=3-a-b;
	now+=c[3-a-b][x];
	for(int i=head[x]; i; i=e[i].nxt) {
		int to=e[i].to;
		if(to!=l)dfs(to,x,tmp[x],a);
	}
}
void link(int s,int t,int n) {
	e[n]=(edge)<%t,head[s]%>;
	head[s]=n,ind[t]++;
}
int main() {
	scanf("%d",&n);
	for(int j=0; j<3; j++)for(int i=1; i<=n; i++)scanf("%d",&c[j][i]);
	for(int i=1; i<n; i++) {
		int s,t;
		scanf("%d%d",&s,&t);
		link(s,t,i<<1);
		link(t,s,i<<1|1);
	}
	int ct=0,s,g,h;
	for(int i=1; i<=n; i++)
		if(ind[i]==1)ct++,s=i;
		else if(ind[i]!=2) {
			puts("-1");
			return 0;
		}
	if(ct!=2) {
		puts("-1");
		return 0;
	}
	for(int i=head[s]; i; i=e[i].nxt)g=e[i].to;
	for(int i=head[g]; i; i=e[i].nxt)if(e[i].to!=s)h=e[i].to;
	for(int i=0; i<=2; i++)
		for(int j=0; j<=2; j++) {
			if(i==j)continue;
			now=c[i][s]+c[j][g];
			dfs(h,g,j,i);
			if(now<ans) {
				memcpy(col,tmp,sizeof tmp);
				ans=now,col[s]=i,col[g]=j;
			}
		}
	printf("%I64d\n",ans);
	for(int i=1; i<=n; i++)printf("%d ",col[i]+1);
	return 0;
}

