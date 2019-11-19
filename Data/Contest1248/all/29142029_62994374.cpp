#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define ll long long
#define N 110000
#define mod 1000000007
using namespace std;
int n,m,f[N],s[N];
//int n,m,x[10],y[10],a[100][100],ans; 
//inline int qpow(int n,ll w){
//	int s[110],num=0;
//	if(w==0) return 1;
//	while(w>0) s[++num]=w%2,w/=2;
//	int t=n,ans=1;
//	if(s[1]) ans=n;
//	for(int i=2;i<=num;++i){
//		t=1ll*t*t%mod;
//		if(s[i]) ans=1ll*ans*t%mod;
//	}
//	return ans;
//}
//inline bool check(int n,int m){
//	for(int i=1;i<=n;++i)
//	for(int j=1;j<=m;++j){
//		int an=0;
//		for(int k=1;k<=4;++k){
//			int x1=i+x[k],y1=j+y[k];
//			if(0<x1 and x1<=n and 0<y1 and y1<=m){
//				if(a[x1][y1]==a[i][j]) ++an;
//			}
//		}
//		if(an>1) return false;
//	}
//	return true;
//}
//void work(int i,int j,int n,int m){
//	if(j>m) ++i,j=1;
//	if(i>n){
//		if(check(n,m)) ++ans;
//		return ;
//	}
//	a[i][j]=1;
//	work(i,j+1,n,m);
//	a[i][j]=0;
//	work(i,j+1,n,m);
//}
//inline void baoli(){
//	for(int i=1;i<=n;++i)
//	for(int j=1;j<=m;++j){
//		ans=0;work(1,1,i,j);
//		printf("%d %d:%d\n",i,j,ans);
//	}
//} 
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	f[1]=1;
	for(int i=2;i<=max(n,m);++i) f[i]=(f[i-1]+f[i-2])%mod;
	s[1]=1;
	for(int i=2;i<=max(n,m);++i) s[i]=(s[i-1]+f[i])%mod;
	int yu=(1ll*(2+1ll*s[n-1]*2%mod)%mod+1ll*2*s[m-1]%mod)%mod;
	printf("%d\n",yu);
//	printf("%d\n",qpow(n,m));
	return 0;
}
