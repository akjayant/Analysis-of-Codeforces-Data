#include<bits/stdc++.h>
using namespace std;
#define int long long
//typedef long long ll;
#define sqr(x) ((x)*(x))
#define pb push_back
const int N=200002,M=998244353;
int pw(int x,int y){int z=1;for(;y;y>>=1,x=1ll*x*x%M)if(y&1)z=1ll*z*x%M;return z;}
void inc(int &x,int y){x+=y;if(x>=M)x-=M;}void dec(int &x,int y){x-=y;if(x<0)x+=M;}
void Max(int &x,int y){if(y>x)x=y;}void Min(int &x,int y){if(y<x)x=y;}
int p[N],c[N],a[4][N],i,j,n,sum,ans,p1,p2,p3,x,y,c1,c2,k,t,xx;
vector<int>v[N];
signed main(){
	scanf("%lld",&n);
	for (j=1;j<=3;j++)
	for (i=1;i<=n;i++) scanf("%lld",&a[j][i]);
	for (i=1;i<n;i++) scanf("%lld%lld",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for (i=1;i<=n;i++){
		if (v[i].size()==1) c1++,x=i;
		if (v[i].size()==2) c2++;
	}
	if (c1!=2 || c1+c2!=n) return puts("-1"),0;
	ans=1e18;
	xx=x;
	for (i=1;i<=3;i++)
		for (j=1;j<=3;j++) if (i!=j){
			x=xx;
			y=v[x][0],sum=a[i][x]+a[j][y];
			p1=i,p2=j,c[x]=i,c[y]=j;
			for (k=3;k<=n;k++){
				t=(x==v[y][0]?v[y][1]:v[y][0]);
				p3=6-p1-p2;
				sum+=a[p3][t];
				x=y,y=t;
				p1=p2,p2=p3,c[t]=p3;
			}
			if (sum<ans){
				ans=sum;
				memcpy(p,c,sizeof(c));
			}
		}
	if (ans==1e18) return puts("-1"),0;
	printf("%lld\n",ans);
	for (i=1;i<=n;i++) printf("%lld ",p[i]);
}