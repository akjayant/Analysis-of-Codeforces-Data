//Code by : Y-k-y
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define int long long
const int N=100010;
using namespace std;
inline int rnd(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
inline void wr(int x){
	if(x<0){putchar('-');x=-x;}if(x>9) wr(x/10);putchar(x%10+'0');
}
const int mod=1e9+7;
int n,m,ans;
int a[1005][1005];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
inline int nnx(int x,int y){
	if(y==m){
		return x+1;
	}
	else return x;
}
//inline int nny(int x,int y){
//	if(y==m)return 1;
//	else return y+1;
//}
//inline int chk(){
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			int num=0;
//			for(int k=0;k<4;k++){
//				int nx=i+dx[k],ny=j+dy[k];
//				if(a[nx][ny]==a[i][j])num++;
//			}
//			if(num>2)return 0;
//		}
//	}
//	return 1;
//}
//inline void dfs(int x,int y){
//	if(x>n){
//		if(chk())ans++;
//		return;
//	}
//	a[x][y]=0;
//	int nx=nnx(x,y),ny=nny(x,y);
//	dfs(nx,ny);
//	a[x][y]=1;
//	dfs(nx,ny);
//}
int fac[N];
signed main(){
	cin>>n>>m;
//	memset(a,-1,sizeof(a));
//	for(n=1;n<=10;n++){
//		for(m=1;m<=5;m++){
//			ans=0;dfs(1,1);
//			
//			cout<<ans<<' ';
//		}
//		cout<<endl;
//	}
	fac[1]=fac[2]=1;
	for(int i=3;i<=100005;i++){
		fac[i]=(fac[i-1]+fac[i-2])%mod;
	}
	ans=(fac[n+1]+fac[m+1]%mod-1ll)%mod*2%mod;
	wr(ans);
	return 0;
}

