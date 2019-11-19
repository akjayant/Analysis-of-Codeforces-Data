#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
#define int long long
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}
const int MAXN=100001;
int col[4][MAXN],n;
struct node{
	int u,v,nex;
}x[MAXN<<1];
int M[MAXN],A[MAXN],cnt,head[MAXN],d[MAXN];
void add(int u,int v){
	x[cnt].u=u,x[cnt].v=v,x[cnt].nex=head[u],head[u]=cnt++;
}
void dfs(int u,int fath,int H){
	A[H]=u;M[u]=H;
	for(int i=head[u];i!=-1;i=x[i].nex){
		if(x[i].v==fath) continue;
		dfs(x[i].v,u,H+1);
	}return;
}
int f[MAXN][4][4][4],Minn,INF=LLONG_MAX,Sta[MAXN];
signed main(){
//	freopen("3.in","r",stdin);
	memset(head,-1,sizeof(head));
	n=read();
	for(int i=1;i<=3;i++) for(int j=1;j<=n;j++) col[i][j]=read();
	for(int i=1;i<n;i++){int u=read(),v=read();add(u,v),add(v,u);d[u]++,d[v]++;}
	int d1=0,d2=0;
	for(int i=1;i<=n;i++) {if(d[i]==1) d1++;if(d[i]==2) d2++; }
	if((d1!=2)||(d1+d2)!=n){printf("-1\n");return 0;}
	int rt;for(int i=1;i<=n;i++) if(d[i]==1) rt=i;
	dfs(rt,0,1);
	memset(f,127/3,sizeof(f));
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j) continue;
			for(int k=1;k<=3;k++){
				if(i==k||j==k) continue;
				f[3][i][j][k]=col[i][A[1]]+col[j][A[2]]+col[k][A[3]];
			}
		}
	}for(int i=4;i<=n;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				for(int p=1;p<=3;p++){
					if(j==k||j==p||k==p) continue;
					int G=6-j-k;
					f[i][j][k][p]=f[i-1][G][j][k]+col[p][A[i]];
				}
			}
		}
	}
	int Minn=INF;
	int s1,s2,s3;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++){
				if(i==j||i==k||j==k) continue;
				if(f[n][i][j][k]<Minn){s1=i,s2=j,s3=k;Minn=f[n][i][j][k];}
			}
	printf("%lld\n",Minn);
	Sta[n-2]=s1,Sta[n-1]=s2,Sta[n]=s3;
	for(int i=n-3;i>=1;i--){
		int G=6-Sta[i+1]-Sta[i+2];
		Sta[i]=G;
	}
	for(int i=1;i<=n;i++) printf("%lld ",Sta[M[i]]);printf("\n");
	return 0;
}
