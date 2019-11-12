#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
#define sqr(x) ((x)*(x))
#define pb push_back
const int N=1000002,M=998244353;
int pw(int x,int y){int z=1;for(;y;y>>=1,x=1ll*x*x%M)if(y&1)z=1ll*z*x%M;return z;}
void inc(int &x,int y){x+=y;if(x>=M)x-=M;}void dec(int &x,int y){x-=y;if(x<0)x+=M;}
void Max(int &x,int y){if(y>x)x=y;}void Min(int &x,int y){if(y<x)x=y;}
//struct node{int to,ne;}e[];
//void add(int x,int y){e[++tot]=(node){y,h[x]},h[x]=tot;}
int n,i,j,a[302][302],now;
signed main(){
	scanf("%d",&n);
	for (j=1;j<=n;j++){
		if (j&1)
			for (i=1;i<=n;i++) a[i][j]=++now;
		else for (i=n;i;i--) a[i][j]=++now;
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++) printf("%d%c",a[i][j],j==n?'\n':' ');
}