#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
const int P=1e9+7;
int ans,n,m,fib[N],pre[N];
// int dir_x[]={0,1,0,-1};
// int dir_y[]={1,0,-1,0};
// bool check(){
// 	for (int i=1;i<=n;++i){
// 		for (int j=1;j<=m;++j){
// 			int cnt=0;
// 			for (int k=0;k<4;++k){
// 				int tx=dir_x[k]+i;
// 				int ty=dir_y[k]+j;
// 				if (tx<1 || tx>n || ty<1 || ty>m) continue;
// 				cnt+=ret[tx][ty]==ret[i][j];
// 			}
// 			if (cnt>1) return false;
// 		}
// 	}
// 	return true;
// }
// void dfs(int x,int y){
// 	if (x==n && y==m){
// 		if (check()) ans++;
// 		return;
// 	}
// 	if (y==m){
// 		x+=1,y=1;
// 	}
// 	else y+=1;
// 	ret[x][y]=0;
// 	dfs(x,y);
// 	ret[x][y]=1;
// 	dfs(x,y);
// 	// if (x==1){
// 	// 	ret[x][y]=0;
// 	// 	dfs(x,y);
// 	// 	ret[x][y]=1;
// 	// 	dfs(x,y);
// 	// }
// 	// else{

// 	// }
// }
int main(){
	// for (n=1;n<=5;++n){
	// 	for (m=1;m<=5;++m){
	// 		ans=0;
	// 		ret[1][1]=0;
	// 		dfs(1,1);
	// 		cout<<n<<" "<<m<<" "<<ans<<endl;
	// 	}
	// }
	read(n),read(m);
	pre[1]=1,pre[2]=1;
	for (int i=3;i<=m-1;++i) pre[i]=(pre[i-1]+pre[i-2])%P;
	for (int i=2;i<=m-1;++i) pre[i]=(pre[i]+pre[i-1])%P;
	fib[1]=1,fib[2]=2;
	for (int i=3;i<=n;++i){
		fib[i]=(fib[i-1]+fib[i-2])%P;
	}
	// cout<<fib[n]<<" "<<fib[m-1]<<endl;
	printf("%d\n",(fib[n]+pre[m-1])%P*2LL%P);
	return 0;
}