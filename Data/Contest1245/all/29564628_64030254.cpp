#include<bits/stdc++.h>
#define maxn 20
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;
int mp[maxn][maxn],t[maxn][maxn],nx[maxn*maxn],ny[maxn*maxn],tot;
int ed[maxn*maxn]; double dp[maxn*maxn];

inline int read(){
    int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

inline void init(int n){
	for(int i=n;i>=1;i--){
		if(!(i&1))
			for(int j=1;j<=n;j++) t[i][j]=++tot,nx[tot]=i,ny[tot]=j;
		else
			for(int j=n;j>=1;j--) t[i][j]=++tot,nx[tot]=i,ny[tot]=j;
	}
}

int main(){
	init(10);
	int n=10;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]=read(),ed[t[i][j]]=t[i-mp[i][j]][j];
	dp[n*n]=0;
	for(int i=n*n-1;i>=1;i--){
		double tp=1.0;
		if(i>94){
			tp=6.0/(100.0-(double)i);
			dp[i]+=(6.0-(double)(n*n-i))/6.0;
		}
		for(int j=1;j<=min(n*n-i,6);j++)
			dp[i]+=((double)min(dp[i+j],dp[ed[i+j]])+1.0)/6.0;
		dp[i]*=tp;
	}
	printf("%.10lf\n",dp[1]);
	return 0;
}
